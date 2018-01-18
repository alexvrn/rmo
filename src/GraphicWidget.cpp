// Local
#include "GraphicWidget.h"
#include "ui_GraphicWidget.h"

GraphicWidget::GraphicWidget(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::GraphicWidget)
  , m_graphColor(QColor(0,255,0))
  , m_nowData(true)
  , m_seconds(0)
{
  ui->setupUi(this);

  // Количество секунд для отображения
  QSettings settings("SAMI_DVO_RAN", "rmo");
  m_seconds = settings.value("SHP/seconds", 60).toInt();

  ui->scrollArea->verticalScrollBar()->setSliderDown(true);

  connect(ui->scrollArea->verticalScrollBar(), SIGNAL(valueChanged(int)), SLOT(colorScaleLayout()));

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
  ui->graphic->yAxis->setLabel("T");


  //ui->graphic->setLocale(QLocale(QLocale::Russian, QLocale::RussianFederation));
  //QSharedPointer<QCPAxisTickerDateTime> dateTicker(new QCPAxisTickerDateTime);
  //dateTicker->setDateTimeFormat("h.m.s");
  //ui->graphic->yAxis->setTicker(dateTicker);

  ui->graphic->yAxis->setRangeUpper(50);

  // set up the QCPColorMap:
  m_colorMap = new QCPColorMap(ui->graphic->xAxis, ui->graphic->yAxis);

  // add a color scale:
  m_colorScale = new QCPColorScale(ui->graphic);
  ui->graphic->plotLayout()->addElement(0, 1, m_colorScale); // add it to the right of the main axis rect
  m_colorScale->setType(QCPAxis::atRight); // scale shall be vertical bar with tick/axis labels right (actually atRight is already the default)
  m_colorMap->setColorScale(m_colorScale); // associate the color map with the color scale
  //colorScale->axis()->setLabel("Magnetic Field Strength");
  QCPColorGradient gradien;
  QMap<double, QColor> colorStops;
  colorStops[0] = QColor(0, 50, 0);
  colorStops[+1] = QColor(0, 255, 0);
  gradien.setColorStops(colorStops);

  // set the color gradient of the color map to one of the presets:
  m_colorMap->setGradient(gradien);//QCPColorGradient::gpJet);
  // we could have also created a QCPColorGradient instance and added own colors to
  // the gradient, see the documentation of QCPColorGradient for what's possible.

  // make sure the axis rect and color scale synchronize their bottom and top margins (so they line up):
  //QCPMarginGroup *marginGroup = new QCPMarginGroup(ui->graphic);
  //ui->graphic->axisRect()->setMarginGroup(QCP::msBottom | QCP::msTop, marginGroup);
  //colorScale->setMarginGroup(QCP::msBottom|QCP::msTop, marginGroup);

  const QString style = "background-color: rgb(200,200,200, 20);";
  //ui->labelX->setStyleSheet(style);
  //ui->labelY->setStyleSheet(style);
  //ui->typeLabel->setStyleSheet(style);
  ui->contrastLabel->setStyleSheet(style);
  ui->brightnessLabel->setStyleSheet(style);

  // Подцветка
  setLightMode(settings.value("mode", "sun").toString());

  ui->graphic->setFixedHeight(m_seconds);

  QMargins mar(0, 100, 1, 100);
  m_colorScale->setMargins(mar);

  dataRepaint();
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
  m_colorMap->data()->clear();

  int nx = 128;
  int ny = isNowData() ? m_seconds : 60;//(data.length() - indexBegin) / 128;

  ui->graphic->setBackground(QBrush(Qt::lightGray));

  m_colorMap->data()->setSize(nx, ny); // we want the color map to have nx * ny data points
  m_colorMap->data()->setRange(QCPRange(0, nx), QCPRange(0, ny)); // and span the coordinate range -4..4 in both key (x) and value (y) dimensions

  // Прединдикаторная обработка
  //! TODO
  const int predIndicator = ui->predIndicatorComboBox->currentIndex();

  QHash<QDateTime, int> timeAxis;
  // Убираем миллисекунды
  QDateTime bottomRange = isNowData() ? QDateTime::currentDateTime() : m_checkDateTime.addSecs(60);
  const QTime bottomTime = QTime(bottomRange.time().hour(),
                                 bottomRange.time().minute(),
                                 bottomRange.time().second());
  bottomRange.setTime(bottomTime);

  for (int i = 0; i < ny; ++i)
    timeAxis[bottomRange.addSecs(-i)] = i;

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
    m_colorMap->data()->setCell(xIndex, timeAxis[dateTime], m_data[index]["data"].toDouble());
  }



  // rescale the data dimension (color) such that all data points lie in the span visualized by the color gradient:
  //m_colorMap->rescaleDataRange();

  // rescale the key (x) and value (y) axes so the whole color map is visible:
  ui->graphic->rescaleAxes();

  ui->graphic->replot();
}


void GraphicWidget::newData()
{
  dataRepaint();
}


void GraphicWidget::setNowData(bool nowData)
{
  m_nowData = nowData;
  ui->graphic->setMinimumHeight(nowData ? m_seconds : 0);

  colorScaleLayout();
  dataRepaint();
}


bool GraphicWidget::isNowData() const
{
  return m_nowData;
}


void GraphicWidget::setAxisText(const QString& text)
{
  ui->graphic->xAxis->setLabel(text);
  ui->graphic->replot();
}


void GraphicWidget::resizeEvent(QResizeEvent* event)
{
  colorScaleLayout();
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
  qDebug() << predIndicatorType;
  ui->graphic->replot();
}


void GraphicWidget::colorScaleLayout()
{
  const int hv = ui->scrollArea->verticalScrollBar()->height();
  const QMargins m(0, ui->scrollArea->verticalScrollBar()->value(), 0,
                   (m_nowData ? m_seconds : height()) - ui->scrollArea->verticalScrollBar()->value() - hv);
  m_colorScale->setMargins(m);
  ui->graphic->replot();
}
