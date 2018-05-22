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
#include "AbstractGraphic.h"


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

  private slots:
    void colorValue(const QColor &color);
    void brightness(int value);
    void setGradient(int value);

    void on_toolButtonGrid_toggled(bool checked);
    void on_orientationToolButton_clicked();
    void on_predIndicatorComboBox_activated(int index);

    void colorScaleLayout();

    void verticalScrollBarSliderReleased();
    void verticalScrollBarValueChanged(int value);

    void dataRepaint();

private:
    int shiftData() const;
    void clearData();
    void scrollMinMax();

    Ui::GraphicWidget *ui;

    QColor m_graphColor;

    QList<QToolButton*> m_toolButtons;

    bool m_nowData;

    int m_seconds;
    QDateTime m_checkDateTime;

    QList<QVariantMap> m_data;

    IndicatorType m_indicatorType;
    CommandType::Command m_type;

    QScrollBar* m_scrollBar;
    AbstractGraphic* m_graphic;

    QMap<int, QPair<AbstractGraphic*, QScrollBar*> > m_widgetPage;
    QList<QScrollBar*> m_scrolls;
    QList<AbstractGraphic*> m_graphics;
};

#endif // GRAPHICWIDGET_H
