// Local
#include "ControlLeftPanel.h"
#include "ui_ControlLeftPanel.h"
#include "LeftPanel.h"

// Qt
#include <QToolBar>
#include <QHBoxLayout>
#include <QCloseEvent>


ControlLeftPanel::ControlLeftPanel(QWidget *parent)
  : ControlPanel(parent)
  , ui(new Ui::ControlLeftPanel)
  , m_panel(new LeftPanel(this))
{
  ui->setupUi(this);

  connect(m_panel, &LeftPanel::indicatorChecked, this, &ControlLeftPanel::indicatorChecked);
  connect(m_panel, &LeftPanel::indicatorChecked, m_indicatorsStackedWidget, &IndicatorsStackedWidget::setCurrentIndicator);

  m_toolBar->addWidget(m_panel);
  setCentralWidget(m_indicatorsStackedWidget);

  connect(m_indicatorsStackedWidget, SIGNAL(info(QString)), statusBar(), SLOT(showMessage(QString)));

  setWindowTitle("Панель управления");
}


ControlLeftPanel::~ControlLeftPanel()
{
  delete ui;
}


void ControlLeftPanel::setConfiguration(const QString& type, const QString& mode)
{
  Q_UNUSED(mode);

  m_panel->setConfiguration(type);
  m_indicatorsStackedWidget->setCurrentIndicator(type, true);
  m_indicatorsStackedWidget->setLightMode(mode);
}


void ControlLeftPanel::indicatorCheck(const QString& type, bool checked)
{
  m_panel->indicatorCheck(type, checked);

  //! TODO: Сделать красиво.
  m_indicatorsStackedWidget->sync(type, checked);
}


void ControlLeftPanel::setLightMode(const QString& mode)
{
  m_indicatorsStackedWidget->setLightMode(mode);
}
