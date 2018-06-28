// Local
#include "ClientWorker.h"

// Qt
#include <QFile>
#include <QSettings>
#include <QDir>
#include <QDateTime>
#include <QDebug>

const qint64 commandCount = 22;
const qint64 messageLength = 100;

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


QVariantMap ClientWorker::parseData(cmd_e command, const QByteArray& message) const
{
  QVariantMap vm;

  switch (command)
  {
    // STREAM
    case CMD_STREAM1:
    {
      cmd_data86_t* cmd_data86 = reinterpret_cast<cmd_data86_t*>(const_cast<char*>(message.data()));
      cmd_data86_print(cmd_data86);
      break;
    }
    case CMD_STREAM2:
    {
      cmd_data89_t* cmd_data89 = reinterpret_cast<cmd_data89_t*>(const_cast<char*>(message.data()));
      cmd_data89_print(cmd_data89);
      break;
    }
    case CMD_STREAM3:
    case CMD_STREAM4:
    {
      cmd_data92_t* cmd_data92 = reinterpret_cast<cmd_data92_t*>(const_cast<char*>(message.data()));
      //cmd_data92_print(cmd_data92);
      vm["streamId"]    = cmd_data92->streamId;
      vm["timestamp"]   = QDateTime::fromSecsSinceEpoch(cmd_data92->timestamp);
      vm["beamCount"]   = cmd_data92->beamCount;
      vm["lowFreq"]     = cmd_data92->lowFreq;
      vm["highFreq"]    = cmd_data92->highFreq;
      vm["heading"]     = cmd_data92->heading;
      vm["headingStd"]  = cmd_data92->headingStd;
      vm["data"]        = cmd_data92->data;
      vm["stationId"]   = cmd_data92->stationId;
      vm["serviceData"] = QByteArray(cmd_data92->serviceData.data);
      if (command == CMD_STREAM4)
      {
        //uint timestamp = vm["timestamp"].toUInt();
        //QDateTime dt = QDateTime::fromSecsSinceEpoch(timestamp);
        //qDebug() << vm["beamCount"] << dt;
      }
      break;
    }
    case CMD_STREAM5:
    case CMD_STREAM6:
    {
      cmd_data95_t* cmd_data95 = reinterpret_cast<cmd_data95_t*>(const_cast<char*>(message.data()));
      cmd_data95_print(cmd_data95);
      break;
    }
    case CMD_STREAM7:
    {
      cmd_data104_t* cmd_data104 = reinterpret_cast<cmd_data104_t*>(const_cast<char*>(message.data()));
      cmd_data104_print(cmd_data104);
      break;
    }
    case CMD_STREAM8:
    case CMD_STREAM10:
    case CMD_STREAM12:
    {
      cmd_data107_t* cmd_data107 = reinterpret_cast<cmd_data107_t*>(const_cast<char*>(message.data()));
      cmd_data107_print(cmd_data107);
      break;
    }
    case CMD_STREAM9:
    case CMD_STREAM11:
    case CMD_STREAM13:
    {
      cmd_data110_t* cmd_data110 = reinterpret_cast<cmd_data110_t*>(const_cast<char*>(message.data()));
      cmd_data110_print(cmd_data110);
      break;
    }
    case CMD_STREAM14:
    {
      cmd_data114_t* cmd_data114 = reinterpret_cast<cmd_data114_t*>(const_cast<char*>(message.data()));
      cmd_data114_print(cmd_data114);
      break;
    }
    case CMD_STREAM15:
    {
      cmd_data117_t* cmd_data117 = reinterpret_cast<cmd_data117_t*>(const_cast<char*>(message.data()));
      cmd_data117_print(cmd_data117);
      break;
    }
    case CMD_STREAM16:
    {
      cmd_data121_t* cmd_data121 = reinterpret_cast<cmd_data121_t*>(const_cast<char*>(message.data()));
      cmd_data121_print(cmd_data121);
      break;
    }
    case CMD_STREAM17:
    {
      cmd_data124_t* cmd_data124 = reinterpret_cast<cmd_data124_t*>(const_cast<char*>(message.data()));
      cmd_data124_print(cmd_data124);
      break;
    }
    case CMD_STREAM18:
    {
      cmd_data132_t* cmd_data132 = reinterpret_cast<cmd_data132_t*>(const_cast<char*>(message.data()));
      cmd_data132_print(cmd_data132);
      break;
    }
    case CMD_STREAM19:
    {
      cmd_data135_t* cmd_data135 = reinterpret_cast<cmd_data135_t*>(const_cast<char*>(message.data()));
      cmd_data135_print(cmd_data135);
      break;
    }
    case CMD_STREAM20:
    {
      cmd_data145_t* cmd_data145 = reinterpret_cast<cmd_data145_t*>(const_cast<char*>(message.data()));
      cmd_data145_print(cmd_data145);
      break;
    }
    case CMD_STREAM21:
    {
      cmd_data154_t* cmd_data154 = reinterpret_cast<cmd_data154_t*>(const_cast<char*>(message.data()));
      cmd_data154_print(cmd_data154);
      break;
    }
    case CMD_STREAM22:
    {
      cmd_data174_t* cmd_data174 = reinterpret_cast<cmd_data174_t*>(const_cast<char*>(message.data()));
      cmd_data174_print(cmd_data174);
      break;
    }
    // STREAM

    case CMD_GET_SELF_DIAGNOSIS:
    {
      cmd_data187_t* cmd_data187 = reinterpret_cast<cmd_data187_t*>(const_cast<char*>(message.data()));
      cmd_data187_print(cmd_data187);
      break;
    }
    case CMD_SERVICE:
    {
      cmd_data0_t* cmd_data0 = reinterpret_cast<cmd_data0_t*>(const_cast<char*>(message.data()));
      cmd_data0_print(cmd_data0);
      break;
    }
    case CMD_GET_FIRMWARE_SHA1:
    {
      cmd_data16_t* cmd_data16 = reinterpret_cast<cmd_data16_t*>(const_cast<char*>(message.data()));
      cmd_data16_print(cmd_data16);
      break;
    }
    case CMD_GET_RTC:
    {
      cmd_data19_t* cmd_data19 = reinterpret_cast<cmd_data19_t*>(const_cast<char*>(message.data()));
      cmd_data19_print(cmd_data19);
      break;
    }
    case CMD_GET_ANTENNA_DEFECTIVE_COLUMNS:
    {
      cmd_data28_t* cmd_data28 = reinterpret_cast<cmd_data28_t*>(const_cast<char*>(message.data()));
      cmd_data28_print(cmd_data28);
      break;
    }
    case CMD_GET_ENV_PARAMS:
    {
      cmd_data36_t* cmd_data36 = reinterpret_cast<cmd_data36_t*>(const_cast<char*>(message.data()));
      cmd_data36_print(cmd_data36);
      break;
    }
    case CMD_GET_ACTIVE_SCHEDULE:
    {
      cmd_data47_t* cmd_data47 = reinterpret_cast<cmd_data47_t*>(const_cast<char*>(message.data()));
      cmd_data47_print(cmd_data47);
      break;
    }
    case CMD_GET_UTCS_TRANSMIT_SCHEDULE:
    {
      cmd_data58_t* cmd_data58 = reinterpret_cast<cmd_data58_t*>(const_cast<char*>(message.data()));
      cmd_data58_print(cmd_data58);
      break;
    }
    case CMD_GET_SATCOM_SCHEDULE:
    {
      cmd_data69_t* cmd_data69 = reinterpret_cast<cmd_data69_t*>(const_cast<char*>(message.data()));
      cmd_data69_print(cmd_data69);
      break;
    }
    case CMD_GET_PASSIVE_PROCESSING_PARAMETERS:
    {
      cmd_data71_t* cmd_data71 = reinterpret_cast<cmd_data71_t*>(const_cast<char*>(message.data()));
      cmd_data71_print(cmd_data71);
      break;
    }
    case CMD_GET_ATT_1:
    {
      cmd_data82_t* cmd_data82 = reinterpret_cast<cmd_data82_t*>(const_cast<char*>(message.data()));
      cmd_data82_print(cmd_data82);
      break;
    }
    case CMD_GET_PASSIVE_MARKS:
    {
      cmd_data101_t* cmd_data101 = reinterpret_cast<cmd_data101_t*>(const_cast<char*>(message.data()));
      cmd_data101_print(cmd_data101);
      break;
    }
    case CMD_GET_ACTIVE_GET_ANGLE_ID_MARKS:
    {
      cmd_data129_t* cmd_data129 = reinterpret_cast<cmd_data129_t*>(const_cast<char*>(message.data()));
      cmd_data129_print(cmd_data129);
      break;
    }
    case CMD_GET_UTCS_INBOX:
    {
      cmd_data142_t* cmd_data142 = reinterpret_cast<cmd_data142_t*>(const_cast<char*>(message.data()));
      cmd_data142_print(cmd_data142);
      break;
    }
    case CMD_GET_PASSIVE_TARGETS:
    {
      cmd_data151_t* cmd_data151 = reinterpret_cast<cmd_data151_t*>(const_cast<char*>(message.data()));
      cmd_data151_print(cmd_data151);
      break;
    }
    case CMD_GET_ACTIVE_TARGETS:
    {
      cmd_data160_t* cmd_data160 = reinterpret_cast<cmd_data160_t*>(const_cast<char*>(message.data()));
      cmd_data160_print(cmd_data160);
      break;
    }
    case CMD_GET_STREAMS:
    {
      cmd_data172_t* cmd_data172 = reinterpret_cast<cmd_data172_t*>(const_cast<char*>(message.data()));
      cmd_data172_print(cmd_data172);
      break;
    }
    default:
    {
      qWarning() << tr("Прочитана неизвестная команда") << command;
      return QVariantMap();
    }
  }

  return vm;
}


void ClientWorker::parseFileForDateTime(int stationId, const QDateTime& dateTime)
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
  QFile dat(QString("%1%2%3%4").arg(sourceDataPath).arg(QDir::separator())
                               .arg(QString("%1_%2").arg(dateTime.date().toString("ddMMyyyy")).arg(stationId))
                               .arg(".dat"));
  if (dat.exists() && dat.open(QIODevice::ReadOnly))
  {
    const auto msecsBegin = dateTime.time().msecsSinceStartOfDay();
    const auto posBegin = msecsBegin * commandCount * messageLength;

    PgasData result;
    qint64 currentPos = posBegin;
    int iter_msec = 0;

    while (iter_msec < 60 * 1000)
    {
      if (dat.size() < currentPos + commandCount * messageLength)
        break;

      bool check = false;

      if (!dat.seek(currentPos))
        break;

      QDataStream in(&dat);
      in.setVersion(QDataStream::Qt_5_9);
      for (int c = static_cast<int>(CMD_STREAM1); c <= static_cast<int>(CMD_STREAM22); ++c)
      {
        const qint64 pos = (c - static_cast<int>(CMD_STREAM1)) * messageLength;
        if (in.skipRawData(pos) == -1)
        {
          check = true;
          break;
        }

        QByteArray block;
        block.resize(messageLength);
        int bytesRead = in.readRawData(block.data(), messageLength);
        if (bytesRead == -1)
        {
          qWarning() << tr("Ошибка чтения файла") << dat.errorString();
          check = true;
          break;
        }

        QDataStream blockData(&block, QIODevice::ReadOnly);
        blockData.setVersion(QDataStream::Qt_5_9);

        quint16 cmd;
        blockData >> cmd;
        // Проверка что есть данные для данной команды
        if (cmd < static_cast<quint16>(CMD_STREAM1) || cmd > static_cast<quint16>(CMD_STREAM22))
          continue;

        quint32 dataLength;
        QByteArray dataArray;
        blockData >> dataLength;
        if (dataLength != 0)
        {
          dataArray.resize(dataLength);
          int bytesRead = blockData.readRawData(dataArray.data(), dataLength);
          if (bytesRead == -1)
          {
            qWarning() << tr("Ошибка чтения данных") << dat.errorString();
            check = true;
            break;
          }
          cmd_e command = static_cast<cmd_e>(cmd);
          QVariantMap vm = parseData(command, dataArray);
          addDate(command, vm, result);
        }
      } // for

      currentPos += commandCount * messageLength;
      iter_msec++;

      if (check)
        break;
    }  // while

    dat.close();

//      while (!in.atEnd())
//      {
//        quint16 cmd;
//        quint32 dataLength;
//        QByteArray dataArray;
//        in >> cmd;
//        in >> dataLength;
//        if (dataLength != 0)
//        {
//          dataArray.resize(dataLength);
//          int bytesRead = in.readRawData(dataArray.data(), dataLength);
//          if (bytesRead == -1)
//          {
//            qWarning() << tr("Ошибка чтения файла");
//            //return PgasData();
//            emit parsedFileForDateTime(PgasData());
//            return;
//          }
//          cmd_e command = static_cast<cmd_e>(cmd);
//          QVariantMap vm = parseData(command, dataArray);
//          QDateTime dt = vm["timestamp"].toDateTime();
//          if (dt.time().hour() == dateTime.time().hour()
//              && dt.time().minute() == dateTime.time().minute())
//          {
//            addDate(command, vm, result);
//          }
//        }
//      }

    //return result;

    emit parsedFileForDateTime(result);
    return;
  }
  else
  {
    emit parsedFileForDateTime(PgasData());
  }
}


PgasData ClientWorker::parseFile(int stationId, int seconds) const
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
  QFile dat(QString("%1%2%3%4").arg(sourceDataPath).arg(QDir::separator())
                               .arg(QString("%1_%2").arg(now.date().toString("ddMMyyyy")).arg(stationId))
                               .arg(".dat"));
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
          const cmd_e command = static_cast<cmd_e>(cmd);
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


QList<QVariantMap> ClientWorker::parseFile(int stationId, cmd_e command, const QDateTime& lowerDateTime, const QDateTime& upperDateTime) const
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


void ClientWorker::calculateData(const QByteArray& data, cmd_e cmd)
{
  if (cmd >= CMD_STREAM1 && cmd <= CMD_STREAM22)
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
  else
  //else if (cmd >= CommandType::CMD_RequestData_DateTime)
  {
    // Команда на запрос данных по дате-времени
  }
}


void ClientWorker::addDate(cmd_e command, const QVariantMap& vm, PgasData& container) const
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
      auto& map = container[stationId];
      if (map.contains(command))
      {
        // Проверяем, наполнен ли контейнер до максимального значения
        QList<QVariantMap>& vms = container[stationId][command];
        if (vms.isEmpty())
        {
          // Контейнер пустой, поэтому просто добавляем элемент
          container[stationId][command].append(vm);
          return;
        }
        // Берем первое и последнее добавляемое значение времени и берем разницу в секундах
        const QDateTime lowerDateTime = vms[0]["timestamp"].toDateTime();
        const QDateTime upperDateTime = vm["timestamp"].toDateTime();
        if (lowerDateTime.toSecsSinceEpoch() + m_seconds < upperDateTime.toSecsSinceEpoch())//lowerDateTime.addSecs(m_seconds) < upperDateTime)
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
      QMap<cmd_e, QList<QVariantMap> > cvm;
      cvm.insert(command, QList<QVariantMap>() << vm);
      container.insert(stationId, cvm);
    }
  }
}
