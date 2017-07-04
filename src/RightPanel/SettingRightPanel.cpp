// Local
#include "SettingRightPanel.h"
#include "ui_SettingRightPanel.h"

// Qt
#include <QButtonGroup>


SettingRightPanel::SettingRightPanel(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::SettingRightPanel)
{
  ui->setupUi(this);

  QButtonGroup* group = new QButtonGroup(this);
  group->addButton(ui->sunToolButton);
  group->addButton(ui->nightToolButton);
}


SettingRightPanel::~SettingRightPanel()
{
  delete ui;
}
