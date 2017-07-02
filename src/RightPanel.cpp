// Local
#include "RightPanel.h"
#include "ui_RightPanel.h"

// Qt
#include <QTimer>
#include <QDateTime>

RightPanel::RightPanel(QWidget *parent)
  : QFrame(parent)
  , ui(new Ui::RightPanel)
  , m_timer(new QTimer(this))
{
  ui->setupUi(this);
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
  ui->dateTimeLabel->setText(currentDateTime.toString("dd MMMM hh:mm:ss"));
}
