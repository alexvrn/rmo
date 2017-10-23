// Local
#include "ShPIndicator.h"
#include "ui_ShPIndicator.h"
#include "ShPIndicatorItem.h"

// Qt
#include <QButtonGroup>

ShPIndicator::ShPIndicator(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::ShPIndicator)
  , indicatorItem1(new ShPIndicatorItem(this))
  , indicatorItem2(new ShPIndicatorItem(this))
{
  ui->setupUi(this);

  ui->lastToolButton->setIcon(QIcon(":/icons/undo-circular-arrow.png"));
  ui->nowToolButton->setIcon(QIcon(":/icons/redo-circular-arrow.png"));
  ui->checkedToolButton->setIcon(QIcon(":/icons/checked.png"));

  ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());

  QButtonGroup * buttonGroup = new QButtonGroup(this);
  buttonGroup->addButton(ui->lastToolButton);
  buttonGroup->addButton(ui->nowToolButton);

  connect(ui->nowToolButton, SIGNAL(clicked(bool)), SIGNAL(nowData()));
  connect(ui->checkedToolButton, SIGNAL(clicked(bool)), SLOT(checkedDateTime()));

  ui->indicatorsHorizontalLayout->addWidget(indicatorItem1);
  ui->indicatorsHorizontalLayout->addWidget(indicatorItem2);
}


ShPIndicator::~ShPIndicator()
{
  delete ui;
}


void ShPIndicator::checkedDateTime()
{
  emit lastData(ui->dateTimeEdit->dateTime());
}


void ShPIndicator::setLightMode(const QString& mode)
{
  indicatorItem1->setLightMode(mode);
  indicatorItem2->setLightMode(mode);
}


void ShPIndicator::data(double key, double value)
{
  indicatorItem1->data(key, value);
  indicatorItem2->data(key, value);
}
