// Local
#include "ShPIndicator.h"
#include "ui_ShPIndicator.h"
#include "ShPIndicatorItem.h"

ShPIndicator::ShPIndicator(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::ShPIndicator)
  , indicatorItem1(new ShPIndicatorItem(this))
  , indicatorItem2(new ShPIndicatorItem(this))
{
  ui->setupUi(this);

  ui->undoToolButton->setIcon(QIcon(":/icons/undo-circular-arrow.png"));
  ui->redoToolButton->setIcon(QIcon(":/icons/redo-circular-arrow.png"));
  ui->checkedToolButton->setIcon(QIcon(":/icons/checked.png"));

  ui->indicatorsHorizontalLayout->addWidget(indicatorItem1);
  ui->indicatorsHorizontalLayout->addWidget(indicatorItem2);
}


ShPIndicator::~ShPIndicator()
{
  delete ui;
}


void ShPIndicator::setLightMode(const QString& mode)
{
  indicatorItem1->setLightMode(mode);
  indicatorItem2->setLightMode(mode);
}
