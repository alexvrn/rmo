#ifndef GRAPHICPCHSSWORKER_H
#define GRAPHICPCHSSWORKER_H

// Qt
#include <QObject>
#include <QVariantMap>

class GraphicPChSSWorker : public QObject
{
  Q_OBJECT

  public:
    GraphicPChSSWorker(QObject* parent = nullptr);

  public Q_SLOTS:
    void calculateData(const QList<QVariantMap>& data, bool isNowData, int seconds, int shiftData,
                       int verticalScrollBarMaximum, int verticalScrollBarValue, const QDateTime& checkDateTime,
                       bool reverse);
  Q_SIGNALS:
    void calculatedData(const QHash<QPair<int, int>, double>& result, int keySize, int valueSize, int yRange,
                        const QDateTime& bottomRange, int verticalScrollBarValue);
};

#endif // GRAPHICPCHSSWORKER_H
