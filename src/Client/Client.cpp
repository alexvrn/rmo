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
  m_authDialog.exec();
  if (QDialog::Accepted == m_authDialog.result())
  {
    emit authentication();
  }
  else
  {
    qApp->quit();
  }
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
