// Local
#include "ControlLeftPanel.h"
#include "ui_ControlLeftPanel.h"
#include "LeftPanel.h"

// Qt
#include <QToolBar>
#include <QHBoxLayout>

ControlLeftPanel::ControlLeftPanel(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::ControlLeftPanel)
{
  ui->setupUi(this);

  QToolBar *toolBar = new QToolBar(this);
  toolBar->setMovable(false);
  addToolBar(Qt::TopToolBarArea, toolBar);

  LeftPanel *panel = new LeftPanel(this);
  toolBar->addWidget(panel);

  setWindowTitle("Панель управления");
}


ControlLeftPanel::~ControlLeftPanel()
{
  delete ui;
}
