#ifndef CLIENT_H
#define CLIENT_H

// Qt
#include <QObject>
#include <QLocalSocket>
//#include <QTimer>

// Local
#include "AuthDialog.h"
#include "ResponseReceiver.h"
#include <commandType.h>

class Client : public QObject
{
  Q_OBJECT

  public:
    enum WaitState
    {
      WaitingId,
      WaitingMessageType,
      WaitingLength,
      WaitingMessage
    };

    static Client& instance(QObject *parent = Q_NULLPTR);
    ~Client();

    bool connectToServer(const QString& host);

    // Отправка команды(или запроса) локальному серверу
    void sendCommand(CommandType::Command cmd, const QVariantMap& value = QVariantMap());

  private:
    Client(QObject *parent = Q_NULLPTR);
    Client& operator=(const Client&);

  public slots:
    void logout();

  signals:
    void data(CommandType::Command cmd, const QByteArray& value = QByteArray());
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
    void init();
    QVariantMap parseData(CommandType::Command cmd, const QByteArray& data) const;

    AuthDialog m_authDialog;

    //! TODO: надо ли это
    ResponseReceiver* m_responseReceiver;

    QLocalSocket* m_socket;

    // FAKE
    //QTimer m_dataTimer;

    QString m_host;

    WaitState m_waitState;
    CommandType::Command m_command;
    quint32 m_messageLength;
};

#endif // CLIENT_H
