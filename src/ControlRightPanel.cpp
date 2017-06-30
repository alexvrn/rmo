// Local
#include "ControlRightPanel.h"
#include "ui_ControlRightPanel.h"

ControlRightPanel::ControlRightPanel(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::ControlRightPanel)
{
  ui->setupUi(this);

  setWindowTitle("Панель управления");
}


ControlRightPanel::~ControlRightPanel()
{
  delete ui;
}
