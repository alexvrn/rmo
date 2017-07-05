// Local
#include "TOIndicator.h"
#include "ui_TOIndicator.h"

TOIndicator::TOIndicator(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::TOIndicator)
{
  ui->setupUi(this);
}


TOIndicator::~TOIndicator()
{
  delete ui;
}
