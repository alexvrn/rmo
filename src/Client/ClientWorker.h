#ifndef CLIENTWORKER_H
#define CLIENTWORKER_H

// Qt
#include <QObject>
#include <QVariantMap>

// Local
#include "AuthDialog.h"
#include "ResponseReceiver.h"

// cmd
#include <cmd.h>
#include <cmd_data_debug.h>

class ClientWorker : public QObject
{
  Q_OBJECT

  public:
    explicit ClientWorker(QObject *parent = Q_NULLPTR);
    ~ClientWorker();

  public slots:
    void calculateData(const QByteArray& data, cmd_e cmd);

    //! Получение данных из файла для времени dateTime(с точностью до минуты)
    //! int stationId - номер ПГАС
    void parseFileForDateTime(int stationId, const QDateTime& dateTime);

  signals:
    void newData(const PgasData& pgasData, cmd_e cmd, const QVariant& value = QVariant());
    void pgasData(const PgasData& pgasData);
    void parsedFileForDateTime(const PgasData& data);

  private slots:
    //! Получение данных за seconds секунд, начиная от текущего времени
    PgasData parseFile(int stationId, int seconds) const;

    //! Получение данных за заданный период
    QList<QVariantMap> parseFile(int stationId, cmd_e command, const QDateTime& lowerDateTime, const QDateTime& upperDateTime) const;

  private:
    QVariantMap parseData(cmd_e cmd, const QByteArray& data) const;
    void addDate(cmd_e cmd, const QVariantMap& vm, PgasData& container) const;

    PgasData m_pgasData;
    int m_seconds;
};

#endif // CLIENTWORKER_H
