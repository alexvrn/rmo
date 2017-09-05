#ifndef CLIENT_H
#define CLIENT_H

// Qt
#include <QObject>
#include <QTcpSocket>

// Local
#include "AuthDialog.h"
#include "ResponseReceiver.h"

class Client : public QObject
{
  Q_OBJECT

  public:
    explicit Client(QObject *parent = 0);
    ~Client();

    bool connectToHost(const QString& host, int port);

  public slots:
    void logout();

  signals:
    void data(const QByteArray& data);
    void authentication();
    void messageReceived(const QVariantMap& result);

  private slots:
    void readyRead();
    void disconnected();
    void stateChanged(QAbstractSocket::SocketState socketState);

    void authAccess(const QVariantMap& userData);

  private:
    QTcpSocket *m_socket;
    AuthDialog m_authDialog;

    ResponseReceiver* m_responseReceiver;
};

#endif // CLIENT_H
