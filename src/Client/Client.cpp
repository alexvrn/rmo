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

Client::Client(QObject *parent)
  : QObject(parent)
  , m_socket(new QLocalSocket(this))
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
  //m_socket->write("");
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


void Client::readyRead()
{
  qDebug() << "data localserver" << m_socket->readAll();
  emit data(CommandType::CMD_PGAS_Data);
}


void Client::disconnected()
{

}


void Client::realtimeDataSlot()
{  
  emit data(CommandType::CMD_PGAS_Data);
}

