// Local
#include "GraphicTimeWorker.h"

// Qt
#include <QTime>
#include <QDebug>

GraphicTimeWorker::GraphicTimeWorker(QObject *parent)
  : QObject(parent)
{

}


void GraphicTimeWorker::calculateData(const QList<QVariantMap>& data, bool isNowData, int seconds, int shiftData,
                                      int verticalScrollBarMaximum, int verticalScrollBarValue, const QDateTime& checkDateTime,
                                      bool reverse)
{
  if (data.isEmpty())
    return;

  const int nx = 128;
  const int ny = isNowData ? seconds : 60;//(data.length() - indexBegin) / 128;

  const int size = isNowData ? shiftData : 60;
  const int valueScroll = isNowData ? (reverse ? verticalScrollBarValue : (verticalScrollBarMaximum - verticalScrollBarValue)) : 0;
  //const int valueScroll = isNowData ? (-verticalScrollBarMaximum + verticalScrollBarValue) : 0;

  // Текущее время на оборудовании (может отличаться от времени на РМО)
  // Поэтому берем текущее время из крайнего набора данных
  const QDateTime nowTime = data.last()["timestamp"].toDateTime();
  QDateTime bottomRange = isNowData ? nowTime : checkDateTime.addSecs(60); // Нижняя граница времени на графике

  QHash<QPair<int, int>, double> result;

  // Соответствие времени и координаты по оси Y
  QHash<int, int> timeAxis;
  // Кол-во секунд от начала дня
  const int secsBottomRange = static_cast<int>(bottomRange.time().msecsSinceStartOfDay() / 1000.0);
  for (int i = 0; i < ny; ++i)
    timeAxis[secsBottomRange - ny + i] = i - valueScroll;

  for (int index = 0; index < data.length(); index++)
  {
    QDateTime dateTime = data[index]["timestamp"].toDateTime();
    const int secs = static_cast<int>(dateTime.time().msecsSinceStartOfDay() / 1000.0);
    if (!timeAxis.contains(secs))
      continue;

    const int xIndex = data[index]["beamCount"].toInt();
    // чтобы не было предупреждения
    if (!(xIndex < nx && timeAxis[secs] >= 0 && timeAxis[secs] < size))
      continue;

    result.insert(qMakePair(xIndex, timeAxis[secs]), data[index]["data"].toDouble());
  }

  emit calculatedData(result, nx, size, ny, bottomRange, verticalScrollBarMaximum, verticalScrollBarValue, reverse);
}

