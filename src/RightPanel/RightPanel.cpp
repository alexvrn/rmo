// Local
#include "RightPanel.h"
#include "ui_RightPanel.h"
#include "ButtonGroup.h"
#include "SettingRightPanel.h"

// Qt
#include <QTimer>
#include <QDateTime>
#include <QLabel>

RightPanel::RightPanel(QWidget *parent)
  : QFrame(parent)
  , ui(new Ui::RightPanel)
  , m_group(new ButtonGroup(this))
  , m_dateTimeLabel(new QLabel(this))
  , m_timer(new QTimer(this))
{
  ui->setupUi(this);

  connect(m_group, &ButtonGroup::indicatorChecked, this, &RightPanel::indicatorChecked);
  ui->horizontalLayout->addWidget(m_group);
  ui->horizontalLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding));
  ui->horizontalLayout->addWidget(m_dateTimeLabel);

  SettingRightPanel *settingPanel = new SettingRightPanel(this);
  ui->horizontalLayout->addWidget(settingPanel);

  connect(m_timer, SIGNAL(timeout()), SLOT(timer()));
  m_timer->start(1000);
}


RightPanel::~RightPanel()
{
  delete ui;
}


void RightPanel::indicatorCheck(const QString& type, bool checked)
{
  m_group->indicatorCheck(type, checked);
}


void RightPanel::setConfiguration(const QString& type)
{
  m_group->setConfiguration(type);
}


void RightPanel::timer()
{
  const QDateTime currentDateTime = QDateTime::currentDateTime();
  m_dateTimeLabel->setText(currentDateTime.toString("dd MMMM hh:mm:ss"));
}
