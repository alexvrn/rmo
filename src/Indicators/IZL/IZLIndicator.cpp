// Local
#include "IZLIndicator.h"
#include "ui_IZLIndicator.h"


IZLIndicator::IZLIndicator(QWidget *parent)
  : Indicator(parent)
  , ui(new Ui::IZLIndicator)
{
  ui->setupUi(this);
}


IZLIndicator::~IZLIndicator()
{
  delete ui;
}


void IZLIndicator::newData(CommandType::Command cmd, const QVariant& value)
{

}


QString IZLIndicator::name() const
{
  return tr("ИЗЛ");
}
