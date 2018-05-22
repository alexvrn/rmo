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
  , m_nowData(true)
  , m_seconds(0)
  , m_scrollBar(nullptr)
  , m_graphic(nullptr)
{
  ui->setupUi(this);

  //! FIXME: проверка количества секунд
  // Количество секунд для отображения
  QSettings settings("SAMI_DVO_RAN", "rmo");
  m_seconds = settings.value("SHP/seconds", 60).toInt();

  m_widgetPage[0] = qMakePair(ui->graphicShP1, ui->verticalScrollBarShP1);
  m_widgetPage[1] = qMakePair(ui->graphicShP2, ui->verticalScrollBarShP2);
  m_widgetPage[2] = qMakePair(ui->graphicPChSS, ui->verticalScrollBarPChSS);

  auto it = m_widgetPage.begin();
  while (it != m_widgetPage.end())
  {
    auto scroll = it.value().second;
    scroll->setRange(0, m_seconds);
    connect(scroll, SIGNAL(sliderReleased()), this, SLOT(verticalScrollBarSliderReleased()));
    connect(scroll, SIGNAL(valueChanged(int)), this, SLOT(verticalScrollBarValueChanged(int)));

    //! Магическое число second - shift - для правильного отображения
    scroll->setMaximum(m_seconds - shiftData());
    scroll->setValue(scroll->maximum());
    ++it;
  }

  connect(ui->paletteComboBox, SIGNAL(activated(int)), this, SLOT(setGradient(int)));
  //connect(ui->paletteWidget, SIGNAL(colorValue(QColor)), SLOT(colorValue(QColor)));

  // Иконки
  ui->contrastLabel->setPixmap(QIcon(":/icons/contrast.png").pixmap(25, 25));
  ui->brightnessLabel->setPixmap(QIcon(":/icons/sun.png").pixmap(32, 32));
  ui->toolButtonGrid->setIcon(QIcon::fromTheme(":/icons/arrow_close_minimize-20.png"));
  ui->orientationToolButton->setIcon(QIcon(":/icons/inout-32.png"));

  connect(ui->brightnessSlider, SIGNAL(valueChanged(int)), SLOT(brightness(int)));

  const QString style = "background-color: rgb(200,200,200, 20);";
  ui->contrastLabel->setStyleSheet(style);
  ui->brightnessLabel->setStyleSheet(style);

  // Подцветка
  setLightMode(settings.value("mode", "sun").toString());
}


GraphicWidget::~GraphicWidget()
{
  delete ui;
}


void GraphicWidget::setType(IndicatorType indicatorType)
{
  m_indicatorType = indicatorType;

  // Обновляем список вариантов прединдикаторной обработки
  ui->predIndicatorComboBox->clear();

  if (indicatorType == IndicatorType::ShP)
  {
    ui->predIndicatorComboBox->addItem(tr("Логарифм"), PredIndicatorType::Logarithm);
    ui->predIndicatorComboBox->addItem(tr("Линейная"), PredIndicatorType::Linear);
    ui->predIndicatorComboBox->addItem(tr("Логарифм"), PredIndicatorType::Marker);
    ui->predIndicatorComboBox->addItem(tr("Пороговая"), PredIndicatorType::Threshold);
    ui->predIndicatorComboBox->addItem(tr("Логарифм"), PredIndicatorType::GL_Reverberation);
    ui->predIndicatorComboBox->addItem(tr("Логарифм"), PredIndicatorType::GL_Noise);
  }
  else if (indicatorType == IndicatorType::SA)
  {
    ui->predIndicatorComboBox->addItem(tr("Логарифм"), PredIndicatorType::Logarithm);
    ui->predIndicatorComboBox->addItem(tr("Псевдо-линейная"), PredIndicatorType::PseudoLinear);
  }
}


void GraphicWidget::colorValue(const QColor &color)
{
  m_graphColor = color;
  brightness(ui->brightnessSlider->value());
}


void GraphicWidget::brightness(int value)
{
  const QColor graphColorLighter = m_graphColor.lighter(value);
  //ui->customPlot->graph(0)->setPen(QPen(graphColorLighter));
  //ui->customPlot->graph(1)->setPen(QPen(graphColorLighter));
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


void GraphicWidget::setGradient(int value)
{
  if (value == 0)
  {
    QCPColorGradient gradient;
    QMap<double, QColor> colorStops;
    colorStops[0] = QColor(0, 50, 0);
    colorStops[+1] = QColor(0, 255, 0);
    gradient.setColorStops(colorStops);

    m_graphic->setGradient(gradient);
  }
  else
  {
    m_graphic->setGradient(QCPColorGradient::gpSpectrum);
  }

  m_graphic->replot();
}


void GraphicWidget::dataRepaint()
{
  if (m_data.isEmpty())
  {
    clearData();
    return;
  }

  if (m_type == CommandType::Stream_3 || m_type == CommandType::Stream_4)
  {
    qobject_cast<GraphicShP*>(m_graphic)->calculateData(
                    m_data, isNowData(), m_seconds, shiftData(),
                    m_scrollBar->maximum(),
                    m_scrollBar->value(), m_checkDateTime, m_graphic->yAxis->rangeReversed());

  }
  else
  {
    //qobject_cast<GraphicPChSS*>(m_graphic)->calculateData(
    //                m_data, isNowData(), m_seconds, shiftData(),
    //                ui->verticalScrollBarShP->maximum(),
    //                ui->verticalScrollBarShP->value(), m_checkDateTime, m_graphic->yAxis->rangeReversed());
  }
}


int GraphicWidget::shiftData() const
{
  //! TODO: делить на 4 или на сколько вообще!
  return m_seconds / 4;
}


void GraphicWidget::scrollMinMax()
{
  if (!m_scrollBar)
    return;

  //! Магическое число second - shift - для правильного отображения
  m_scrollBar->setMaximum(isNowData() ? m_seconds - shiftData() : 60);
  m_scrollBar->setValue(m_graphic->yAxis->rangeReversed() ? m_scrollBar->maximum() : 0);
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
  m_nowData = nowData;
  m_scrollBar->setRange(0, nowData ? m_seconds : 1);
  scrollMinMax();
  m_scrollBar->setVisible(nowData);
  colorScaleLayout();
  dataRepaint();
}


bool GraphicWidget::isNowData() const
{
  return m_nowData;
}


void GraphicWidget::setDataType(const QString& text, CommandType::Command type)
{
  m_type = type;
  if (type == CommandType::Stream_3)
  {
    ui->graphicWidget->setCurrentIndex(1);
    m_graphic = ui->graphicShP1;
    m_scrollBar = ui->verticalScrollBarShP1;
  }
  else if (type == CommandType::Stream_4)
  {
    ui->graphicWidget->setCurrentIndex(2);
    m_graphic = ui->graphicShP2;
    m_scrollBar = ui->verticalScrollBarShP2;
  }
  else
  {
    ui->graphicWidget->setCurrentIndex(0);
    m_graphic = ui->graphicPChSS;
    m_scrollBar = ui->verticalScrollBarPChSS;
  }

  m_graphic->xAxis->setLabel(text);

  dataRepaint();
}


void GraphicWidget::resizeEvent(QResizeEvent* event)
{
  colorScaleLayout();
  scrollMinMax();
  QWidget::resizeEvent(event);
}


void GraphicWidget::on_orientationToolButton_clicked()
{
  auto it = m_widgetPage.begin();
  while (it != m_widgetPage.end())
  {
    auto scroll = it.value().second;
    auto graphic = it.value().first;

    graphic->yAxis->setRangeReversed(!graphic->yAxis->rangeReversed());
    scroll->setValue(graphic->yAxis->rangeReversed() ? scroll->maximum() : 0);
    ++it;
  }

  dataRepaint();
}


void GraphicWidget::on_toolButtonGrid_toggled(bool checked)
{  
  m_graphic->xAxis->grid()->setVisible(checked);
  m_graphic->yAxis->grid()->setVisible(checked);
}


void GraphicWidget::on_predIndicatorComboBox_activated(int index)
{
  Q_UNUSED(index);

  PredIndicatorType predIndicatorType = static_cast<PredIndicatorType>(ui->predIndicatorComboBox->currentData().toInt());
  m_graphic->replot();
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
