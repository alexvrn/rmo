// Local
#include "GraphicTime.h"
#include "ui_GraphicTime.h"

GraphicTime::GraphicTime(QWidget *parent)
 : QWidget(parent), AbstractGraphic()
 , ui(new Ui::GraphicTime)
 , m_thread(new QThread(this))
 , m_worker(new GraphicTimeWorker())
 , m_graphColor(QColor(0,255,0))
 , m_nowData(true)
 , m_seconds(0)
{
  ui->setupUi(this);

  m_thread->start();
  m_worker->moveToThread(m_thread);

  //! FIXME: проверка количества секунд
  // Количество секунд для отображения
  QSettings settings("SAMI_DVO_RAN", "rmo");
  m_seconds = settings.value("SHP/seconds", 60).toInt();

  connect(m_worker, &GraphicTimeWorker::calculatedData, this, &GraphicTime::calculatedData, Qt::QueuedConnection);

  // http://www.qcustomplot.com/index.php/demos/colormapdemo
  // configure axis rect:
  ui->graphic->setInteractions(QCP::iSelectAxes|QCP::iRangeDrag); // this will also allow rescaling the color scale by dragging/zooming
  ui->graphic->axisRect()->setupFullAxesBox(true);
  ui->graphic->xAxis->setLabel("");

  // Обработка перемещения мыши
  connect(ui->graphic, SIGNAL(mouseMove(QMouseEvent*)), this, SLOT(mouseMove(QMouseEvent*)));
  connect(ui->graphic, SIGNAL(mousePress(QMouseEvent*)), this, SLOT(mousePress(QMouseEvent*)));

  // Шкала
  m_colorScale = new QCPColorScale(ui->graphic);
  ui->graphic->plotLayout()->addElement(0, 1, m_colorScale); // add it to the right of the main axis rect
  m_colorScale->setType(QCPAxis::atRight); // scale shall be vertical bar with tick/axis labels right (actually atRight is already the default)

  ui->graphic->yAxis->setRangeReversed(true);

  // Координата времени
  QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
  ui->graphic->yAxis->setTicker(timeTicker);
  //ui->graphic->axisRect()->setupFullAxesBox();
  timeTicker->setTimeFormat("%h:%m:%s");

  ui->verticalScrollBar->setRange(0, m_seconds);
  connect(ui->verticalScrollBar, SIGNAL(sliderReleased()), this, SLOT(verticalScrollBarSliderReleased()));
  connect(ui->verticalScrollBar, SIGNAL(valueChanged(int)), this, SLOT(verticalScrollBarValueChanged(int)));

  //! Магическое число second - shift - для правильного отображения
  ui->verticalScrollBar->setMaximum(m_seconds - shiftData());
  ui->verticalScrollBar->setValue(ui->verticalScrollBar->maximum());

  m_colorMap = new CPColorMap(ui->graphic->xAxis, ui->graphic->yAxis);
  m_colorMap->setColorScale(m_colorScale); // associate the color map with the color scale

  QCPColorGradient gradien;
  QMap<double, QColor> colorStops;
  colorStops[0] = QColor(0, 50, 0);
  colorStops[+1] = QColor(0, 255, 0);
  gradien.setColorStops(colorStops);

  // set the color gradient of the color map to one of the presets:
  m_colorMap->setGradient(gradien);//QCPColorGradient::gpJet);

  m_colorMap->setInterpolate(true);

  ui->graphic->xAxis->setLabel("");
  ui->graphic->yAxis->setLabel("Т");

  // make sure the axis rect and color scale synchronize their bottom and top margins (so they line up):
  //QCPMarginGroup *marginGroup = new QCPMarginGroup(ui->graphic);
  //ui->graphic->axisRect()->setMarginGroup(QCP::msBottom | QCP::msTop, marginGroup);
  //colorScale->setMarginGroup(QCP::msBottom|QCP::msTop, marginGroup);

  connect(ui->paletteComboBox, SIGNAL(activated(int)), this, SLOT(onPalette(int)));
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
  //setLightMode(settings.value("mode", "sun").toString());
}


GraphicTime::~GraphicTime()
{
  delete ui;

  m_thread->quit();
  if (!m_thread->wait(5000))
    m_thread->terminate();

  delete m_worker;
}


void GraphicTime::clearData()
{
  m_colorMap->data()->clear();
  m_colorMap->data()->setSize(128, 60);
  m_colorMap->data()->setRange(QCPRange(0, 128), QCPRange(0, 60));
  // rescale the data dimension (color) such that all data points lie in the span visualized by the color gradient:
  //m_colorMap->rescaleDataRange();

  // rescale the key (x) and value (y) axes so the whole color map is visible:
  ui->graphic->rescaleAxes();

  ui->graphic->yAxis->rescale();
  ui->graphic->replot();
}


void GraphicTime::setGradient(const QCPColorGradient& gradient)
{
  m_colorMap->setGradient(gradient);
  ui->graphic->replot();
}


void GraphicTime::onPalette(int value)
{
  if (value == 0)
  {
    QCPColorGradient gradient;
    QMap<double, QColor> colorStops;
    colorStops[0] = QColor(0, 50, 0);
    colorStops[+1] = QColor(0, 255, 0);
    gradient.setColorStops(colorStops);

    setGradient(gradient);
  }
  else
  {
    setGradient(QCPColorGradient::gpSpectrum);
  }
}


void GraphicTime::setLabel(const QString& text)
{
  ui->graphic->xAxis->setLabel(text);
}


void GraphicTime::replot(const QList<QVariantMap>& data, const QDateTime& dateTime)
{
  m_data = data;
  m_checkDateTime = dateTime;

  QMetaObject::invokeMethod(m_worker, "calculateData", Qt::QueuedConnection,
                            Q_ARG(QList<QVariantMap>, data),
                            Q_ARG(bool, isNowData()),
                            Q_ARG(int, m_seconds),
                            Q_ARG(int, shiftData()),
                            Q_ARG(int, ui->verticalScrollBar->maximum()),
                            Q_ARG(int, ui->verticalScrollBar->value()),
                            Q_ARG(QDateTime, m_checkDateTime),
                            Q_ARG(bool, ui->graphic->yAxis->rangeReversed()));
}


//void GraphicWidget::colorValue(const QColor &color)
//{
//  m_graphColor = color;
//  brightness(ui->brightnessSlider->value());
//}


//void GraphicWidget::brightness(int value)
//{
//  const QColor graphColorLighter = m_graphColor.lighter(value);
//  //ui->customPlot->graph(0)->setPen(QPen(graphColorLighter));
//  //ui->customPlot->graph(1)->setPen(QPen(graphColorLighter));
//}


//void GraphicWidget::setLightMode(const QString& mode)
//{
//  if (mode == "sun")
//    ui->customPlot->setBackgroundColor(QColor(180, 180, 180));
//  else if (mode == "night")
//    ui->customPlot->setBackgroundColor(QColor(130, 130, 130));
//}


void GraphicTime::setIndicatorType(IndicatorType indicatorType)
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


void GraphicTime::calculatedData(const QHash<QPair<int, int>, double>& result, int keySize, int valueSize, int yRange,
                                 const QDateTime& bottomRange, int verticalScrollBarValue)
{
  m_colorMap->data()->clear();
  m_colorMap->data()->setSize(keySize, valueSize);
  const int secs = bottomRange.time().msecsSinceStartOfDay() / 1000.0;
  m_colorMap->data()->setRange(QCPRange(0, keySize), QCPRange(secs + verticalScrollBarValue,
                                                              secs + valueSize + verticalScrollBarValue));
  QHashIterator<QPair<int, int>, double> iter(result);
  while (iter.hasNext())
  {
    iter.next();
    m_colorMap->data()->setCell(iter.key().first, iter.key().second, iter.value());
  }

  // rescale the data dimension (color) such that all data points lie in the span visualized by the color gradient:
  //m_colorMap->rescaleDataRange();

  // rescale the key (x) and value (y) axes so the whole color map is visible:
  ui->graphic->rescaleAxes();

  ui->graphic->yAxis->rescale();
  ui->graphic->replot();
}


void GraphicTime::setNowData(bool nowData)
{
  m_nowData = nowData;
  ui->verticalScrollBar->setRange(0, nowData ? m_seconds : 1);
  scrollMinMax();
  ui->verticalScrollBar->setVisible(nowData);
  //dataRepaint();
}


bool GraphicTime::isNowData() const
{
  return m_nowData;
}


void GraphicTime::scrollMinMax()
{
  //! Магическое число second - shift - для правильного отображения
  ui->verticalScrollBar->setMaximum(isNowData() ? m_seconds - shiftData() : 60);
  ui->verticalScrollBar->setValue(ui->graphic->yAxis->rangeReversed() ? ui->verticalScrollBar->maximum() : 0);
}


int GraphicTime::shiftData() const
{
  //! TODO: делить на 4 или на сколько вообще!
  return m_seconds / 4;
}


void GraphicTime::on_orientationToolButton_clicked()
{
  ui->graphic->yAxis->setRangeReversed(!ui->graphic->yAxis->rangeReversed());
  scrollMinMax();
  replot();
}


void GraphicTime::on_toolButtonGrid_toggled(bool checked)
{
  ui->graphic->xAxis->grid()->setVisible(checked);
  ui->graphic->yAxis->grid()->setVisible(checked);
}


void GraphicTime::on_predIndicatorComboBox_activated(int index)
{
  Q_UNUSED(index);

  PredIndicatorType predIndicatorType = static_cast<PredIndicatorType>(ui->predIndicatorComboBox->currentData().toInt());
  replot();
}


void GraphicTime::verticalScrollBarValueChanged(int value)
{
  Q_UNUSED(value);

  replot();
}


void GraphicTime::verticalScrollBarSliderReleased()
{
  replot();
}


void GraphicTime::brightness(int value)
{

}


void GraphicTime::replot()
{
  replot(m_data);
}


void GraphicTime::mouseMove(QMouseEvent* event)
{

}


void GraphicTime::mousePress(QMouseEvent* event)
{
  const int x = ui->graphic->xAxis->pixelToCoord(event->pos().x());
  const int y = ui->graphic->yAxis->pixelToCoord(event->pos().y());

  // Проверяем чтобы клик был только по обрасти графика
  if (!m_colorMap->data()->keyRange().contains(x) || m_colorMap->data()->keyRange().contains(y))
    return;

  m_colorMap->setPoint(QPoint(x, y));
  ui->graphic->replot();
}

