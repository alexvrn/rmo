#ifndef CLIENTWORKER_H
#define CLIENTWORKER_H

// Qt
#include <QObject>
#include <QVariantMap>

// Local
#include "AuthDialog.h"
#include "ResponseReceiver.h"
#include "commandType.h"

class ClientWorker : public QObject
{
  Q_OBJECT

  public:
    explicit ClientWorker(QObject *parent = Q_NULLPTR);
    ~ClientWorker();

  public slots:
    void calculateData(const QByteArray& data, CommandType::Command cmd);
    PgasData pgasData() const;

  signals:
    void newData(CommandType::Command cmd, const QVariant& value = QVariant());

  private slots:
    //! Получение данных из файла для времени dateTime(с точностью до минуты)
    PgasData parseFile(const QDateTime& dateTime) const;

    //! Получение данных за seconds секунд, начиная от текущего времени
    PgasData parseFile(int seconds) const;

    //! Получение данных за заданный период
    QList<QVariantMap> parseFile(int stationId, CommandType::Command command, const QDateTime& lowerDateTime, const QDateTime& upperDateTime) const;

  private:
    QVariantMap parseData(CommandType::Command cmd, const QByteArray& data) const;
    void addDate(CommandType::Command cmd, const QVariantMap& vm, PgasData& container) const;

    PgasData m_pgasData;
    int m_seconds;
};

#endif // CLIENTWORKER_H
