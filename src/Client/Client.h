#ifndef CLIENT_H
#define CLIENT_H

// Qt
#include <QObject>
#include <QTimer>
class QNetworkAccessManager;

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
    void data(double key, double value);
    void authentication();
    void messageReceived(const QVariantMap& result);

  private slots:
    void readyRead();
    void disconnected();

    void authAccess(const QVariantMap& userData);

    // FAKE
    void realtimeDataSlot();

  private:
    AuthDialog m_authDialog;

    //! TODO: надо ли это
    ResponseReceiver* m_responseReceiver;

    QNetworkAccessManager* m_networkManager;

    // FAKE
    QTimer m_dataTimer;
};

#endif // CLIENT_H
