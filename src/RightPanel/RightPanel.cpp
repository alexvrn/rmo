// Local
#include "RightPanel.h"
#include "ui_RightPanel.h"
#include "ButtonGroup.h"

// Qt
#include <QTimer>
#include <QDateTime>
#include <QLabel>

RightPanel::RightPanel(QWidget *parent)
  : QFrame(parent)
  , ui(new Ui::RightPanel)
  , m_dateTimeLabel(new QLabel(this))
  , m_timer(new QTimer(this))
{
  ui->setupUi(this);

  ButtonGroup* group = new ButtonGroup(this);
  ui->horizontalLayout->addWidget(group);
  ui->horizontalLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding));
  ui->horizontalLayout->addWidget(m_dateTimeLabel);

  connect(m_timer, SIGNAL(timeout()), SLOT(timer()));
  m_timer->start(1000);
}


RightPanel::~RightPanel()
{
  delete ui;
}


void RightPanel::timer()
{
  const QDateTime currentDateTime = QDateTime::currentDateTime();
  m_dateTimeLabel->setText(currentDateTime.toString("dd MMMM hh:mm:ss"));
}