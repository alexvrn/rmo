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
  , m_panel(new LeftPanel(this))
{
  ui->setupUi(this);

  QToolBar *toolBar = new QToolBar(this);
  toolBar->setMovable(false);
  addToolBar(Qt::TopToolBarArea, toolBar);

  connect(m_panel, &LeftPanel::indicatorChecked, this, &ControlLeftPanel::indicatorChecked);

  toolBar->addWidget(m_panel);

  setWindowTitle("Панель управления");
}


ControlLeftPanel::~ControlLeftPanel()
{
  delete ui;
}


void ControlLeftPanel::indicatorCheck(const QString& type, bool checked)
{
  m_panel->indicatorCheck(type, checked);
}
