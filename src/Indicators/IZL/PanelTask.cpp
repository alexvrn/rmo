// Local
#include "PanelTask.h"
#include "ui_PanelTask.h"

PanelTask::PanelTask(QWidget *parent)
  : QWidget(parent)
  ,  ui(new Ui::PanelTask)
  , m_tonalModel(new TonalModel(this))
  , m_complicatedModel(new TonalModel(this))
{
  ui->setupUi(this);

  ui->tonalTableView->setModel(m_tonalModel);
  ui->complicatedTableView->setModel(m_complicatedModel);
}


PanelTask::~PanelTask()
{
  delete ui;
}
