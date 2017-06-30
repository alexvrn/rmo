// Local
#include "ControlRightPanel.h"
#include "ui_ControlRightPanel.h"

// Qt
#include <QToolBar>
#include <QPushButton>

ControlRightPanel::ControlRightPanel(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::ControlRightPanel)
{
  ui->setupUi(this);

  QToolBar *toolBar = new QToolBar(this);
  toolBar->setMovable(false);
  addToolBar(Qt::TopToolBarArea, toolBar);

  setWindowState(Qt::WindowFullScreen);

  setWindowTitle("Панель управления");
}


ControlRightPanel::~ControlRightPanel()
{
  delete ui;
}
