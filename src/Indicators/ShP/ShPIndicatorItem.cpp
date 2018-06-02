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

  connect(m_upWidget, &ShPIndicatorWidget::info, this, &ShPIndicatorItem::info);

  m_upWidget->setHasSwitch(true);
  ui->splitter->addWidget(m_upWidget);
  connect(m_upWidget, SIGNAL(countWidget()), SLOT(countWidget()));


  //
  auto graphic = ui->graphic->addGraph();
  graphic->setPen(QPen(QColor(40, 110, 255)));
  ui->graphic->setBackground(QBrush(Qt::black));

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

//  if (mode == "sun")
//    ui->graphic->setBackground(QBrush(QColor(180, 180, 180)));
//  else if (mode == "night")
//    ui->graphic->setBackground(QBrush(QColor(130, 130, 130)));
}


void ShPIndicatorItem::insertDownWidget()
{
  Q_ASSERT(!m_downWidget);

  m_downWidget = new ShPIndicatorWidget(this);
  m_downWidget->setCurrentPgasNumber(m_upWidget->currentPgasNumber());
  connect(m_downWidget, &ShPIndicatorWidget::info, this, &ShPIndicatorItem::info);

  ui->splitter->addWidget(m_downWidget);
}


void ShPIndicatorItem::deleteDownWidget()
{
  Q_ASSERT(m_downWidget);

  disconnect(m_downWidget, 0, 0, 0);
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
