// Local
#include "ShPIndicator.h"
#include "ui_ShPIndicator.h"
#include "ShPIndicatorItem.h"
#include "Client.h"


ShPIndicator::ShPIndicator(QWidget *parent)
  : Indicator(parent)
  , ui(new Ui::ShPIndicator)
{
  ui->setupUi(this);

  connect(ui->indicatorItem1, &ShPIndicatorItem::info, this, &Indicator::info);
  connect(ui->indicatorItem2, &ShPIndicatorItem::info, this, &Indicator::info);

  ui->lastToolButton->setIcon(QIcon(":/icons/undo-circular-arrow.png"));
  ui->nowToolButton->setIcon(QIcon(":/icons/redo-circular-arrow.png"));
  ui->checkedToolButton->setIcon(QIcon(":/icons/checked.png"));

  ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());

  QButtonGroup * buttonGroup = new QButtonGroup(this);
  buttonGroup->addButton(ui->lastToolButton);
  buttonGroup->addButton(ui->nowToolButton);

  connect(ui->checkedToolButton, SIGNAL(clicked(bool)), SLOT(checkedDateTime()));

  connect(ui->nowToolButton, SIGNAL(toggled(bool)), SLOT(nowToggled()));
}


ShPIndicator::~ShPIndicator()
{
  delete ui;
}


void ShPIndicator::checkedDateTime()
{
  // Обнуляем секунды
  QDateTime checkDateTime = ui->dateTimeEdit->dateTime();
  const QTime checkTime = checkDateTime.time();
  const QTime time(checkTime.hour(), checkTime.minute(), 0);
  checkDateTime.setTime(time);

  qApp->setOverrideCursor(QCursor(Qt::WaitCursor));
  // Посылаем команду(запрос в данном случае)
  const auto data = Client::instance().parseFileForDateTime(ui->spinBox->value(), checkDateTime);
  qApp->restoreOverrideCursor();

  ui->indicatorItem1->setSelectedData(data, checkDateTime);
  ui->indicatorItem2->setSelectedData(data, checkDateTime);
}


void ShPIndicator::nowToggled()
{
  ui->indicatorItem1->setNowData(ui->nowToolButton->isChecked());
  ui->indicatorItem2->setNowData(ui->nowToolButton->isChecked());

  // Обнуляем данные
  ui->indicatorItem1->setSelectedData(PgasData());
  ui->indicatorItem2->setSelectedData(PgasData());
}


void ShPIndicator::setLightMode(const QString& mode)
{
  ui->indicatorItem1->setLightMode(mode);
  ui->indicatorItem2->setLightMode(mode);
}


void ShPIndicator::newData(CommandType::Command cmd, const QVariant& value)
{
  // Если выбрано получение данных по конкретной дате, то текущие данные игнорим
  if (!ui->nowToolButton->isChecked())
  {
    return;
  }
  else
  {
    // Если текущие данные ПГАС
    if (cmd >= CommandType::Stream_1 && cmd <= CommandType::Stream_22)
    {
      // Если смотрим на текущие данные (иначе не игнорим, данные записались в файлы)
      if (!ui->lastToolButton->isChecked())
      {
        ui->indicatorItem1->newData();
        ui->indicatorItem2->newData();
      }
    }
  }
}


void ShPIndicator::on_spinBox_valueChanged(int value)
{
  ui->indicatorItem1->setCurrentPgasNumber(value);
  ui->indicatorItem2->setCurrentPgasNumber(value);
}
