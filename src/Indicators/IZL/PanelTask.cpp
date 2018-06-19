// Local
#include "PanelTask.h"
#include "ui_PanelTask.h"

PanelTask::PanelTask(QWidget *parent)
  : QWidget(parent)
  ,  ui(new Ui::PanelTask)
{
  ui->setupUi(this);
}


PanelTask::~PanelTask()
{
  delete ui;
}
