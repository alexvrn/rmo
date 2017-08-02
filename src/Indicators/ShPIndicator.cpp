// Local
#include "ShPIndicator.h"
#include "ui_ShPIndicator.h"
#include "ShPIndicatorItem.h"

ShPIndicator::ShPIndicator(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::ShPIndicator)
{
  ui->setupUi(this);

  ui->indicatorsHorizontalLayout->addWidget(new ShPIndicatorItem(this));
  ui->indicatorsHorizontalLayout->addWidget(new ShPIndicatorItem(this));
}


ShPIndicator::~ShPIndicator()
{
  delete ui;
}
