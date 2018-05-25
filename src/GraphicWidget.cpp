// Local
#include "GraphicWidget.h"
#include "ui_GraphicWidget.h"

// Qt
#include <QScrollBar>
#include <QPair>

GraphicWidget::GraphicWidget(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::GraphicWidget)
  , m_graphColor(QColor(0,255,0))
  , m_graphic(nullptr)
{
  ui->setupUi(this);

  m_graphics = QList<AbstractGraphic*>() << ui->graphic_shp1 << ui->graphic_shp2 << ui->graphic_pchss;
}


GraphicWidget::~GraphicWidget()
{
  delete ui;
}


void GraphicWidget::colorValue(const QColor &color)
{
  m_graphColor = color;
  //brightness(ui->brightnessSlider->value());
}


void GraphicWidget::setData(const QList<QVariantMap> &data, const QDateTime& dateTime)
{
  m_data = data;
  m_checkDateTime = dateTime;

  // Обновляем данные не сразу, а по таймеру через каждые 10 секунд
  dataRepaint();
}


void GraphicWidget::setLightMode(const QString& mode)
{
//  if (mode == "sun")
//    ui->customPlot->setBackgroundColor(QColor(180, 180, 180));
//  else if (mode == "night")
//    ui->customPlot->setBackgroundColor(QColor(130, 130, 130));
}


void GraphicWidget::dataRepaint()
{
  if (m_data.isEmpty())
  {
    clearData();
    return;
  }

  m_graphic->replot(m_data, m_checkDateTime);
}


void GraphicWidget::clearData()
{
  if (!m_graphic)
    return;

  m_graphic->clearData();
}


void GraphicWidget::newData()
{
  dataRepaint();
}


void GraphicWidget::setNowData(bool nowData)
{
  m_graphic->setNowData(nowData);
  colorScaleLayout();
  dataRepaint();
}


void GraphicWidget::setDataType(const QString& text, CommandType::Command type)
{
  m_type = type;
  if (type == CommandType::Stream_3)
  {
    ui->graphicWidget->setCurrentIndex(1);
    m_graphic = ui->graphic_shp1;
  }
  else if (type == CommandType::Stream_4)
  {
    ui->graphicWidget->setCurrentIndex(2);
    m_graphic = ui->graphic_shp2;
  }
  else
  {
    ui->graphicWidget->setCurrentIndex(0);
    m_graphic = ui->graphic_pchss;
  }

  m_graphic->setLabel(text);

  dataRepaint();
}


void GraphicWidget::setIndicatorType(AbstractGraphic::IndicatorType indicatorType)
{
  for (auto graphic : m_graphics)
    graphic->setIndicatorType(indicatorType);
}


void GraphicWidget::resizeEvent(QResizeEvent* event)
{
  colorScaleLayout();
  QWidget::resizeEvent(event);
}


void GraphicWidget::on_orientationToolButton_clicked()
{
  dataRepaint();
}


void GraphicWidget::on_toolButtonGrid_toggled(bool checked)
{  

}


void GraphicWidget::on_predIndicatorComboBox_activated(int index)
{
  Q_UNUSED(index);

  //PredIndicatorType predIndicatorType = static_cast<PredIndicatorType>(ui->predIndicatorComboBox->currentData().toInt());
  //m_graphic->replot();
}


void GraphicWidget::colorScaleLayout()
{
//  const int hv = ui->scrollArea->verticalScrollBar()->height();
//  const QMargins m(0, ui->scrollArea->verticalScrollBar()->value(), 0,
//                   (m_nowData ? m_seconds : height()) - ui->scrollArea->verticalScrollBar()->value() - hv);
//  m_colorScale->setMargins(m);
//  ui->graphic->replot();
}


void GraphicWidget::verticalScrollBarValueChanged(int value)
{
  Q_UNUSED(value);
  dataRepaint();
}


void GraphicWidget::verticalScrollBarSliderReleased()
{
  dataRepaint();
}
