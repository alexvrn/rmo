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
#include "cmd.h"
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
    void sendCommand(cmd_e cmd, const QVariantMap& value = QVariantMap());

    //! Данные, полученные от ПГАС-ов
    PgasData pgasData() const;

    //! Получение данных из файла для времени dateTime(с точностью до минуты)
    //! int stationId - номер ПГАС
    PgasData parseFileForDateTime(int stationId, const QDateTime& dateTime) const;

  private:
    Client(QObject *parent = Q_NULLPTR);
    Client& operator=(const Client&);

  public slots:
    // Вызов диалогового окна авторизации
    bool logout();

  signals:
    void newData(cmd_e cmd, const QVariant& value = QVariant());
    void success();
    void failure();
    void messageReceived(const QVariantMap& result);

  private slots:
    void readyRead();
    void disconnected();
    void stateChanged(QLocalSocket::LocalSocketState state);
    void connectLater();

    void authAccess(const QVariantMap& userData);

    void calculateData(const QByteArray& data, cmd_e cmd);

    void getNewData(const PgasData& pgasData, cmd_e cmd, const QVariant& value = QVariant());
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
    cmd_e m_command;
    quint32 m_messageLength;

    PgasData m_pgasData;
};

#endif // CLIENT_H
