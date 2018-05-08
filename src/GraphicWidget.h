#ifndef GRAPHICWIDGET_H
#define GRAPHICWIDGET_H

// Qt
#include <QWidget>
#include <QTimer>
#include <QVariantMap>
class QToolButton;

// Local
class Graphic;
#include <commandType.h>
class GraphicWidgetWorker;

// QCustomPlot
#include "qcustomplot.h"

namespace Ui
{
  class GraphicWidget;
}

class GraphicWidget : public QWidget
{
  Q_OBJECT

  public:
    // Типы индикатора
    enum IndicatorType
    {
      ShP,
      SA
    };

    // Типы пред-индикаторной обработки
    enum PredIndicatorType
    {
      Logarithm,
      Linear,
      Marker,
      Threshold,
      GL_Reverberation,
      GL_Noise,
      PseudoLinear
    };

    explicit GraphicWidget(QWidget *parent = 0);
    ~GraphicWidget();

    void setType(IndicatorType indicatorType);

  public slots:
    void setData(const QList<QVariantMap>& data, const QDateTime& dateTime = QDateTime());
    void setLightMode(const QString& mode);
    void newData();
    void setNowData(bool nowData);
    bool isNowData() const;
    void setDataType(const QString& text, CommandType::Command type);

    void resizeEvent(QResizeEvent* event);

    void calculateData(const QList<QVariantMap>& data, bool isNowData, int seconds, int shiftData,
                       int verticalScrollBarMaximum, int verticalScrollBarValue, const QDateTime& checkDateTime);

    void calculatedData(const QHash<QPair<int, int>, double>& result, int keySize, int valueSize, int yRange);

  private slots:
    void colorValue(const QColor &color);
    void brightness(int value);
    void setGradient(int value);

    void on_toolButtonGrid_toggled(bool checked);
    void on_orientationToolButton_clicked();
    void on_predIndicatorComboBox_activated(int index);

    void colorScaleLayout();

    void on_verticalScrollBar_valueChanged(int value);

    void dataRepaint();

    void on_verticalScrollBar_sliderReleased();

private:
    void shpRepaint();
    void pchssRepaint();
    int shiftData() const;

    Graphic* m_graphic;
    QCPColorScale* m_colorScale;

    QColor m_graphColor;

    QList<QToolButton*> m_toolButtons;

    QCPColorMap *m_colorMap;

    bool m_nowData;
    QList<QVariantMap> m_selectedData;

    int m_seconds;
    QDateTime m_checkDateTime;

    Ui::GraphicWidget *ui;

    QList<QVariantMap> m_data;

    IndicatorType m_indicatorType;
    CommandType::Command m_type;

    QTimer m_replotTimer;

    GraphicWidgetWorker* m_graphicWidgetWorker;
    QThread* m_thread;

    QCPColorMapData* m_colorMapData;
};

#endif // GRAPHICWIDGET_H
