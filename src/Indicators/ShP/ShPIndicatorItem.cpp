// Local
#include "ShPIndicatorItem.h"
#include "ui_ShPIndicatorItem.h"
#include "ShPIndicatorWidget.h"

// Qt
#include <QSplitter>

ShPIndicatorItem::ShPIndicatorItem(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::ShPIndicatorItem)
  , m_upWidget(new ShPIndicatorWidget(this))
  , m_downWidget(nullptr)
{
  ui->setupUi(this);

  m_upWidget->setHasSwitch(true);
  ui->splitter->addWidget(m_upWidget);
  connect(m_upWidget, SIGNAL(countWidget()), SLOT(countWidget()));


  //
  ui->graphic->addGraph(); // blue line
  ui->graphic->graph(0)->setPen(QPen(QColor(40, 110, 255)));
  QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
  timeTicker->setTimeFormat("%h:%m:%s");
  ui->graphic->xAxis->setTicker(timeTicker);
  ui->graphic->axisRect()->setupFullAxesBox();
  ui->graphic->yAxis->setRange(-1.2, 1.2);
}


ShPIndicatorItem::~ShPIndicatorItem()
{
  delete ui;
}


void ShPIndicatorItem::setLightMode(const QString& mode)
{
  m_upWidget->setLightMode(mode);
  if (m_downWidget)
    m_downWidget->setLightMode(mode);

  if (mode == "sun")
    ui->graphic->setBackground(QBrush(QColor(180, 180, 180)));
  else if (mode == "night")
    ui->graphic->setBackground(QBrush(QColor(130, 130, 130)));
}


void ShPIndicatorItem::insertDownWidget()
{
  Q_ASSERT(!m_downWidget);

  m_downWidget = new ShPIndicatorWidget(this);
  m_downWidget->setCurrentPgasNumber(m_upWidget->currentPgasNumber());

  ui->splitter->addWidget(m_downWidget);
}


void ShPIndicatorItem::deleteDownWidget()
{
  Q_ASSERT(m_downWidget);

  delete m_downWidget;
  m_downWidget = nullptr;
}


void ShPIndicatorItem::countWidget()
{
  if (m_downWidget)
    deleteDownWidget();
  else
    insertDownWidget();
}


void ShPIndicatorItem::newData()
{
  m_upWidget->newData();
  if (m_downWidget)
    m_downWidget->newData();

  return;
  // calculate two new data points:
  static double key = 1; // time elapsed since start of demo, in seconds
  key += 20;
  static double lastPointKey = 0;
  if (key-lastPointKey > 0.002) // at most add point every 2 ms
  {
    // add data to lines:
    ui->graphic->graph(0)->addData(key, qSin(key)+qrand()/(double)RAND_MAX*1*qSin(key/0.3843));
    // rescale value (vertical) axis to fit the current data:
    //ui->customPlot->graph(0)->rescaleValueAxis();
    //ui->customPlot->graph(1)->rescaleValueAxis(true);
    lastPointKey = key;
  }
  // make key axis range scroll with the data (at a constant range size of 8):
  ui->graphic->xAxis->setRange(key, 8, Qt::AlignRight);
  ui->graphic->replot();

  // calculate frames per second:
  static double lastFpsKey;
  static int frameCount;
  ++frameCount;
  if (key-lastFpsKey > 2) // average fps over 2 seconds
  {
    lastFpsKey = key;
    frameCount = 0;
  }
}


void ShPIndicatorItem::setCurrentPgasNumber(int pgasNumber)
{
  m_upWidget->setCurrentPgasNumber(pgasNumber);
  if (m_downWidget)
    m_downWidget->setCurrentPgasNumber(pgasNumber);
}


void ShPIndicatorItem::setNowData(bool nowData)
{
  m_upWidget->setNowData(nowData);
  if (m_downWidget)
    m_downWidget->setNowData(nowData);
}


void ShPIndicatorItem::setSelectedData(const PgasData& selectedData, const QDateTime& checkDateTime)
{
  m_upWidget->setSelectedData(selectedData, checkDateTime);
  if (m_downWidget)
    m_downWidget->setSelectedData(selectedData, checkDateTime);
}
