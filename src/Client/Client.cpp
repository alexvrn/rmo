// Local
#include "Client.h"

// Qt
#include <QApplication>
#include <QTime>
#include <QTimer>
#include <QLocalSocket>
#include <QEventLoop>

// MATH
#include <QtMath>

const quint16 idMessage = 0xCAFE;

Client::Client(QObject *parent)
  : QObject(parent)
  , m_socket(new QLocalSocket(this))
  , m_waitState(WaitingId)
  , m_messageType(-1)
  , m_messageLength(0)
{
  connect(&m_authDialog, &AuthDialog::authentication, this, &Client::authAccess);

  connect(m_socket, SIGNAL(stateChanged(QLocalSocket::LocalSocketState)), SLOT(stateChanged(QLocalSocket::LocalSocketState)));
  connect(m_socket, SIGNAL(readyRead()), SLOT(readyRead()));

  //! FAKE
  // setup a timer that repeatedly calls MainWindow::realtimeDataSlot:
  //connect(&m_dataTimer, SIGNAL(timeout()), this, SLOT(realtimeDataSlot()));
  //m_dataTimer.start(500); // Interval 0 means to refresh as fast as possible
}


Client& Client::instance(QObject *parent)
{
  static Client clientInstance(parent);
  return clientInstance;
}


Client::~Client()
{
}


void Client::sendCommand(CommandType::Command cmd, const QVariantMap& value)
{
  switch (cmd)
  {
    case CommandType::CMD_RequestData_DateTime:
      qDebug() << value["datetime"];
      break;
    default:
      qWarning() << "Неизвестный тип команды" << cmd;
  }

  QByteArray data; //

  QByteArray package;
  QDataStream out(&package, QIODevice::WriteOnly);
  out.setVersion(QDataStream::Qt_5_9);
  // подготовка данных для записи
  out << quint16(idMessage);
  out << quint16(cmd);
  out << quint32(data.length());
  if (data.length())
    out.writeRawData(data.data(), data.length());

  m_socket->write(package);
  if (!m_socket->waitForBytesWritten())
    qWarning() << tr("Ошибка отправки данных!"); //! TODO: что тут делать?
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
  m_messageType = -1;
  m_messageLength = 0;
  m_waitState = WaitingId;
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
    dataStream >> m_messageType;

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
    qDebug() << tr("Тип") << m_messageType << message.length() << message;
    init();
  }
}


void Client::disconnected()
{

}


void Client::realtimeDataSlot()
{  
  emit data(CommandType::CMD_PGAS_Data);
}

