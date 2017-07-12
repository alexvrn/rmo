// Local
#include "LeftPanel.h"
#include "ui_LeftPanel.h"
#include "ButtonGroup.h"
#include "MonitoringLeftPanel.h"

// Qt
#include <QDebug>

LeftPanel::LeftPanel(QWidget *parent)
  : QFrame(parent)
  , ui(new Ui::LeftPanel)
  , m_group(new ButtonGroup(this))
{
  ui->setupUi(this);

  connect(m_group, &ButtonGroup::indicatorChecked, this, &LeftPanel::indicatorChecked);
  ui->horizontalLayout->addWidget(m_group);
  ui->horizontalLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding));

  MonitoringLeftPanel *monitoring = new MonitoringLeftPanel(this);
  ui->horizontalLayout->addWidget(monitoring);
}


LeftPanel::~LeftPanel()
{
  delete ui;
}


void LeftPanel::indicatorCheck(const QString& type, bool checked)
{
  m_group->indicatorCheck(type, checked);
}


void LeftPanel::setConfiguration(const QString& type)
{
  m_group->setConfiguration(type);
}


