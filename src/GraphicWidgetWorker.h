#ifndef GRAPHICWIDGETWORKER_H
#define GRAPHICWIDGETWORKER_H

// Qt
#include <QTime>
#include <QVariantMap>

// Local
class Graphic;
#include <commandType.h>

namespace Ui
{
  class GraphicWidget;
}

class GraphicWidgetWorker : public QObject
{
  Q_OBJECT

  public:
    explicit GraphicWidgetWorker(QObject *parent = 0);
    ~GraphicWidgetWorker();

  public slots:
    void calculateData(const QList<QVariantMap>& data, bool isNowData, int seconds, int shiftData,
                       int verticalScrollBarMaximum, int verticalScrollBarValue, const QDateTime& checkDateTime);

  signals:
    void calculatedData(const QHash<QPair<int, int>, double>& result, int keySize, int valueSize, int yRange);
};

#endif // GRAPHICWIDGETWORKER_H
