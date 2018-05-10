#ifndef CLIENT_H
#define CLIENT_H

// Qt
#include <QObject>
#include <QLocalSocket>
#include <QVariantMap>
class QThread;

// Local
#include "AuthDialog.h"
#include "ResponseReceiver.h"
#include <commandType.h>
class ClientWorker;

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

    //! Отправка команды(или запроса) локальному серверу
    void sendCommand(CommandType::Command cmd, const QVariantMap& value = QVariantMap());

    //! Данные, полученные от ПГАС-ов
    PgasData pgasData() const;

    //! Получение данных из файла для времени dateTime(с точностью до минуты)
    PgasData parseFileForDateTime(const QDateTime& dateTime) const;

  private:
    Client(QObject *parent = Q_NULLPTR);
    Client& operator=(const Client&);

  public slots:
    // Вызов диалогового окна авторизации
    bool logout();

  signals:
    void newData(CommandType::Command cmd, const QVariant& value = QVariant());
    void success();
    void failure();
    void messageReceived(const QVariantMap& result);

  private slots:
    void readyRead();
    void disconnected();
    void stateChanged(QLocalSocket::LocalSocketState state);
    void connectLater();

    void authAccess(const QVariantMap& userData);

    void calculateData(const QByteArray& data, CommandType::Command cmd);

    void getNewData(const PgasData& pgasData, CommandType::Command cmd, const QVariant& value = QVariant());
    void getPgasData(const PgasData& pgasData);

    // FAKE
    void realtimeDataSlot();

  private:
    void init();

    AuthDialog m_authDialog;

    //! TODO: надо ли это
    ResponseReceiver* m_responseReceiver;

    ClientWorker* m_clientWorker;
    QThread* m_thread;

    QLocalSocket* m_socket;

    // FAKE
    //QTimer m_dataTimer;

    QString m_host;

    // Для чтения данных с сокета
    WaitState m_waitState;
    CommandType::Command m_command;
    quint32 m_messageLength;

    PgasData m_pgasData;
};

#endif // CLIENT_H
