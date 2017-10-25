#ifndef CLIENT_H
#define CLIENT_H

// Qt
#include <QObject>
#include <QTimer>
#include <QLocalSocket>

// Local
#include "AuthDialog.h"
#include "ResponseReceiver.h"

class Client : public QObject
{
  Q_OBJECT

  public:
    explicit Client(QObject *parent = 0);
    ~Client();

    bool connectToServer(const QString& host);

  public slots:
    void logout();

  signals:
    void data(double key, double value);
    void authentication();
    void messageReceived(const QVariantMap& result);

  private slots:
    void readyRead();
    void disconnected();
    void stateChanged(QLocalSocket::LocalSocketState state);
    void connectLater();

    void authAccess(const QVariantMap& userData);

    // FAKE
    void realtimeDataSlot();

  private:
    AuthDialog m_authDialog;

    //! TODO: надо ли это
    ResponseReceiver* m_responseReceiver;

    QLocalSocket* m_socket;

    // FAKE
    QTimer m_dataTimer;

    QString m_host;
};

#endif // CLIENT_H
