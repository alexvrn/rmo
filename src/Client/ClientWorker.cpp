// Local
#include "ClientWorker.h"

// Qt
#include <QFile>
#include <QSettings>
#include <QDir>
#include <QDateTime>
#include <QDebug>

// CBOR
#include <cbor.h>
#include <cmd_data_packer.h>
#include <cmd_data_debug.h>


ClientWorker::ClientWorker(QObject *parent)
  : QObject(parent)
  , m_seconds(0)
{
  // Запрашиваем накопившиеся данные за заданное в конфиге количество секунд
  QSettings settings("SAMI_DVO_RAN", "rmo");
  m_seconds = settings.value("SHP/seconds", 60).toInt();

  //! TODO: очень долгая операция. Убрать из конструктора
  //m_pgasData = parseFile(m_seconds);
  emit pgasData(m_pgasData);

  //! FAKE
  // setup a timer that repeatedly calls MainWindow::realtimeDataSlot:
  //connect(&m_dataTimer, SIGNAL(timeout()), this, SLOT(realtimeDataSlot()));
  //m_dataTimer.start(500); // Interval 0 means to refresh as fast as possible
}


ClientWorker::~ClientWorker()
{
}


QVariantMap ClientWorker::parseData(CommandType::Command cmd, const QByteArray& data) const
{
  QByteArray _d = data; //! TODO
  size_t offset = 0;
  cbor_stream_t cborStream = {reinterpret_cast<unsigned char*>(_d.data()), static_cast<size_t>(data.length()), 0};
  switch (cmd)
  {
    case CommandType::Stream_1:
    {
      cmd_data86_t cmdData;
      cmd_data86_unpack(&cborStream, &offset, &cmdData);
      QVariantMap vm;
      vm["streamId"]    = cmdData.streamId;
      vm["timestamp"]   = QDateTime::fromSecsSinceEpoch(cmdData.timestamp);
      vm["coefCount"]   = cmdData.coefCount;
      vm["elemCount"]   = cmdData.elemCount;
      vm["lowFreq"]     = cmdData.lowFreq;
      vm["highFreq"]    = cmdData.highFreq;
      vm["heading"]     = cmdData.heading;
      vm["data"]        = cmdData.data;
      vm["stationId"]   = cmdData.stationId;
      vm["serviceData"] = QByteArray(cmdData.serviceData.data);
      return vm;
    }
//    case CommandType::Stream_2:
//    {
//      cmd_data89_t cmdData;
//      cmd_data89_unpack(&cborStream, &offset, &cmdData);
//      return QVariantMap();
//    }
    case CommandType::Stream_3:
    case CommandType::Stream_4:
    {
      cmd_data92_t cmdData;
      cmd_data92_unpack(&cborStream, &offset, &cmdData);
      QVariantMap vm;
      vm["streamId"]    = cmdData.streamId;
      vm["timestamp"]   = QDateTime::fromSecsSinceEpoch(cmdData.timestamp);
      vm["beamCount"]   = cmdData.beamCount;
      vm["lowFreq"]     = cmdData.lowFreq;
      vm["highFreq"]    = cmdData.highFreq;
      vm["heading"]     = cmdData.heading;
      vm["headingStd"]  = cmdData.headingStd;
      vm["data"]        = cmdData.data;
      vm["stationId"]   = cmdData.stationId;
      vm["serviceData"] = QByteArray(cmdData.serviceData.data);
      if (cmd == CommandType::Stream_4)
      {
        //uint timestamp = vm["timestamp"].toUInt();
        //QDateTime dt = QDateTime::fromSecsSinceEpoch(timestamp);
        //qDebug() << vm["beamCount"] << dt;
      }
      return vm;
    }
//    case CommandType::Stream_5:
//    {
//      cmd_data89_t cmdData;
//      cmd_data89_unpack(&cborStream, &offset, &cmdData);
//      return QVariantMap();
//    }
//    case CommandType::Stream_6:
//    {
//      cmd_data92_t cmdData;
//      cmd_data92_unpack(&cborStream, &offset, &cmdData);
//      return QVariantMap();
//    }
//    case CommandType::Stream_7:
//    {
//      cmd_data86_t cmdData;
//      cmd_data86_unpack(&cborStream, &offset, &cmdData);
//      return QVariantMap();
//    }
//    case CommandType::Stream_8:
//    {
//      cmd_data89_t cmdData;
//      cmd_data89_unpack(&cborStream, &offset, &cmdData);
//      return QVariantMap();
//    }
//    case CommandType::Stream_9:
//    {
//      cmd_data92_t cmdData;
//      cmd_data92_unpack(&cborStream, &offset, &cmdData);
//     return QVariantMap();
//    }
//    case CommandType::Stream_10:
//    {
//      cmd_data86_t cmdData;
//      cmd_data86_unpack(&cborStream, &offset, &cmdData);
//      return QVariantMap();
//    }
//    case CommandType::Stream_11:
//    {
//      cmd_data89_t cmdData;
//      cmd_data89_unpack(&cborStream, &offset, &cmdData);
//      return QVariantMap();
//    }
//    case CommandType::Stream_12:
//    {
//      cmd_data92_t cmdData;
//      cmd_data92_unpack(&cborStream, &offset, &cmdData);
//      return QVariantMap();
//    }
//    case CommandType::Stream_13:
//    {
//      cmd_data86_t cmdData;
//      cmd_data86_unpack(&cborStream, &offset, &cmdData);
//      return QVariantMap();
//    }
//    case CommandType::Stream_14:
//    {
//      cmd_data89_t cmdData;
//      cmd_data89_unpack(&cborStream, &offset, &cmdData);
//      return QVariantMap();
//    }
//    case CommandType::Stream_15:
//    {
//      cmd_data92_t cmdData;
//      cmd_data92_unpack(&cborStream, &offset, &cmdData);
//      return QVariantMap();
//    }
//    case CommandType::Stream_16:
//    {
//      cmd_data86_t cmdData;
//      cmd_data86_unpack(&cborStream, &offset, &cmdData);
//      return QVariantMap();
//    }
//    case CommandType::Stream_17:
//    {
//      cmd_data89_t cmdData;
//      cmd_data89_unpack(&cborStream, &offset, &cmdData);
//     return QVariantMap();
//    }
//    case CommandType::Stream_18:
//    {
//      cmd_data92_t cmdData;
//      cmd_data92_unpack(&cborStream, &offset, &cmdData);
//      return QVariantMap();
//    }
//    case CommandType::Stream_19:
//    {
//      cmd_data86_t cmdData;
//      cmd_data86_unpack(&cborStream, &offset, &cmdData);
//      return QVariantMap();
//    }
//    case CommandType::Stream_20:
//    {
//      cmd_data89_t cmdData;
//      cmd_data89_unpack(&cborStream, &offset, &cmdData);
//      return QVariantMap();
//    }
//    case CommandType::Stream_21:
//    {
//      cmd_data92_t cmdData;
//      cmd_data92_unpack(&cborStream, &offset, &cmdData);
//      return QVariantMap();
//    }
//    case CommandType::Stream_22:
//    {
//      cmd_data92_t cmdData;
//      cmd_data92_unpack(&cborStream, &offset, &cmdData);
//      return QVariantMap();
//    }
    default:
    {
      //qWarning() << tr("Неизвестный номер потока") << cmd;
      return QVariantMap();
    }
  }
}


PgasData ClientWorker::parseFileForDateTime(const QDateTime& dateTime) const
{
  QSettings settings("SAMI_DVO_RAN", "rmo");
  QString sourceDataPath = settings.value("sourceDataPath",
#if defined(Q_OS_LINUX)
    "/tmp/rmoserver"
  #else
        "C:\\tmp\\rmoserver"
  #endif
  ).toString();

  // Ищем файл с запрашиваемой датой
  QFile dat(QString("%1%2%3%4").arg(sourceDataPath).arg(QDir::separator()).arg(dateTime.date().toString("ddMMyyyy")).arg(".dat"));
  if (dat.exists())
  {
    if (dat.open(QIODevice::ReadOnly))
    {
      QDataStream in(&dat);
      in.setVersion(QDataStream::Qt_5_9);

      PgasData result;
      while (!in.atEnd())
      {
        quint16 cmd;
        quint32 dataLength;
        QByteArray dataArray;
        in >> cmd;
        in >> dataLength;
        if (dataLength != 0)
        {
          dataArray.resize(dataLength);
          int bytesRead = in.readRawData(dataArray.data(), dataLength);
          if (bytesRead == -1)
          {
            qWarning() << tr("Ошибка чтения файла");
            return PgasData();
          }
          CommandType::Command command = static_cast<CommandType::Command>(cmd);
          QVariantMap vm = parseData(command, dataArray);
          QDateTime dt = vm["timestamp"].toDateTime();
          if (dt.time().hour() == dateTime.time().hour()
              && dt.time().minute() == dateTime.time().minute())
          {
            addDate(command, vm, result);
          }
        }
      }

      return result;
    }
  }

  return PgasData();
}


PgasData ClientWorker::parseFile(int seconds) const
{
  if (seconds <= 0)
    return PgasData();

  QSettings settings("SAMI_DVO_RAN", "rmo");
  QString sourceDataPath = settings.value("sourceDataPath",
#if defined(Q_OS_LINUX)
    "/tmp/rmoserver"
  #else
        "C:\\tmp\\rmoserver"
  #endif
  ).toString();

  const QDateTime now = QDateTime::currentDateTime();

  // Ищем файл с запрашиваемой датой
  QFile dat(QString("%1%2%3%4").arg(sourceDataPath).arg(QDir::separator()).arg(now.date().toString("ddMMyyyy")).arg(".dat"));
  if (dat.exists())
  {
    if (dat.open(QIODevice::ReadOnly))
    {
      QDataStream in(&dat);
      in.setVersion(QDataStream::Qt_5_9);

      PgasData result;
      while (!in.atEnd())
      {
        quint16 cmd;
        quint32 dataLength;
        QByteArray dataArray;
        in >> cmd;
        in >> dataLength;
        if (dataLength != 0)
        {
          dataArray.resize(dataLength);
          int bytesRead = in.readRawData(dataArray.data(), dataLength);
          if (bytesRead == -1)
          {
            qWarning() << tr("Ошибка чтения файла");
            return PgasData();
          }
          const CommandType::Command command = static_cast<CommandType::Command>(cmd);
          const QVariantMap vm = parseData(command, dataArray);
          const QDateTime dt = vm["timestamp"].toDateTime();
          if (dt.secsTo(now) <= seconds)
            addDate(command, vm, result);
        }
      }

      return result;
    }
  }
  else
    qWarning() << tr("Отсутствует файл") << dat.fileName();

  return PgasData();
}


QList<QVariantMap> ClientWorker::parseFile(int stationId, CommandType::Command command, const QDateTime& lowerDateTime, const QDateTime& upperDateTime) const
{
  // Проверка корректности данных
  if (lowerDateTime >= upperDateTime)
    return QList<QVariantMap>();

  // Существуют ли данные для номера ПГАС stationId
  if (!m_pgasData.contains(stationId))
    return QList<QVariantMap>();

  // Существуют ли данные для потока command
  if (!m_pgasData[stationId].contains(command))
    return QList<QVariantMap>();

  QList<QVariantMap> result;
  auto vms = m_pgasData[stationId][command];
  for (auto vm : vms)
  {
    const QDateTime dt = vm["timestamp"].toDateTime();
    if (dt >= lowerDateTime && dt <= upperDateTime)
      result.append(vm);
  }

  return result;
}


void ClientWorker::calculateData(const QByteArray& data, CommandType::Command cmd)
{
  if (cmd >= CommandType::Stream_1 && cmd <= CommandType::Stream_22)
  {
    QVariantMap vm = parseData(cmd, data);

    // Номер ПГАС
    int stationId = vm["stationId"].toInt();
    if (stationId <= 0)
    {
      qWarning() << tr("Неверный номер ПГАС:") << stationId;
    }
    else
    {
      addDate(cmd, vm, m_pgasData);
      emit newData(m_pgasData, cmd);

//      QJsonObject jobject = QJsonDocument::fromJson(message).object();
//      if (!jobject.isEmpty())
//      {
//        qDebug() << jobject.keys();
//      }
//      else
//      {
//        qWarning() << tr("Невозможно преобразовать данные");
//      }
    }
  }
  else if (cmd >= CommandType::CMD_RequestData_DateTime)
  {
    // Команда на запрос данных по дате-времени
  }
}


void ClientWorker::addDate(CommandType::Command command, const QVariantMap& vm, PgasData& container) const
{
  // Номер ПГАС
  int stationId = vm["stationId"].toInt();
  if (stationId <= 0)
  {
    qWarning() << tr("Неверный номер ПГАС:") << stationId;
    return;
  }
  else
  {
    if (container.contains(stationId))
    {
      auto map = container[stationId];
      if (map.contains(command))
      {
        // Проверяем, наполнен ли контейнер до максимального значения
        QList<QVariantMap> vms = container[stationId][command];
        if (vms.isEmpty())
        {
          // Контейнер пустой, поэтому просто добавляем элемент
          container[stationId][command].append(vm);
          return;
        }
        // Берем первое и последнее добавляемое значение времени и берем разницу в секундах
        const QDateTime lowerDateTime = vms[0]["timestamp"].toDateTime();
        const QDateTime upperDateTime = vm["timestamp"].toDateTime();
        if (lowerDateTime.addSecs(m_seconds) < upperDateTime)
        {
          // Удаляем данные с первой датой
          auto end = std::remove_if(vms.begin(), vms.end(),
                                          [lowerDateTime](const QVariantMap& vm)
                                          {
                                            const QDateTime dt = vm["timestamp"].toDateTime();
                                            return (dt.time().hour() == lowerDateTime.time().hour()
                                                    && dt.time().minute() == lowerDateTime.time().minute()
                                                    && dt.time().second() == lowerDateTime.time().second());
                                          });
          vms.erase(end, vms.end());
          container[stationId][command] = vms;
        }
        container[stationId][command].append(vm);
      }
      else
        container[stationId].insert(command, QList<QVariantMap>() << vm);
    }
    else
    {
      QHash<CommandType::Command, QList<QVariantMap> > cvm;
      cvm.insert(command, QList<QVariantMap>() << vm);
      container.insert(stationId, cvm);
    }
  }
}
