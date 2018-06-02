#ifndef GRAPHICWIDGET_H
#define GRAPHICWIDGET_H

// Qt
#include <QWidget>
#include <QTimer>
#include <QVariantMap>
#include <QString>
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

  public slots:
    void setData(const QList<QVariantMap>& data, const QDateTime& dateTime = QDateTime());
    void setLightMode(const QString& mode);
    void newData();
    void setNowData(bool nowData);
    void setDataType(const QString& text, CommandType::Command type);
    void setIndicatorType(AbstractGraphic::IndicatorType indicatorType);

    void resizeEvent(QResizeEvent* event);

  private slots:
    void colorValue(const QColor &color);

    void on_toolButtonGrid_toggled(bool checked);
    void on_orientationToolButton_clicked();
    void on_predIndicatorComboBox_activated(int index);

    void colorScaleLayout();

    void verticalScrollBarSliderReleased();
    void verticalScrollBarValueChanged(int value);

    void dataRepaint();

  signals:
    void info(const QString& text);

  private:
    void clearData();

    Ui::GraphicWidget *ui;

    QColor m_graphColor;

    QList<QToolButton*> m_toolButtons;

    QDateTime m_checkDateTime;

    QList<QVariantMap> m_data;

    AbstractGraphic::IndicatorType m_indicatorType;
    CommandType::Command m_type;

    // Текущий график
    AbstractGraphic* m_graphic;

    QList<AbstractGraphic*> m_graphics;
};

#endif // GRAPHICWIDGET_H
