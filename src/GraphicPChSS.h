#ifndef GRAPHICPCHSS_H
#define GRAPHICPCHSS_H

// Qt
#include <QThread>

// Local
#include "GraphicPChSSWorker.h"
#include "CPColorMap.h"
#include "AbstractGraphic.h"

class GraphicPChSS : public AbstractGraphic
{
  Q_OBJECT

  public:
    GraphicPChSS(QWidget *parent = nullptr);
    ~GraphicPChSS();

  public Q_SLOTS:
    void calculateData(const QList<QVariantMap>& data, bool isNowData, int seconds, int shiftData,
                       int verticalScrollBarMaximum, int verticalScrollBarValue, const QDateTime& checkDateTime, bool reverse);
    void calculatedData(const QHash<QPair<int, int>, double>& result, int keySize, int valueSize, int yRange,
                        const QDateTime& bottomRange, int verticalScrollBarValue);

    void clearData() override;
    void setGradient(const QCPColorGradient& gradient) override;

  private Q_SLOTS:
    void mouseMove(QMouseEvent* event);
    void mousePress(QMouseEvent* event);

  private:
    GraphicPChSSWorker* m_worker;
    QThread* m_thread;

    CPColorMap* m_colorMap;
    QCPColorScale* m_colorScale;
};

#endif // GRAPHICPCHSS_H
