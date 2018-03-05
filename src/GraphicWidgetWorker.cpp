// Local
#include "GraphicWidgetWorker.h"

// Qt
#include <QtConcurrent>
#include <QFuture>

GraphicWidgetWorker::GraphicWidgetWorker(QObject *parent)
  : QObject(parent)
{
}


GraphicWidgetWorker::~GraphicWidgetWorker()
{
}


void GraphicWidgetWorker::calculateData(const QList<QVariantMap>& data, bool isNowData, int seconds, int shiftData,
                                             int verticalScrollBarMaximum, int verticalScrollBarValue, const QDateTime& checkDateTime)
{
  if (data.isEmpty())
    return;

  const int nx = 128;
  const int ny = isNowData ? seconds : 60;//(data.length() - indexBegin) / 128;

  const int size = isNowData ? shiftData : 60;
  const int valueScroll = isNowData ? (verticalScrollBarMaximum - verticalScrollBarValue) : 0;

  // Убираем миллисекунды
  //QDateTime bottomRange = isNowData() ? QDateTime::currentDateTime() : m_checkDateTime.addSecs(60);
  const QDateTime nowTime = QDateTime::fromSecsSinceEpoch(data.last()["timestamp"].toUInt()); // Текущее время на оборудовании (может отличаться от времени на РМО)
  QDateTime bottomRange = isNowData ? nowTime : checkDateTime.addSecs(60); // Нижняя граница времени на графике
  const QTime bottomTime = QTime(bottomRange.time().hour(),
                                 bottomRange.time().minute(),
                                 bottomRange.time().second());
  bottomRange.setTime(bottomTime);

  QHash<QPair<int, int>, double> result;

  // Соответствие времени и координаты по оси Y
  QHash<QDateTime, int> timeAxis;
  for (int i = 0; i < ny; ++i)
    timeAxis[bottomRange.addSecs(-i)] = i - valueScroll;

  for (int index = 0; index < data.length(); index++)
  {
    const uint timestamp = data[index]["timestamp"].toUInt();
    QDateTime dateTime = QDateTime::fromSecsSinceEpoch(timestamp);

    // Обнуляем секунды
    const QTime checkTime = dateTime.time();
    const QTime time(checkTime.hour(), checkTime.minute(), checkTime.second());
    dateTime.setTime(time);
    if (!timeAxis.contains(dateTime))
      continue;

    const int xIndex = data[index]["beamCount"].toInt();
    // чтобы не было предупреждения
    if (!(xIndex < nx && timeAxis[dateTime] >= 0 && timeAxis[dateTime] < size))
      continue;

    result.insert(qMakePair(xIndex, timeAxis[dateTime]), data[index]["data"].toDouble());
  }

  emit calculatedData(result, nx, size, ny);
}
