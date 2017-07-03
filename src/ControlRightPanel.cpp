// Local
#include "ControlRightPanel.h"
#include "ui_ControlRightPanel.h"
#include "RightPanel.h"

// Qt
#include <QToolBar>


ControlRightPanel::ControlRightPanel(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::ControlRightPanel)
{
  ui->setupUi(this);

  QToolBar *toolBar = new QToolBar(this);
  toolBar->setMovable(false);
  addToolBar(Qt::TopToolBarArea, toolBar);

  RightPanel *panel = new RightPanel(this);
  toolBar->addWidget(panel);

  setWindowTitle("Панель управления");
}


ControlRightPanel::~ControlRightPanel()
{
  delete ui;
}
