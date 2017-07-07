#ifndef SERVER_H
#define SERVER_H

// Qt
#include <QObject>
#include <QTcpSocket>

class Server : public QObject
{
  Q_OBJECT

  public:
    explicit Server(QObject *parent = 0);

    bool start();

  signals:

  public slots:

  private:
    QTcpSocket *m_socket;
};

#endif // SERVER_H
