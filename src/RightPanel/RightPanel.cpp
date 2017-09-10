// Local
#include "RightPanel.h"
#include "ui_RightPanel.h"
#include "ButtonGroup.h"
#include "SettingRightPanel.h"

// Qt
#include <QTimer>
#include <QDateTime>
#include <QLabel>
#include <QSettings>

RightPanel::RightPanel(QWidget *parent)
  : QFrame(parent)
  , ui(new Ui::RightPanel)
  , m_settingPanel(new SettingRightPanel(this))
  , m_group(new ButtonGroup(this))
  , m_dateTimeLabel(new QLabel(this))
  , m_timer(new QTimer(this))
{
  ui->setupUi(this);

  connect(m_group, &ButtonGroup::indicatorChecked, this, &RightPanel::indicatorChecked);
  connect(m_group, &ButtonGroup::indicatorChecked, this, &RightPanel::settingsSave);
  
  connect(m_settingPanel, &SettingRightPanel::lightMode, this, &RightPanel::lightMode);

  ui->horizontalLayout->addWidget(m_group);
  ui->horizontalLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding));
  ui->horizontalLayout->addWidget(m_dateTimeLabel);

  ui->horizontalLayout->addWidget(m_settingPanel);

  connect(m_timer, SIGNAL(timeout()), SLOT(timer()));
  m_timer->start(1000);
}


RightPanel::~RightPanel()
{
  delete ui;
}


void RightPanel::settingsSave(const QString& type, bool checked)
{
  QSettings settings("SAMI DVO RAN", "rmo");
  settings.setValue("right/indicator", checked ? type : QString());
}


void RightPanel::indicatorCheck(const QString& type, bool checked)
{
  if (!checked)
    return;

  const QString currentType = m_group->indicatorCheck(type, checked);
  QSettings settings("SAMI DVO RAN", "rmo");
  settings.setValue("right/indicator", currentType);
}


void RightPanel::setConfiguration(const QString& type, const QString& mode)
{
  m_group->setConfiguration(type);
  m_settingPanel->setConfiguration(mode);
}


void RightPanel::timer()
{
  const QDateTime currentDateTime = QDateTime::currentDateTime();
  m_dateTimeLabel->setText(currentDateTime.toString("dd MMMM hh:mm:ss"));
}
