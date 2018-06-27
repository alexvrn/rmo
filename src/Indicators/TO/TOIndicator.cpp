// Local
#include "TOIndicator.h"
#include "ui_TOIndicator.h"

TOIndicator::TOIndicator(QWidget *parent)
  : Indicator(parent)
  , ui(new Ui::TOIndicator)
{
  ui->setupUi(this);
}


TOIndicator::~TOIndicator()
{
  delete ui;
}


QString TOIndicator::name() const
{
  return tr("ТО");
}


void TOIndicator::newData(cmd_e cmd, const QVariant& value)
{

}

