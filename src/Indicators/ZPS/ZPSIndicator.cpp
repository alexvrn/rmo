// Local
#include "ZPSIndicator.h"
#include "ui_ZPSIndicator.h"
#include "GraphicTime.h"

ZPSIndicator::ZPSIndicator(QWidget *parent)
  : Indicator(parent)
  , ui(new Ui::ZPSIndicator)
{
  ui->setupUi(this);

  // K-21
  ui->graphicTimeK21->setLabel(tr("AK max"));
  ui->graphicK21->setBackground(QBrush(Qt::black));

  // K-CЧ
  ui->graphicTimeKSCH->setLabel(tr("AK max"));
  ui->graphicKSCH->setBackground(QBrush(Qt::black));
}


ZPSIndicator::~ZPSIndicator()
{
  delete ui;
}
