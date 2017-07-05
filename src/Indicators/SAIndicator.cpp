// Local
#include "SAIndicator.h"
#include "ui_SAIndicator.h"

SAIndicator::SAIndicator(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::SAIndicator)
{
  ui->setupUi(this);
}


SAIndicator::~SAIndicator()
{
  delete ui;
}
