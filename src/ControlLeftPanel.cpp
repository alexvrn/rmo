// Local
#include "ControlLeftPanel.h"
#include "ui_ControlLeftPanel.h"

// Qt
#include <QToolBar>
#include <QPushButton>

ControlLeftPanel::ControlLeftPanel(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::ControlLeftPanel)
{
  ui->setupUi(this);

  QToolBar *toolBar = new QToolBar(this);
  toolBar->setMovable(false);
  addToolBar(Qt::TopToolBarArea, toolBar);

  setWindowTitle("Панель управления");
}


ControlLeftPanel::~ControlLeftPanel()
{
  delete ui;
}
