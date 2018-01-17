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
    void setData(const QList<QVariantMap>& data);
    void setLightMode(const QString& mode);
    void newData();
    void setNowData(bool nowData);
    bool isNowData() const;
    void setSelectedData(const QList<QVariantMap>& selectedData, const QDateTime& checkDateTime = QDateTime());
    void setAxisText(const QString& text);

  private slots:
    void colorValue(const QColor &color);
    void brightness(int value);
    void setGradient(int value);

    void vertScrollBarChanged(int value);
    void yAxisChanged(QCPRange range);

    void on_toolButtonGrid_toggled(bool checked);
    void on_orientationToolButton_clicked();
    void on_predIndicatorComboBox_activated(int index);

  private:
    void dataRepaint();

    Graphic* m_graphic;

    QColor m_graphColor;

    QList<QToolButton*> m_toolButtons;

    QCPColorMap *m_colorMap;

    bool m_nowData;
    QList<QVariantMap> m_selectedData;

    int m_seconds;
    QDateTime m_checkDateTime;

  private:
    Ui::GraphicWidget *ui;

    QList<QVariantMap> m_data;

    IndicatorType m_indicatorType;
};

#endif // GRAPHICWIDGET_H
