// Local
#include "LeftPanel.h"
#include "ui_LeftPanel.h"
#include "ButtonGroup.h"
#include "MonitoringLeftPanel.h"

// Qt
#include <QDebug>
#include <QSettings>

LeftPanel::LeftPanel(QWidget *parent)
  : QFrame(parent)
  , ui(new Ui::LeftPanel)
  , m_group(new ButtonGroup(this))
{
  ui->setupUi(this);

  setWindowFlag(Qt::Dialog);

  connect(m_group, &ButtonGroup::indicatorChecked, this, &LeftPanel::indicatorChecked);
  connect(m_group, &ButtonGroup::indicatorChecked, this, &LeftPanel::settingsSave);
  connect(m_group, &ButtonGroup::otherIndicatorChecked, this, &LeftPanel::otherIndicatorChecked);

  ui->horizontalLayout->addWidget(m_group);
  ui->horizontalLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding));

  MonitoringLeftPanel *monitoring = new MonitoringLeftPanel(this);
  ui->horizontalLayout->addWidget(monitoring);
}


LeftPanel::~LeftPanel()
{
  delete ui;
}


void LeftPanel::settingsSave(const QString& type)
{
  QSettings settings("SAMI_DVO_RAN", "rmo");
  settings.setValue("left/indicator", type);
}


void LeftPanel::indicatorCheck(const QString& type, bool checked)
{
  if (!checked)
    return;

  const QString currentType = m_group->indicatorCheck(type, checked);
  QSettings settings("SAMI_DVO_RAN", "rmo");
  settings.setValue("left/indicator", currentType);
}


void LeftPanel::fromOtherIndicatorChecked(const QString& type)
{
  const QString currentType = m_group->fromOtherIndicatorChecked(type);
  QSettings settings("SAMI_DVO_RAN", "rmo");
  settings.setValue("left/indicator", currentType);
}


void LeftPanel::setConfiguration(const QString& type)
{
  m_group->setConfiguration(type);
}


