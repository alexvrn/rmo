// Local
#include "IndicatorList.h"
#include "ui_IndicatorList.h"

// Indicators
#include "ShPIndicator.h"
#include "GLIndicator.h"
#include "TOIndicator.h"
#include "SAIndicator.h"
#include "ZPSIndicator.h"
#include "IZLIndicator.h"

// Qt
#include <QDebug>

IndicatorList::IndicatorList(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::IndicatorList)
  , m_nullIndicator(new QWidget(this))
  , m_glIndicator(new GLIndicator(this))
  , m_shpIndicator(new ShPIndicator(this))
  , m_toIndicator(new TOIndicator(this))
  , m_saIndicator(new SAIndicator(this))
  , m_zpsIndicator(new ZPSIndicator(this))
  , m_izlIndicator(new IZLIndicator(this))
  , m_leftIndicator(nullptr)
  , m_rightIndicator(nullptr)
{
  ui->setupUi(this);

  m_indicators[m_glIndicator->name()]  = m_glIndicator;
  m_indicators[m_shpIndicator->name()] = m_shpIndicator;
  m_indicators[m_toIndicator->name()]  = m_toIndicator;
  m_indicators[m_saIndicator->name()]  = m_saIndicator;
  m_indicators[m_zpsIndicator->name()] = m_zpsIndicator;
  m_indicators[m_izlIndicator->name()] = m_izlIndicator;

  for (auto indicator : m_indicators.values())
  {
    indicator->hide();
    connect(indicator, SIGNAL(info(QString)), this, SIGNAL(info(QString)));
  }
}


IndicatorList::~IndicatorList()
{
  delete ui;
}


void IndicatorList::setCurrentIndicators(const QString& leftType, const QString& rightType)
{
  // Очистка
  if (m_leftIndicator)
    ui->horizontalLayout->removeWidget(m_leftIndicator);
  if (m_rightIndicator)
    ui->horizontalLayout->removeWidget(m_rightIndicator);

  // Left
  if (leftType.isEmpty() || !m_indicators.contains(leftType))
    m_leftIndicator = nullptr;
  else
    m_leftIndicator = m_indicators[leftType];

  // Right
  if (rightType.isEmpty() || !m_indicators.contains(rightType))
    m_rightIndicator = nullptr;
  else
    m_rightIndicator = m_indicators[rightType];

  for (auto indicator : m_indicators.values())
    indicator->hide();

  if (m_leftIndicator)
  {
    ui->horizontalLayout->addWidget(m_leftIndicator, 1);
    m_leftIndicator->show();
  }
  if (m_rightIndicator)
  {
    ui->horizontalLayout->addWidget(m_rightIndicator, 1);
    m_rightIndicator->show();
  }
}


void IndicatorList::setLightMode(const QString& mode)
{
  //for (auto indicator : m_indicators.values())
  //  indicator->setLightMode(mode);
}


void IndicatorList::newData(cmd_e cmd, const QVariant& value)
{
  for (auto indicator : m_indicators.values())
    indicator->newData(cmd, value);
}


