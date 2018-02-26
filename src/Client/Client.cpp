// Local
#include "Client.h"
#include "ClientWorker.h"

// Qt
#include <QApplication>
#include <QTimer>
#include <QThread>
#include <QLocalSocket>
#include <QEventLoop>
#include <QSettings>


const quint16 idMessage = 0xCAFE;

Client::Client(QObject *parent)
  : QObject(parent)
  , m_clientWorker(new ClientWorker)
  , m_thread(new QThread(this))
  , m_socket(new QLocalSocket(this))
  , m_waitState(WaitingId)
  , m_messageLength(0)
{
  qRegisterMetaType<CommandType::Command>();

  m_thread->start();
  m_clientWorker->moveToThread(m_thread);
  connect(m_clientWorker, &ClientWorker::newData, this, &Client::getNewData, Qt::QueuedConnection);
  connect(m_clientWorker, &ClientWorker::pgasData, this, &Client::getPgasData, Qt::QueuedConnection);

  connect(&m_authDialog, &AuthDialog::authentication, this, &Client::authAccess);

  connect(m_socket, SIGNAL(stateChanged(QLocalSocket::LocalSocketState)), SLOT(stateChanged(QLocalSocket::LocalSocketState)));
  connect(m_socket, SIGNAL(readyRead()), SLOT(readyRead()));
}


Client& Client::instance(QObject *parent)
{
  static Client clientInstance(parent);
  return clientInstance;
}


Client::~Client()
{
  m_thread->quit();
  if (!m_thread->wait(5000))
    m_thread->terminate();

  delete m_clientWorker;
}


void Client::sendCommand(CommandType::Command cmd, const QVariantMap& value)
{
  QByteArray data;

  switch (cmd)
  {
    case CommandType::CMD_RequestData_DateTime:
    {
      //! TODO: делать это тут или отдавать службе?
      //const qint64 secs = value["datetime"].toDateTime().toSecsSinceEpoch();
      //data = QByteArray::number(secs);
      break;
    }
    default:
      qWarning() << "Неизвестный тип команды" << cmd;
  }

  QByteArray package;
  QDataStream out(&package, QIODevice::WriteOnly);
  out.setVersion(QDataStream::Qt_5_9);
  // подготовка данных для записи
  out << quint16(idMessage);
  out << quint16(cmd);
  out << quint32(data.length());

  if (data.length())
  {
    if (-1 == out.writeRawData(data.data(), data.length()))
      qWarning() << tr("Ошибка отправки данных");
  }

  m_socket->write(package);
  if (!m_socket->waitForBytesWritten())
    qWarning() << tr("Ошибка отправки данных!"); //! TODO: что тут делать?
}


PgasData Client::pgasData() const
{
  return m_pgasData;
}


//! Получение данных из файла для времени dateTime(с точностью до минуты)
PgasData Client::parseFileForDateTime(const QDateTime& dateTime) const
{
  PgasData data;
  QMetaObject::invokeMethod(m_clientWorker, "parseFileForDateTime", Qt::BlockingQueuedConnection,
                            Q_RETURN_ARG(PgasData, data),
                            Q_ARG(QDateTime, dateTime));
  return data;
}


bool Client::connectToServer(const QString& host)
{
  qDebug() << qPrintable(QString(tr("Подключение к серверу %1")).arg(host));

  m_host = host;

  QEventLoop loop;
  connect(m_socket, &QLocalSocket::stateChanged, &loop, &QEventLoop::quit);
  QTimer::singleShot(500, this, SLOT(connectLater()));
  loop.exec();

  return m_socket->state() == QLocalSocket::ConnectedState;
}


void Client::connectLater()
{
  m_socket->connectToServer(m_host);
}


void Client::stateChanged(QLocalSocket::LocalSocketState state)
{
  switch (state)
  {
    case QLocalSocket::ConnectedState:
      qDebug() << tr("Подключение к локальному серверу сбора данных");

      // Через секунду запрашиваем авторизацию
      QTimer::singleShot(1000, this, SLOT(logout()));
      break;
    case QLocalSocket::UnconnectedState:
      qWarning() << tr("Не удаётся подключиться к локальному серверу");
      //! TODO: разобраться с подключением к серверу
      //qApp->quit();
      break;
    default: {}
  }
}


void Client::logout()
{
  if (m_authDialog.isVisible())
    return;

  if (QDialog::Rejected == m_authDialog.exec())
  {
    // Выходим из приложения, если пользователь отказаться авторизоваться
    qApp->quit();
  }
}


void Client::authAccess(const QVariantMap& userData)
{
  qDebug() << userData;
  m_authDialog.setResult(QDialog::Accepted);
  m_authDialog.hide();
  emit authentication();
  //! TODO: получение результата по сокету
//  QByteArray request = Proto::encode("request", method, data);

//  ResponseReceiver receiver(method);
//  connect(this, SIGNAL(messageReceived(QVariantMap)), &receiver, SLOT(messageReceived(QVariantMap)));
//  m_socket->write("");
//  receiver.run();

  //if (receiver.responseData())
  //{}
}


void Client::init()
{
  m_messageLength = 0;
  m_waitState = WaitingId;
}


void Client::calculateData(const QByteArray& data, CommandType::Command cmd)
{
  QMetaObject::invokeMethod(m_clientWorker, "calculateData", Qt::QueuedConnection,
                              Q_ARG(QByteArray, data),
                              Q_ARG(CommandType::Command, cmd));
}


void Client::readyRead()
{
  // TDOD: не знаю, нужна ли тут эта проверка
  if (!m_socket)
    return;

  if (m_waitState == WaitingId)
  {
    // ждем ID-сообщения
    if (m_socket->bytesAvailable() < (qint64)sizeof(quint16))
      return;

    quint16 id;
    auto data = m_socket->read(sizeof(quint16));
    QDataStream dataStream(&data, QIODevice::ReadOnly);
    dataStream.setVersion(QDataStream::Qt_5_9);
    //! TODO: dataStream.setByteOrder(QDataStream::LittleEndian);
    dataStream >> id;
    if (id != idMessage)
    {
      init();
      qWarning() << tr("Попытка прочесть какое-то другое сообщение");
      return;
    }

    m_waitState = WaitingMessageType;
  }

  if (m_waitState == WaitingMessageType)
  {
    // ждем тип сообщения
    if (m_socket->bytesAvailable() < (qint64)sizeof(quint16))
      return;

    auto data = m_socket->read(sizeof(quint16));
    QDataStream dataStream(&data, QIODevice::ReadOnly);
    dataStream.setVersion(QDataStream::Qt_5_9);
    //! TODO: dataStream.setByteOrder(QDataStream::LittleEndian);

    quint16 command;
    dataStream >> command;
    m_command = static_cast<CommandType::Command>(command);

    m_waitState = WaitingLength;
  }

  if (m_waitState == WaitingLength)
  {
    // ждем размер сообщения
    if (m_socket->bytesAvailable() < (qint64)sizeof(quint32))
      return;

    auto data = m_socket->read(sizeof(quint32));
    QDataStream dataStream(&data, QIODevice::ReadOnly);
    dataStream.setVersion(QDataStream::Qt_5_9);
    //! TODO: dataStream.setByteOrder(QDataStream::LittleEndian);
    dataStream >> m_messageLength;

    m_waitState = WaitingMessage;
  }

  if (m_waitState == WaitingMessage)
  {
    // ждем сообщениe
    if (m_socket->bytesAvailable() < (qint64)m_messageLength)
      return;

    QByteArray message = m_socket->read(m_messageLength);
    calculateData(message, m_command);

    init();

    // Проверяем, есть ли ещё сообщения
    if (m_socket->bytesAvailable())
      readyRead();
  }
}


void Client::getNewData(const PgasData& pgasData, CommandType::Command cmd, const QVariant& value)
{
  m_pgasData = pgasData;
  emit newData(cmd, value);
}


void Client::getPgasData(const PgasData& pgasData)
{
  m_pgasData = pgasData;
}


void Client::disconnected()
{

}


void Client::realtimeDataSlot()
{
  //emit data(CommandType::CMD_PGAS_Data);
}

