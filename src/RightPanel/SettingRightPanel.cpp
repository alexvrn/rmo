// Local
#include "SettingRightPanel.h"
#include "ui_SettingRightPanel.h"

// Qt
#include <QButtonGroup>
#include <QMessageBox>
#include <QDebug>
#include <QSignalMapper>
#include <QSettings>


SettingRightPanel::SettingRightPanel(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::SettingRightPanel)
{
  ui->setupUi(this);

  QButtonGroup* group = new QButtonGroup(this);
  group->addButton(ui->sunToolButton);
  group->addButton(ui->nightToolButton);

  QSignalMapper* signalMapper = new QSignalMapper(this);
  connect(ui->sunToolButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
  connect(ui->nightToolButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
  signalMapper->setMapping(ui->sunToolButton, "SUN");
  signalMapper->setMapping(ui->nightToolButton, "NIGHT");
  connect(signalMapper, SIGNAL(mapped(QString)), this, SLOT(modeChecked(QString)));
}


SettingRightPanel::~SettingRightPanel()
{
  delete ui;
}


void SettingRightPanel::setConfiguration(const QString& mode)
{
  if (mode.toUpper() == "SUN")
    ui->sunToolButton->toggle();
  else if (mode.toUpper() == "NIGHT")
    ui->nightToolButton->toggle();
  else
    qWarning() << "Неизвестный тип для настройки палитры:" << mode;
}


void SettingRightPanel::modeChecked(const QString& mode)
{
  QSettings settings("SAMI DVO RAN", "rmo");
  settings.setValue("Mode", mode);
}


void SettingRightPanel::on_exitToolButton_clicked()
{
  if (QMessageBox::Yes == QMessageBox::question(this, tr("РМО"), tr("Вы действительно хотите закрыть приложение РМО?"),
                          QMessageBox::Yes | QMessageBox::No))
    qApp->quit();
}
