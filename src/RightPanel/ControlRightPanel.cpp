// Local
#include "ControlRightPanel.h"
#include "ui_ControlRightPanel.h"
#include "RightPanel.h"

// Qt
#include <QToolBar>
#include <QDebug>
#include <QSystemTrayIcon>
#include <QTimer>


ControlRightPanel::ControlRightPanel(QWidget *parent)
  : ControlPanel(parent)
  , ui(new Ui::ControlRightPanel)
  , m_panel(new RightPanel(this))
  //, m_trayIcon(new QSystemTrayIcon(this))
{
  ui->setupUi(this);

  connect(m_panel, &RightPanel::indicatorChecked, this, &ControlRightPanel::indicatorChecked);
  connect(m_panel, &RightPanel::indicatorChecked, m_indicatorsStackedWidget, &IndicatorsStackedWidget::setCurrentIndicator);
  connect(m_panel, &RightPanel::lightMode, this, &ControlRightPanel::lightMode);
  connect(m_panel, &RightPanel::lightMode, this, &ControlRightPanel::setLightMode);

  m_toolBar->addWidget(m_panel);
  setCentralWidget(m_indicatorsStackedWidget);

  //m_trayIcon = new QSystemTrayIcon(this);
  //m_trayIcon->setIcon(QIcon());
  //m_trayIcon->setContextMenu(trayIconMenu);

  // Подключаем обработчик клика по иконке...
  //connect(m_trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(trayIconActivated(QSystemTrayIcon::ActivationReason)));

  // Выводим значок...
  //m_trayIcon->show();

  setWindowTitle("Панель управления");
}


ControlRightPanel::~ControlRightPanel()
{
  delete ui;
}


void ControlRightPanel::setConfiguration(const QString& type, const QString& mode)
{
  m_panel->setConfiguration(type, mode);
  m_indicatorsStackedWidget->setCurrentIndicator(type, true);
  setLightMode(mode);
}


void ControlRightPanel::indicatorCheck(const QString& type, bool checked)
{
  m_panel->indicatorCheck(type, checked);

  //! TODO: Сделать красиво.
  m_indicatorsStackedWidget->sync(type, checked);
}


void ControlRightPanel::setLightMode(const QString &mode)
{
  m_indicatorsStackedWidget->setLightMode(mode);
}
