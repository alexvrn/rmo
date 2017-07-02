// Local
#include "LeftPanel.h"
#include "ui_LeftPanel.h"

#include <QButtonGroup>
#include <QDebug>

LeftPanel::LeftPanel(QWidget *parent)
  : QFrame(parent)
  , ui(new Ui::LeftPanel)
{
  ui->setupUi(this);

  QButtonGroup* bg = new QButtonGroup(this);
  bg->addButton(ui->toolButton);
  bg->addButton(ui->toolButton_2);
  bg->addButton(ui->toolButton_3);
  bg->addButton(ui->toolButton_4);
  bg->addButton(ui->toolButton_5);
  bg->addButton(ui->toolButton_6);
  bg->addButton(ui->toolButton_7);

  connect(bg, SIGNAL(buttonPressed(QAbstractButton *)), SLOT(buttonToggled(QAbstractButton *)));
}


LeftPanel::~LeftPanel()
{
  delete ui;
}


void LeftPanel::buttonToggled(QAbstractButton *button)
{
  QButtonGroup* group = (QButtonGroup*)sender();
  if (button->isChecked())
  {
      group->setExclusive(false);
      button->setChecked(false);
      group->setExclusive(true);
      qDebug() << "111111111";
  }
}
