// Local
#include "ShPIndicatorWidget.h"
#include "ui_ShPIndicatorWidget.h"
#include "PaletteWidget.h"

// Qt
#include "qcustomplot.h"

ShPIndicatorWidget::ShPIndicatorWidget(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::ShPIndicatorWidget)
  , m_graphColor(QColor(0,255,0))
{
  ui->setupUi(this);

  connect(ui->paletteComboBox, SIGNAL(activated(int)), ui->paletteWidget, SLOT(setPalette(int)));
  connect(ui->paletteWidget, SIGNAL(colorValue(QColor)), SLOT(colorValue(QColor)));

  // Иконки
  ui->contrastLabel->setPixmap(QIcon(":/icons/contrast.png").pixmap(25, 25));
  ui->brightnessLabel->setPixmap(QIcon(":/icons/sun.png").pixmap(32, 32));
  ui->toolButton_5->setIcon(QIcon::fromTheme("arrow-minimise-icon"));

  connect(ui->brightnessSlider, SIGNAL(valueChanged(int)), SLOT(brightness(int)));

//  ui->customPlot->addGraph();

//  ui->customPlot->setBackground(QBrush(QColor(0, 200, 0)));
//  ui->customPlot->graph(0)->setPen(QPen(Qt::blue)); // line color blue for first graph
//  ui->customPlot->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20))); // first graph will be filled with translucent blue
//  ui->customPlot->addGraph();
//  ui->customPlot->graph(1)->setPen(QPen(Qt::red)); // line color red for second graph
//  // generate some points of data (y0 for first, y1 for second graph):
//  QVector<double> x(251), y0(251), y1(251);
//  for (int i=0; i<251; ++i)
//  {
//    x[i] = i;
//    y0[i] = qExp(-i/150.0)*qCos(i/10.0); // exponentially decaying cosine
//    y1[i] = qExp(-i/150.0);              // exponential envelope
//  }
//  // configure right and top axis to show ticks but no labels:
//  // (see QCPAxisRect::setupFullAxesBox for a quicker method to do this)
//  ui->customPlot->xAxis2->setVisible(true);
//  ui->customPlot->xAxis2->setTickLabels(false);
//  ui->customPlot->yAxis2->setVisible(true);
//  ui->customPlot->yAxis2->setTickLabels(false);
//  // make left and bottom axes always transfer their ranges to right and top axes:
//  connect(ui->customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot->xAxis2, SLOT(setRange(QCPRange)));
//  connect(ui->customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot->yAxis2, SLOT(setRange(QCPRange)));
//  // pass data points to graphs:
//  ui->customPlot->graph(0)->setData(x, y0);
//  ui->customPlot->graph(1)->setData(x, y1);
//  // let the ranges scale themselves so graph 0 fits perfectly in the visible area:
//  ui->customPlot->graph(0)->rescaleAxes();
//  // same thing for graph 1, but only enlarge ranges (in case graph 1 is smaller than graph 0):
//  ui->customPlot->graph(1)->rescaleAxes(true);
//  // Note: we could have also just called customPlot->rescaleAxes(); instead
//  // Allow user to drag axis ranges with mouse, zoom with mouse wheel and select graphs by clicking:
//  ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

  ui->customPlot->addGraph(); // blue line
  ui->customPlot->graph(0)->setPen(QPen(m_graphColor));
  ui->customPlot->addGraph(); // red line
  ui->customPlot->graph(1)->setPen(QPen(m_graphColor));

  QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
  timeTicker->setTimeFormat("%h:%m:%s");
  ui->customPlot->xAxis->setTicker(timeTicker);
  ui->customPlot->axisRect()->setupFullAxesBox();
  ui->customPlot->yAxis->setRange(-1.2, 1.2);

  // make left and bottom axes transfer their ranges to right and top axes:
  connect(ui->customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot->xAxis2, SLOT(setRange(QCPRange)));
  connect(ui->customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot->yAxis2, SLOT(setRange(QCPRange)));

  // setup a timer that repeatedly calls MainWindow::realtimeDataSlot:
  connect(&dataTimer, SIGNAL(timeout()), this, SLOT(realtimeDataSlot()));
  dataTimer.start(0); // Interval 0 means to refresh as fast as possible
}


ShPIndicatorWidget::~ShPIndicatorWidget()
{
  delete ui;
}


void ShPIndicatorWidget::colorValue(const QColor &color)
{
  ui->customPlot->setBackground(QBrush(color));
}


void ShPIndicatorWidget::brightness(int value)
{
  const QColor graphColorLighter = m_graphColor.lighter(value);
  ui->customPlot->graph(0)->setPen(QPen(graphColorLighter));
  ui->customPlot->graph(1)->setPen(QPen(graphColorLighter));
}


void ShPIndicatorWidget::realtimeDataSlot()
{
  static QTime time(QTime::currentTime());
  // calculate two new data points:
  double key = time.elapsed()/1000.0; // time elapsed since start of demo, in seconds
  static double lastPointKey = 0;
  if (key-lastPointKey > 0.002) // at most add point every 2 ms
  {
    // add data to lines:
    ui->customPlot->graph(0)->addData(key, qSin(key)+qrand()/(double)RAND_MAX*1*qSin(key/0.3843));
    ui->customPlot->graph(1)->addData(key, qCos(key)+qrand()/(double)RAND_MAX*0.5*qSin(key/0.4364));
    // rescale value (vertical) axis to fit the current data:
    //ui->customPlot->graph(0)->rescaleValueAxis();
    //ui->customPlot->graph(1)->rescaleValueAxis(true);
    lastPointKey = key;
  }
  // make key axis range scroll with the data (at a constant range size of 8):
  ui->customPlot->xAxis->setRange(key, 8, Qt::AlignRight);
  ui->customPlot->replot();

  // calculate frames per second:
  static double lastFpsKey;
  static int frameCount;
  ++frameCount;
  if (key-lastFpsKey > 2) // average fps over 2 seconds
  {
//    ui->statusBar->showMessage(
//          QString("%1 FPS, Total Data points: %2")
//          .arg(frameCount/(key-lastFpsKey), 0, 'f', 0)
//          .arg(ui->customPlot->graph(0)->data()->size()+ui->customPlot->graph(1)->data()->size())
//        , 0);
    lastFpsKey = key;
    frameCount = 0;
  }
}
