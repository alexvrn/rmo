// Local
#include "ShPIndicator.h"
#include "ui_ShPIndicator.h"

ShPIndicator::ShPIndicator(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::ShPIndicator)
{
  ui->setupUi(this);
}


ShPIndicator::~ShPIndicator()
{
  delete ui;
}
