// Local
#include "Client.h"

// Qt
#include <QApplication>
#include <QTimer>

Client::Client(QObject *parent)
  : QObject(parent)
  , m_socket(new QTcpSocket(this))
{
  connect(m_socket, &QTcpSocket::readyRead, this, &Client::readyRead);
  connect(m_socket, &QTcpSocket::disconnected, this, &Client::disconnected);
  connect(m_socket, &QTcpSocket::stateChanged, this, &Client::stateChanged);

  connect(&m_authDialog, &AuthDialog::authentication, this, &Client::authAccess);

  // Через секунду запрашиваем авторизацию
  QTimer::singleShot(1000, this, SLOT(logout()));
}


Client::~Client()
{
  m_socket->disconnectFromHost();
}


bool Client::connectToHost(const QString& host, int port)
{
  qDebug() << qPrintable(QString(tr("Подключение к серверу %1:%2")).arg(host).arg(port));
  m_socket->connectToHost(host, port);

  return true;
}


void Client::logout()
{
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

}


void Client::disconnected()
{

}


void Client::stateChanged(QAbstractSocket::SocketState socketState)
{
  if (socketState == QAbstractSocket::ConnectedState)
  {

  }
  else
  {
    qDebug() << socketState;
  }
}
