// Local
#include "ZPSIndicatorData.h"
#include "ui_ZPSIndicatorData.h"

// Qt
#include <QButtonGroup>

ZPSIndicatorData::ZPSIndicatorData(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::ZPSIndicatorData)
{
  ui->setupUi(this);

  QButtonGroup* panelButtonGroup = new QButtonGroup(this);
  panelButtonGroup->addButton(ui->inputPushButton);
  panelButtonGroup->addButton(ui->outputPushButton);

  QButtonGroup* inputButtonGroup = new QButtonGroup(this);
  inputButtonGroup->addButton(ui->ikhPushButton);
  inputButtonGroup->addButton(ui->textPushButton);
}


ZPSIndicatorData::~ZPSIndicatorData()
{
  delete ui;
}


void ZPSIndicatorData::on_inputPushButton_clicked()
{
  ui->stackedWidget->setCurrentWidget(ui->inputPage);
}


void ZPSIndicatorData::on_outputPushButton_clicked()
{
  ui->stackedWidget->setCurrentWidget(ui->outputPage);
}
