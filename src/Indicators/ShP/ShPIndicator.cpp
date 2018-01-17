// Local
#include "ShPIndicator.h"
#include "ui_ShPIndicator.h"
#include "ShPIndicatorItem.h"
#include "Client.h"


ShPIndicator::ShPIndicator(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::ShPIndicator)
  , m_indicatorItem1(new ShPIndicatorItem(this))
  , m_indicatorItem2(new ShPIndicatorItem(this))
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

  connect(ui->nowToolButton, SIGNAL(toggled(bool)), SLOT(nowToggled()));

  ui->indicatorsHorizontalLayout->addWidget(m_indicatorItem1);
  ui->indicatorsHorizontalLayout->addWidget(m_indicatorItem2);
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

  // Посылаем команду(запрос в данном случае)
  const auto data = Client::instance().parseFile(checkDateTime);

  m_indicatorItem1->setSelectedData(data, checkDateTime);
  m_indicatorItem2->setSelectedData(data, checkDateTime);
}


void ShPIndicator::nowToggled()
{
  m_indicatorItem1->setNowData(ui->nowToolButton->isChecked());
  m_indicatorItem2->setNowData(ui->nowToolButton->isChecked());

  // Обнуляем данные
  m_indicatorItem1->setSelectedData(PgasData());
  m_indicatorItem2->setSelectedData(PgasData());
}


void ShPIndicator::setLightMode(const QString& mode)
{
  m_indicatorItem1->setLightMode(mode);
  m_indicatorItem2->setLightMode(mode);
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
        m_indicatorItem1->newData();
        m_indicatorItem2->newData();
      }
    }
  }
}


void ShPIndicator::on_spinBox_valueChanged(int value)
{
  m_indicatorItem1->setCurrentPgasNumber(value);
  m_indicatorItem2->setCurrentPgasNumber(value);
}
