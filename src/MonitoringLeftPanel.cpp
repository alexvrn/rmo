#include "MonitoringLeftPanel.h"
#include "ui_MonitoringLeftPanel.h"

MonitoringLeftPanel::MonitoringLeftPanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MonitoringLeftPanel)
{
    ui->setupUi(this);
}

MonitoringLeftPanel::~MonitoringLeftPanel()
{
    delete ui;
}
