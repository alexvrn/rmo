// Local
#include "ControlLeftPanel.h"
#include "ui_ControlLeftPanel.h"

ControlLeftPanel::ControlLeftPanel(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::ControlLeftPanel)
{
  ui->setupUi(this);

  setWindowTitle("Панель управления");
}


ControlLeftPanel::~ControlLeftPanel()
{
  delete ui;
}
