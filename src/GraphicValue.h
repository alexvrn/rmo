#ifndef GRAPHICVALUE_H
#define GRAPHICVALUE_H

// Qt
#include <QWidget>
#include <QList>

// Local
#include "AbstractGraphic.h"
#include "CPColorMap.h"
#include "GraphicValueWorker.h"

// UI
namespace Ui
{
  class GraphicValue;
}

class GraphicValue : public QWidget, public AbstractGraphic
{
  Q_OBJECT

  public:
    explicit GraphicValue(QWidget *parent = 0);
    ~GraphicValue();

    void setIndicatorType(IndicatorType indicatorType);

    void clearData() override;
    void setLabel(const QString& text) override;
    void replot(const QList<QVariantMap>& data, const QDateTime& dateTime = QDateTime()) override;
    void setNowData(bool nowData) override;
    void setGradient(const QCPColorGradient& gradient) override;
    bool isNowData() const;

  public Q_SLOTS:
    void onPalette(int value);
    void calculatedData(const QHash<QPair<int, int>, double>& result, int keySize, int valueSize, int yRange,
                        const QDateTime& bottomRange, int verticalScrollBarValue);

  signals:
    void info(const QString& text);

  private Q_SLOTS:
    void mouseMove(QMouseEvent* event);
    void mousePress(QMouseEvent* event);

    void on_toolButtonGrid_toggled(bool checked);
    void on_orientationToolButton_clicked();
    void on_predIndicatorComboBox_activated(int index);

    void verticalScrollBarValueChanged(int value);
    void verticalScrollBarSliderReleased();

    void brightness(int value);

    void replot();

  private:
    int shiftData() const;
    void scrollMinMax();

    Ui::GraphicValue *ui;

    GraphicValueWorker* m_worker;
    QThread* m_thread;

    QColor m_graphColor;

    bool m_nowData;

    int m_seconds;
    QDateTime m_checkDateTime;

    CPColorMap* m_colorMap;
    QCPColorScale* m_colorScale;

    IndicatorType m_indicatorType;

    QList<QVariantMap> m_data;
};

#endif // GRAPHICVALUE_H
