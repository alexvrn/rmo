// Local
#include "MonitoringLeftPanel.h"
#include "ui_MonitoringLeftPanel.h"

MonitoringLeftPanel::MonitoringLeftPanel(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::MonitoringLeftPanel)
{
  ui->setupUi(this);
}


MonitoringLeftPanel::~MonitoringLeftPanel()
{
  delete ui;
}


QString MonitoringLeftPanel::styleSheetState(int state) const
{
  QString color = "grey";
  if (state == 1)
    color = "red";
  else if (state == 2)
    color = "yellow";
  else if (state == 3)
    color = "green";

  return QString("border-radius: 10px;"
                 "border: 1px solid %1;"
                 "background-color: %1;").arg(color);
}


void MonitoringLeftPanel::setResultControlComplex(int state)
{
  ui->resultControlComplexLabel->setStyleSheet(styleSheetState(state));
}


void MonitoringLeftPanel::setResultControlDevice(int state)
{
  ui->resultControlDeviceLabel->setStyleSheet(styleSheetState(state));
}


void MonitoringLeftPanel::setResultControlSoft(int state)
{
  ui->resultControlSoftLabel->setStyleSheet(styleSheetState(state));
}



