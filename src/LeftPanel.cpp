// Local
#include "LeftPanel.h"
#include "ui_LeftPanel.h"

LeftPanel::LeftPanel(QWidget *parent)
  : QFrame(parent)
  , ui(new Ui::LeftPanel)
{
  ui->setupUi(this);
}


LeftPanel::~LeftPanel()
{
  delete ui;
}
