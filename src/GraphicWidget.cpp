// Local
#include "GraphicWidget.h"
#include "ui_GraphicWidget.h"
#include "GraphicWidgetWorker.h"

GraphicWidget::GraphicWidget(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::GraphicWidget)
  , m_graphColor(QColor(0,255,0))
  , m_nowData(true)
  , m_seconds(0)
  , m_graphicWidgetWorker(new GraphicWidgetWorker)
  , m_thread(new QThread(this))
  , m_colorMapData(new QCPColorMapData(0,0, QCPRange(0,0), QCPRange(0,0)))
{
  ui->setupUi(this);

  m_thread->start();
  m_graphicWidgetWorker->moveToThread(m_thread);

  connect(m_graphicWidgetWorker, &GraphicWidgetWorker::calculatedData, this, &GraphicWidget::calculatedData, Qt::QueuedConnection);

  // Количество секунд для отображения
  QSettings settings("SAMI_DVO_RAN", "rmo");
  m_seconds = settings.value("SHP/seconds", 60).toInt();

  ui->verticalScrollBar->setRange(0, m_seconds);

  connect(ui->paletteComboBox, SIGNAL(activated(int)), this, SLOT(setGradient(int)));
  //connect(ui->paletteWidget, SIGNAL(colorValue(QColor)), SLOT(colorValue(QColor)));

  // Иконки
  ui->contrastLabel->setPixmap(QIcon(":/icons/contrast.png").pixmap(25, 25));
  ui->brightnessLabel->setPixmap(QIcon(":/icons/sun.png").pixmap(32, 32));
  ui->toolButtonGrid->setIcon(QIcon::fromTheme(":/icons/arrow_close_minimize-20.png"));
  ui->orientationToolButton->setIcon(QIcon(":/icons/inout-32.png"));

  connect(ui->brightnessSlider, SIGNAL(valueChanged(int)), SLOT(brightness(int)));

  // http://www.qcustomplot.com/index.php/demos/colormapdemo
  // configure axis rect:
  ui->graphic->setInteractions(QCP::iSelectAxes|QCP::iRangeDrag); // this will also allow rescaling the color scale by dragging/zooming
  ui->graphic->axisRect()->setupFullAxesBox(true);
  ui->graphic->xAxis->setLabel("");

  //ui->graphic->setLocale(QLocale(QLocale::Russian, QLocale::RussianFederation));
  //QSharedPointer<QCPAxisTickerDateTime> dateTicker(new QCPAxisTickerDateTime);
  //dateTicker->setDateTimeFormat("h.m.s");
  //ui->graphic->yAxis->setTicker(dateTicker);

  m_colorScale = new QCPColorScale(ui->graphic);
  ui->graphic->plotLayout()->addElement(0, 1, m_colorScale); // add it to the right of the main axis rect
  m_colorScale->setType(QCPAxis::atRight); // scale shall be vertical bar with tick/axis labels right (actually atRight is already the default)

  m_colorMap = new QCPColorMap(ui->graphic->xAxis, ui->graphic->yAxis);
  m_colorMap->setColorScale(m_colorScale); // associate the color map with the color scale

  //m_colorMap->setData(m_colorMapData);

  QCPColorGradient gradien;
  QMap<double, QColor> colorStops;
  colorStops[0] = QColor(0, 50, 0);
  colorStops[+1] = QColor(0, 255, 0);
  gradien.setColorStops(colorStops);

  // set the color gradient of the color map to one of the presets:
  m_colorMap->setGradient(gradien);//QCPColorGradient::gpJet);

  m_colorMap->setInterpolate(true);

  // make sure the axis rect and color scale synchronize their bottom and top margins (so they line up):
  //QCPMarginGroup *marginGroup = new QCPMarginGroup(ui->graphic);
  //ui->graphic->axisRect()->setMarginGroup(QCP::msBottom | QCP::msTop, marginGroup);
  //colorScale->setMarginGroup(QCP::msBottom|QCP::msTop, marginGroup);

  const QString style = "background-color: rgb(200,200,200, 20);";
  ui->contrastLabel->setStyleSheet(style);
  ui->brightnessLabel->setStyleSheet(style);

  //QCPAxis* cp = new QCPAxis(ui->graphic->axisRect(0), QCPAxis::atLeft);

  // Подцветка
  setLightMode(settings.value("mode", "sun").toString());

  //ui->graphic->setFixedHeight(m_seconds);

  //QMargins mar(0, 100, 1, 100);
  //m_colorScale->setMargins(mar);

  //QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
  //timeTicker->setTimeFormat("%h:%m");
  //ui->graphic->yAxis->setTicker(timeTicker);
  //ui->graphic->yAxis->setTickLabels(true);

  //connect(&m_replotTimer, SIGNAL(timeout()), SLOT(dataRepaint()));
  //m_replotTimer.start(10000);
  dataRepaint();
}


GraphicWidget::~GraphicWidget()
{
  delete ui;

  m_thread->quit();
  if (!m_thread->wait(5000))
    m_thread->terminate();

  delete m_graphicWidgetWorker;
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

  //dataRepaint();
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
    QCPColorGradient gradien;
    QMap<double, QColor> colorStops;
    colorStops[0] = QColor(0, 50, 0);
    colorStops[+1] = QColor(0, 255, 0);
    gradien.setColorStops(colorStops);

    m_colorMap->setGradient(gradien);
  }
  else
  {
    m_colorMap->setGradient(QCPColorGradient::gpSpectrum);
  }

  ui->graphic->replot();
}


void GraphicWidget::dataRepaint()
{
  //m_colorMap->data()->clear();

  if (m_type == CommandType::Stream_3 || m_type == CommandType::Stream_4)
  {
    ui->graphic->yAxis->setLabel("Т");
    shpRepaint();
  }
  else
  {
    ui->graphic->yAxis->setLabel("Гц");
    pchssRepaint();
  }
}


void GraphicWidget::pchssRepaint()
{
  if (m_data.isEmpty())
    return;

  calculateData(m_data, isNowData(), m_seconds, shiftData(), ui->verticalScrollBar->maximum(), ui->verticalScrollBar->value(), m_checkDateTime);

  /*const int nx = 128;
  const int ny = isNowData() ? m_seconds : 60;//(data.length() - indexBegin) / 128;

  ui->graphic->setBackground(QBrush(Qt::lightGray));

  const int size = isNowData() ? shiftData() : 60;
  const int valueScroll = isNowData() ? (ui->verticalScrollBar->maximum() - ui->verticalScrollBar->value()) : 0;

  // Прединдикаторная обработка
  //! TODO
  //const int predIndicator = ui->predIndicatorComboBox->currentIndex();

  // Убираем миллисекунды
  QDateTime bottomRange = isNowData() ? QDateTime::currentDateTime() : m_checkDateTime.addSecs(60);
  const QTime bottomTime = QTime(bottomRange.time().hour(),
                                 bottomRange.time().minute(),
                                 bottomRange.time().second());
  bottomRange.setTime(bottomTime);



  // Соответствие времени и координаты по оси Y
  QHash<QDateTime, int> timeAxis;
  for (int i = 0; i < ny; ++i)
    timeAxis[bottomRange.addSecs(-i)] = i - valueScroll;
  ui->graphic->yAxis->setRange(valueScroll* 10, valueScroll* 20);

  QCPColorMapData* colorMapData = new QCPColorMapData(nx, size, QCPRange(0, nx), QCPRange(0, ny));
  for (int index = 0; index < m_data.length(); index++)
  {
    const uint timestamp = m_data[index]["timestamp"].toUInt();
    QDateTime dateTime = QDateTime::fromSecsSinceEpoch(timestamp);

    // Обнуляем секунды
    const QTime checkTime = dateTime.time();
    const QTime time(checkTime.hour(), checkTime.minute(), checkTime.second());
    dateTime.setTime(time);
    if (!timeAxis.contains(dateTime))
      continue;

    const int xIndex = m_data[index]["beamCount"].toInt();
    // чтобы не было предупреждения
    if (!(xIndex < nx && timeAxis[dateTime] >= 0 && timeAxis[dateTime] < size))
      continue;

    colorMapData->setCell(xIndex, timeAxis[dateTime], m_data[index]["data"].toDouble());
  }
  m_colorMap->setData(colorMapData);

  // rescale the data dimension (color) such that all data points lie in the span visualized by the color gradient:
  //m_colorMap->rescaleDataRange();

  // rescale the key (x) and value (y) axes so the whole color map is visible:
  ui->graphic->rescaleAxes();

  ui->graphic->yAxis->rescale();
  ui->graphic->replot();*/
}


void GraphicWidget::shpRepaint()
{
  if (m_data.isEmpty())
    return;

  //qDebug() << "111111" << ui->verticalScrollBar->maximum() << ui->verticalScrollBar->value();
  calculateData(m_data, isNowData(), m_seconds, shiftData(), ui->verticalScrollBar->maximum(), ui->verticalScrollBar->value(), m_checkDateTime);

  /*const int nx = 128;
  const int ny = isNowData() ? m_seconds : 60;//(data.length() - indexBegin) / 128;

  ui->graphic->setBackground(QBrush(Qt::lightGray));

  const int size = isNowData() ? shiftData() : 60;
  const int valueScroll = isNowData() ? (ui->verticalScrollBar->maximum() - ui->verticalScrollBar->value()) : 0;

  // Прединдикаторная обработка
  //! TODO
  //const int predIndicator = ui->predIndicatorComboBox->currentIndex();

  // Убираем миллисекунды
  //QDateTime bottomRange = isNowData() ? QDateTime::currentDateTime() : m_checkDateTime.addSecs(60);
  const QDateTime nowTime = QDateTime::fromSecsSinceEpoch(m_data.last()["timestamp"].toUInt()); // Текущее время на оборудовании (может отличаться от времени на РМО)
  QDateTime bottomRange = isNowData() ? nowTime : m_checkDateTime.addSecs(60); // Нижняя граница времени на графике
  const QTime bottomTime = QTime(bottomRange.time().hour(),
                                 bottomRange.time().minute(),
                                 bottomRange.time().second());
  bottomRange.setTime(bottomTime);

  //double nowtime = QDateTime::currentDateTime().toTime_t();
  //ui->graphic->yAxis->setRange(nowtime, nowtime + 60, Qt::AlignLeft);

  // Соответствие времени и координаты по оси Y
  QHash<QDateTime, int> timeAxis;
  for (int i = 0; i < ny; ++i)
    timeAxis[bottomRange.addSecs(-i)] = i - valueScroll;

  QCPColorMapData* colorMapData = new QCPColorMapData(nx, size, QCPRange(0, nx), QCPRange(0, ny));
  for (int index = 0; index < m_data.length(); index++)
  {
    const uint timestamp = m_data[index]["timestamp"].toUInt();
    QDateTime dateTime = QDateTime::fromSecsSinceEpoch(timestamp);

    // Обнуляем секунды
    const QTime checkTime = dateTime.time();
    const QTime time(checkTime.hour(), checkTime.minute(), checkTime.second());
    dateTime.setTime(time);
    if (!timeAxis.contains(dateTime))
      continue;

    const int xIndex = m_data[index]["beamCount"].toInt();
    // чтобы не было предупреждения
    if (!(xIndex < nx && timeAxis[dateTime] >= 0 && timeAxis[dateTime] < size))
      continue;

    colorMapData->setCell(xIndex, timeAxis[dateTime], m_data[index]["data"].toDouble());
  }
  m_colorMap->setData(colorMapData);

  // rescale the data dimension (color) such that all data points lie in the span visualized by the color gradient:
  //m_colorMap->rescaleDataRange();

  // rescale the key (x) and value (y) axes so the whole color map is visible:
  ui->graphic->rescaleAxes();

  ui->graphic->yAxis->rescale();
  ui->graphic->replot();*/
}


void GraphicWidget::calculateData(const QList<QVariantMap>& data, bool isNowData, int seconds, int shiftData,
                   int verticalScrollBarMaximum, int verticalScrollBarValue, const QDateTime& checkDateTime)
{
  QMetaObject::invokeMethod(m_graphicWidgetWorker, "calculateData", Qt::QueuedConnection,
                            Q_ARG(QList<QVariantMap>, data),
                            Q_ARG(bool, isNowData),
                            Q_ARG(int, seconds),
                            Q_ARG(int, shiftData),
                            Q_ARG(int, verticalScrollBarMaximum),
                            Q_ARG(int, verticalScrollBarValue),
                            Q_ARG(QDateTime, checkDateTime));
}



void GraphicWidget::calculatedData(const QHash<QPair<int, int>, double>& result, int keySize, int valueSize, int yRange)
{
  //QCPColorMapData* colorMapData = new QCPColorMapData(keySize, valueSize, QCPRange(0, keySize), QCPRange(0, yRange));

  m_colorMap->data()->setSize(keySize, valueSize);
  m_colorMap->data()->setRange(QCPRange(0, keySize), QCPRange(0, yRange));
  QHashIterator<QPair<int, int>, double> iter(result);
  while (iter.hasNext())
  {
    iter.next();
    m_colorMap->data()->setCell(iter.key().first, iter.key().second, iter.value());
  }

//  m_colorMapData->setKeySize(keySize);
//  m_colorMapData->setValueSize(valueSize);
//  m_colorMapData->setRange(QCPRange(0, keySize), QCPRange(0, yRange));
//  QHashIterator<QPair<int, int>, double> iter(result);
//  while (iter.hasNext())
//  {
//    iter.next();
//    m_colorMapData->setCell(iter.key().first, iter.key().second, iter.value());
//  }
  //m_colorMap->setData(m_colorMapData);

  // rescale the data dimension (color) such that all data points lie in the span visualized by the color gradient:
  //m_colorMap->rescaleDataRange();

  // rescale the key (x) and value (y) axes so the whole color map is visible:
  ui->graphic->rescaleAxes();

  ui->graphic->yAxis->rescale();
  ui->graphic->replot();
}


int GraphicWidget::shiftData() const
{
  //! TODO: делить на 4 или на сколько вообще!
  return m_seconds / 4;
}


void GraphicWidget::newData()
{
  dataRepaint();
}


void GraphicWidget::setNowData(bool nowData)
{
  m_nowData = nowData;
  ui->verticalScrollBar->setRange(0, nowData ? m_seconds : 1);
  ui->verticalScrollBar->setMaximum(isNowData() ? m_seconds - shiftData() : 60);
  ui->verticalScrollBar->setValue(ui->verticalScrollBar->maximum());
  ui->verticalScrollBar->setVisible(nowData);
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
  ui->graphic->xAxis->setLabel(text);
  ui->graphic->replot();
  dataRepaint();
}


void GraphicWidget::resizeEvent(QResizeEvent* event)
{
  colorScaleLayout();
  ui->verticalScrollBar->setMaximum(isNowData() ? m_seconds - shiftData() : 60);
  ui->verticalScrollBar->setValue(ui->verticalScrollBar->maximum());
  QWidget::resizeEvent(event);
}


void GraphicWidget::on_orientationToolButton_clicked()
{
  //ui->customPlot->setOrientation(!ui->customPlot->orientation());
}


void GraphicWidget::on_toolButtonGrid_toggled(bool checked)
{
  ui->graphic->xAxis->grid()->setVisible(checked);
  ui->graphic->yAxis->grid()->setVisible(checked);
}


void GraphicWidget::on_predIndicatorComboBox_activated(int index)
{
  Q_UNUSED(index);

  PredIndicatorType predIndicatorType = static_cast<PredIndicatorType>(ui->predIndicatorComboBox->currentData().toInt());
  ui->graphic->replot();
}


void GraphicWidget::colorScaleLayout()
{
//  const int hv = ui->scrollArea->verticalScrollBar()->height();
//  const QMargins m(0, ui->scrollArea->verticalScrollBar()->value(), 0,
//                   (m_nowData ? m_seconds : height()) - ui->scrollArea->verticalScrollBar()->value() - hv);
//  m_colorScale->setMargins(m);
//  ui->graphic->replot();
}

void GraphicWidget::on_verticalScrollBar_valueChanged(int value)
{
  Q_UNUSED(value);
  dataRepaint();
}
