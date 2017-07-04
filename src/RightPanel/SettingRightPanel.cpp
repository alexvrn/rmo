// Local
#include "SettingRightPanel.h"
#include "ui_SettingRightPanel.h"

// Qt
#include <QButtonGroup>
#include <QMessageBox>


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


void SettingRightPanel::on_exitToolButton_clicked()
{
  if (QMessageBox::Yes == QMessageBox::question(this, tr("РМО"), tr("Вы действительно хотите закрыть приложение РМО?"),
                          QMessageBox::Yes | QMessageBox::No))
     qApp->quit();
}
