// Local
#include "Client.h"

// Qt
#include <QApplication>
#include <QTime>
#include <QTimer>
#include <QLocalSocket>
#include <QEventLoop>
#include <QSettings>
#include <QFile>
#include <QDataStream>
#include <QDir>

// CBOR
#include <cbor.h>
#include <cmd_data_packer.h>
#include <cmd_data_debug.h>

const quint16 idMessage = 0xCAFE;

Client::Client(QObject *parent)
  : QObject(parent)
  , m_socket(new QLocalSocket(this))
  , m_waitState(WaitingId)
  , m_messageLength(0)
  , m_seconds(0)
{
  connect(&m_authDialog, &AuthDialog::authentication, this, &Client::authAccess);

  connect(m_socket, SIGNAL(stateChanged(QLocalSocket::LocalSocketState)), SLOT(stateChanged(QLocalSocket::LocalSocketState)));
  connect(m_socket, SIGNAL(readyRead()), SLOT(readyRead()));

  //! FAKE
  // setup a timer that repeatedly calls MainWindow::realtimeDataSlot:
  //connect(&m_dataTimer, SIGNAL(timeout()), this, SLOT(realtimeDataSlot()));
  //m_dataTimer.start(500); // Interval 0 means to refresh as fast as possible

  // Запрашиваем накопившиеся данные за заданное в конфиге количество секунд
  QSettings settings("SAMI_DVO_RAN", "rmo");
  m_seconds = settings.value("SHP/seconds", 60).toInt();
  m_pgasData = parseFile(m_seconds);
}


Client& Client::instance(QObject *parent)
{
  static Client clientInstance(parent);
  return clientInstance;
}


Client::~Client()
{
}


void Client::sendCommand(CommandType::Command cmd, const QVariantMap& value)
{
  QByteArray data;

  switch (cmd)
  {
    case CommandType::CMD_RequestData_DateTime:
    {
      //! TODO: делать это тут или отдавать службе?
      //const qint64 secs = value["datetime"].toDateTime().toSecsSinceEpoch();
      //data = QByteArray::number(secs);
      break;
    }
    default:
      qWarning() << "Неизвестный тип команды" << cmd;
  }

  QByteArray package;
  QDataStream out(&package, QIODevice::WriteOnly);
  out.setVersion(QDataStream::Qt_5_9);
  // подготовка данных для записи
  out << quint16(idMessage);
  out << quint16(cmd);
  out << quint32(data.length());

  if (data.length())
  {
    if (-1 == out.writeRawData(data.data(), data.length()))
      qWarning() << tr("Ошибка отправки данных");
  }

  m_socket->write(package);
  if (!m_socket->waitForBytesWritten())
    qWarning() << tr("Ошибка отправки данных!"); //! TODO: что тут делать?
}


PgasData Client::pgasData() const
{
  return m_pgasData;
}


bool Client::connectToServer(const QString& host)
{
  qDebug() << qPrintable(QString(tr("Подключение к серверу %1")).arg(host));

  m_host = host;

  QEventLoop loop;
  connect(m_socket, &QLocalSocket::stateChanged, &loop, &QEventLoop::quit);
  QTimer::singleShot(500, this, SLOT(connectLater()));
  loop.exec();

  return m_socket->state() == QLocalSocket::ConnectedState;
}


void Client::connectLater()
{
  m_socket->connectToServer(m_host);
}


void Client::stateChanged(QLocalSocket::LocalSocketState state)
{
  switch (state)
  {
    case QLocalSocket::ConnectedState:
      qDebug() << tr("Подключение к локальному серверу сбора данных");

      // Через секунду запрашиваем авторизацию
      QTimer::singleShot(1000, this, SLOT(logout()));
      break;
    case QLocalSocket::UnconnectedState:
      qWarning() << tr("Не удаётся подключиться к локальному серверу");
      //! TODO: разобраться с подключением к серверу
      //qApp->quit();
      break;
    default: {}
  }
}


void Client::logout()
{
  if (m_authDialog.isVisible())
    return;

  if (QDialog::Rejected == m_authDialog.exec())
  {
    // Выходим из приложения, если пользователь отказаться авторизоваться
    qApp->quit();
  }
}


void Client::authAccess(const QVariantMap& userData)
{
  qDebug() << userData;
  m_authDialog.setResult(QDialog::Accepted);
  m_authDialog.hide();
  emit authentication();
  //! TODO: получение результата по сокету
//  QByteArray request = Proto::encode("request", method, data);

//  ResponseReceiver receiver(method);
//  connect(this, SIGNAL(messageReceived(QVariantMap)), &receiver, SLOT(messageReceived(QVariantMap)));
//  m_socket->write("");
//  receiver.run();

  //if (receiver.responseData())
  //{}
}


void Client::init()
{
  m_messageLength = 0;
  m_waitState = WaitingId;
}


QVariantMap Client::parseData(CommandType::Command cmd, const QByteArray& data) const
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
      vm["timestamp"]   = cmdData.timestamp;
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
      vm["timestamp"]   = cmdData.timestamp;
      vm["beamCount"]   = cmdData.beamCount;
      vm["lowFreq"]     = cmdData.lowFreq;
      vm["highFreq"]    = cmdData.highFreq;
      vm["heading"]     = cmdData.heading;
      vm["headingStd"]  = cmdData.headingStd;
      vm["data"]        = cmdData.data;
      vm["stationId"]   = cmdData.stationId;
      vm["serviceData"] = QByteArray(cmdData.serviceData.data);
      //if (cmd == CommandType::Stream_4)
      //  qDebug() << vm;
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


PgasData Client::parseFile(const QDateTime& dateTime) const
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
          uint timestamp = vm["timestamp"].toUInt();
          QDateTime dt = QDateTime::fromSecsSinceEpoch(timestamp);
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


PgasData Client::parseFile(int seconds) const
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
          CommandType::Command command = static_cast<CommandType::Command>(cmd);
          QVariantMap vm = parseData(command, dataArray);
          uint timestamp = vm["timestamp"].toUInt();
          QDateTime dt = QDateTime::fromSecsSinceEpoch(timestamp);
          if (dt.secsTo(now) <= seconds)
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


QList<QVariantMap> Client::parseFile(int stationId, CommandType::Command command, const QDateTime& lowerDateTime, const QDateTime& upperDateTime) const
{
  if (lowerDateTime >= upperDateTime)
    return QList<QVariantMap>();

  if (!m_pgasData.contains(stationId))
    return QList<QVariantMap>();

  if (!m_pgasData[stationId].contains(command))
    return QList<QVariantMap>();

  QList<QVariantMap> result;
  auto vms = m_pgasData[stationId][command];
  for (auto vm : vms)
  {
    const QDateTime dt = QDateTime::fromSecsSinceEpoch(vm["timestamp"].toUInt());
    if (dt >= lowerDateTime && dt <= upperDateTime)
      result.append(vm);
  }

  return result;
}


void Client::addDate(CommandType::Command command, const QVariantMap& vm, PgasData& container) const
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
        // Берем первое и последнее добавляемое значение времени и берем разницу в секундах
        const QDateTime lowerDateTime = QDateTime::fromSecsSinceEpoch(vms[0]["timestamp"].toUInt());
        const QDateTime upperDateTime = QDateTime::fromSecsSinceEpoch(vm["timestamp"].toUInt());
        if (lowerDateTime.addSecs(m_seconds) < upperDateTime)
        {
          // Удаляем данные с первой датой
          auto end = std::remove_if(vms.begin(), vms.end(),
                                          [lowerDateTime](const QVariantMap& vm)
                                          {
                                            const QDateTime dt = QDateTime::fromSecsSinceEpoch(vm["timestamp"].toUInt());
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


void Client::readyRead()
{
  // TDOD: не знаю, нужна ли тут эта проверка
  if (!m_socket)
    return;

  if (m_waitState == WaitingId)
  {
    // ждем ID-сообщения
    if (m_socket->bytesAvailable() < (qint64)sizeof(quint16))
      return;

    quint16 id;
    auto data = m_socket->read(sizeof(quint16));
    QDataStream dataStream(&data, QIODevice::ReadOnly);
    dataStream.setVersion(QDataStream::Qt_5_9);
    //! TODO: dataStream.setByteOrder(QDataStream::LittleEndian);
    dataStream >> id;
    if (id != idMessage)
    {
      init();
      qWarning() << tr("Попытка прочесть какое-то другое сообщение");
      return;
    }

    m_waitState = WaitingMessageType;
  }

  if (m_waitState == WaitingMessageType)
  {
    // ждем тип сообщения
    if (m_socket->bytesAvailable() < (qint64)sizeof(quint16))
      return;

    auto data = m_socket->read(sizeof(quint16));
    QDataStream dataStream(&data, QIODevice::ReadOnly);
    dataStream.setVersion(QDataStream::Qt_5_9);
    //! TODO: dataStream.setByteOrder(QDataStream::LittleEndian);

    quint16 command;
    dataStream >> command;
    m_command = static_cast<CommandType::Command>(command);

    m_waitState = WaitingLength;
  }

  if (m_waitState == WaitingLength)
  {
    // ждем размер сообщения
    if (m_socket->bytesAvailable() < (qint64)sizeof(quint32))
      return;

    auto data = m_socket->read(sizeof(quint32));
    QDataStream dataStream(&data, QIODevice::ReadOnly);
    dataStream.setVersion(QDataStream::Qt_5_9);
    //! TODO: dataStream.setByteOrder(QDataStream::LittleEndian);
    dataStream >> m_messageLength;

    m_waitState = WaitingMessage;
  }

  if (m_waitState == WaitingMessage)
  {
    // ждем сообщениe
    if (m_socket->bytesAvailable() < (qint64)m_messageLength)
      return;

    QByteArray message = m_socket->read(m_messageLength);
    if (m_command >= CommandType::Stream_1 && m_command <= CommandType::Stream_22)
    {
      QVariantMap vm = parseData(m_command, message);

      // Номер ПГАС
      int stationId = vm["stationId"].toInt();
      if (stationId <= 0)
      {
        qWarning() << tr("Неверный номер ПГАС:") << stationId;
      }
      else
      {
        addDate(m_command, vm, m_pgasData);
        emit newData(m_command);

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
    else if (m_command >= CommandType::CMD_RequestData_DateTime)
    {
      // Команда на запрос данных по дате-времени

    }
    init();

    // Проверяем, есть ли ещё сообщения
    if (m_socket->bytesAvailable())
      readyRead();
  }
}


void Client::disconnected()
{

}


void Client::realtimeDataSlot()
{
  //emit data(CommandType::CMD_PGAS_Data);
}

