// Local
#include "ControlRightPanel.h"
#include "ui_ControlRightPanel.h"
#include "RightPanel.h"
#include "IndicatorsStackedWidget.h"

// Qt
#include <QToolBar>


ControlRightPanel::ControlRightPanel(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::ControlRightPanel)
  , m_panel(new RightPanel(this))
  , m_indicatorsStackedWidget(new IndicatorsStackedWidget(this))
{
  ui->setupUi(this);

  QToolBar *toolBar = new QToolBar(this);
  toolBar->setMovable(false);
  addToolBar(Qt::TopToolBarArea, toolBar);

  connect(m_panel, &RightPanel::indicatorChecked, this, &ControlRightPanel::indicatorChecked);
  connect(m_panel, &RightPanel::indicatorChecked, m_indicatorsStackedWidget, &IndicatorsStackedWidget::setCurrentIndicator);

  toolBar->addWidget(m_panel);

  setCentralWidget(m_indicatorsStackedWidget);

  setWindowTitle("Панель управления");
}


ControlRightPanel::~ControlRightPanel()
{
  delete ui;
}


void ControlRightPanel::indicatorCheck(const QString& type, bool checked)
{
  m_panel->indicatorCheck(type, checked);
}
