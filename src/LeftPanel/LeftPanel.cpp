// Local
#include "LeftPanel.h"
#include "ui_LeftPanel.h"
#include "ButtonGroup.h"

// Qt
#include <QDebug>

LeftPanel::LeftPanel(QWidget *parent)
  : QFrame(parent)
  , ui(new Ui::LeftPanel)
{
  ui->setupUi(this);

  ButtonGroup* group = new ButtonGroup(this);
  ui->horizontalLayout->addWidget(group);
  ui->horizontalLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding));
}


LeftPanel::~LeftPanel()
{
  delete ui;
}


