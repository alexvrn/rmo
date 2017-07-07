#ifndef CLIENT_H
#define CLIENT_H

// Qt
#include <QObject>
#include <QTcpSocket>

class Client : public QObject
{
  Q_OBJECT

  public:
    explicit Client(QObject *parent = 0);
    ~Client();

    bool connectToHost(const QString& host, int port);

  signals:
    void data(const QByteArray& data);

  private slots:
    void readyRead();
    void disconnected();
    void stateChanged(QAbstractSocket::SocketState socketState);

  private:
    QTcpSocket *m_socket;
};

#endif // CLIENT_H
