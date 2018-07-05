// Local
#include "ShPIndicatorItem.h"
#include "ui_ShPIndicatorItem.h"
#include "ShPIndicatorWidget.h"
#include "Client.h"

// Qt
#include <QSplitter>

ShPIndicatorItem::ShPIndicatorItem(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::ShPIndicatorItem)
  , m_upWidget(new ShPIndicatorWidget(this))
  , m_downWidget(nullptr)
  , m_pgasNumber(1)
  , m_nowData(true)
{
  ui->setupUi(this);

  connect(m_upWidget, &ShPIndicatorWidget::info, this, &ShPIndicatorItem::info);
  connect(m_upWidget, &ShPIndicatorWidget::sectionData, this, &ShPIndicatorItem::sectionData);

  m_upWidget->setHasSwitch(true);
  ui->splitter->addWidget(m_upWidget);
  connect(m_upWidget, SIGNAL(countWidget()), SLOT(countWidget()));

  // Чтобы нижний виджет(график) был меньше по высоте
  ui->splitter_2->setStretchFactor(0, 4);
  ui->splitter_2->setStretchFactor(1, 1);

  //
  m_graphic = ui->graphic->addGraph();
  m_graphic->setPen(QPen(QColor(0,200,0)));
  m_graphic->setBrush(QBrush(QColor(0,200,0)));

  ui->graphic->setBackground(QBrush(Qt::black));
  ui->graphic->xAxis->setBasePen(QPen(QColor(0, 200, 0)));
  ui->graphic->yAxis->setBasePen(QPen(QColor(0, 200, 0)));
  ui->graphic->xAxis->setLabelColor(QColor(0, 200, 0));
  ui->graphic->yAxis->setLabelColor(QColor(0, 200, 0));
  ui->graphic->xAxis->setTickLabelColor(QColor(0, 200, 0));
  ui->graphic->yAxis->setTickLabelColor(QColor(0, 200, 0));

//  QCPItemText *textLabel = new QCPItemText(ui->graphic);
//  textLabel->setPositionAlignment(Qt::AlignTop|Qt::AlignLeft);
//  textLabel->position->setType(QCPItemPosition::ptPlotCoords);
//  textLabel->position->setCoords(20,20); // place position at center/top of axis rect
//  textLabel->setText("Text Item Demo");
//  textLabel->setFont(QFont(font().family(), 16)); // make font a bit larger
//  textLabel->setPen(QPen(Qt::red)); // show black border around text

  //ui->graphic->xAxis2->setVisible(true);
  //ui->graphic->yAxis2->setVisible(true);
  //connect(ui->graphic->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->graphic->xAxis2, SLOT(setRange(QCPRange)));
  //connect(ui->graphic->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->graphic->yAxis2, SLOT(setRange(QCPRange)));

  ui->graphic->xAxis->setRange(0, 128);
  //ui->graphic->axisRect()->setupFullAxesBox();
  ui->graphic->yAxis->setRange(-2, 2);

  connect(&m_replotTimer, SIGNAL(timeout()), SLOT(dataRepaint()));
  m_replotTimer.start(10000);
  dataRepaint();
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
  connect(m_downWidget, &ShPIndicatorWidget::sectionData, this, &ShPIndicatorItem::sectionData);

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
  m_pgasNumber = pgasNumber;
  m_upWidget->setCurrentPgasNumber(pgasNumber);
  if (m_downWidget)
    m_downWidget->setCurrentPgasNumber(pgasNumber);
}


void ShPIndicatorItem::setNowData(bool nowData)
{
  m_nowData = nowData;
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


void ShPIndicatorItem::dataRepaint()
{
  m_upWidget->newData(true);
  if (m_downWidget)
    m_downWidget->newData(true);
}


void ShPIndicatorItem::sectionData(const QVector<double> &keys, const QVector<double> &values)
{
  m_graphic->setData(keys, values);

  m_graphic->rescaleAxes(true);
  ui->graphic->replot();
}
