// Local
#include "Server.h"

Server::Server(QObject *parent)
  : QObject(parent)
  , m_socket(new QTcpSocket(this))
{

}
