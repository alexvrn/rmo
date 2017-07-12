// Local
#include "ControlRightPanel.h"
#include "ui_ControlRightPanel.h"
#include "RightPanel.h"

// Qt
#include <QToolBar>
#include <QDebug>


ControlRightPanel::ControlRightPanel(QWidget *parent)
  : ControlPanel(parent)
  , ui(new Ui::ControlRightPanel)
  , m_panel(new RightPanel(this))
{
  ui->setupUi(this);

  connect(m_panel, &RightPanel::indicatorChecked, this, &ControlRightPanel::indicatorChecked);
  connect(m_panel, &RightPanel::indicatorChecked, m_indicatorsStackedWidget, &IndicatorsStackedWidget::setCurrentIndicator);

  m_toolBar->addWidget(m_panel);
  setCentralWidget(m_indicatorsStackedWidget);

  setWindowTitle("Панель управления");
}


ControlRightPanel::~ControlRightPanel()
{
  delete ui;
}


void ControlRightPanel::setConfiguration(const QString& type)
{
  m_panel->setConfiguration(type);
}


void ControlRightPanel::indicatorCheck(const QString& type, bool checked)
{
  m_panel->indicatorCheck(type, checked);

  //! TODO: Сделать красиво.
  m_indicatorsStackedWidget->sync(type, checked);
}
