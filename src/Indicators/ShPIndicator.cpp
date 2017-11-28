// Local
#include "ShPIndicator.h"
#include "ui_ShPIndicator.h"
#include "ShPIndicatorItem.h"
#include "Client.h"

// Qt
#include <QButtonGroup>

ShPIndicator::ShPIndicator(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::ShPIndicator)
  , indicatorItem1(new ShPIndicatorItem(this))
  , indicatorItem2(new ShPIndicatorItem(this))
{
  ui->setupUi(this);

  ui->lastToolButton->setIcon(QIcon(":/icons/undo-circular-arrow.png"));
  ui->nowToolButton->setIcon(QIcon(":/icons/redo-circular-arrow.png"));
  ui->checkedToolButton->setIcon(QIcon(":/icons/checked.png"));

  ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());

  QButtonGroup * buttonGroup = new QButtonGroup(this);
  buttonGroup->addButton(ui->lastToolButton);
  buttonGroup->addButton(ui->nowToolButton);

  connect(ui->checkedToolButton, SIGNAL(clicked(bool)), SLOT(checkedDateTime()));

  ui->indicatorsHorizontalLayout->addWidget(indicatorItem1);
  ui->indicatorsHorizontalLayout->addWidget(indicatorItem2);
}


ShPIndicator::~ShPIndicator()
{
  delete ui;
}


void ShPIndicator::checkedDateTime()
{
  // Запрашиваем данные по выбранному времени
  QVariantMap v;
  v["datetime"] = ui->dateTimeEdit->dateTime();

  // Посылаем команду(запрос в данном случае)
  Client::instance().sendCommand(CommandType::CMD_RequestData_DateTime, v);
}


void ShPIndicator::setLightMode(const QString& mode)
{
  indicatorItem1->setLightMode(mode);
  indicatorItem2->setLightMode(mode);
}


void ShPIndicator::data(CommandType::Command cmd, const QByteArray& value)
{
  // Если текущие данные ПГАС
  if (cmd == CommandType::CMD_PGAS_Data)
  {
    // Если смотрим на текущие данные (иначе не игнорим, данные записались в файлы)
    if (!ui->lastToolButton->isChecked())
    {
      indicatorItem1->data(cmd, value);
      indicatorItem2->data(cmd, value);
    }
  }
  // Ответ на запрос данных на определённое время
  else if (cmd == CommandType::CMD_RequestData_DateTime)
  {
    if (ui->lastToolButton->isChecked())
    {
      // bla bla bla
    }
  }
}


void ShPIndicator::on_spinBox_valueChanged(int value)
{
  // Запрашиваем данные по выбранному времени
  //QVariantMap v;
  //v["datetime"] = ui->dateTimeEdit->dateTime();

  // Посылаем команду(запрос в данном случае)
  //Client::instance().sendCommand(1, v);
}
