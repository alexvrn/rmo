// Local
#include "SAIndicator.h"
#include "ui_SAIndicator.h"
#include "Client.h"
#include "GraphicWidget.h"

SAIndicator::SAIndicator(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::SAIndicator)
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

  ui->widget_1->setType(GraphicWidget::SA);
  ui->widget_2->setType(GraphicWidget::SA);
  ui->widget_5->setType(GraphicWidget::SA);
}


SAIndicator::~SAIndicator()
{
  delete ui;
}


void SAIndicator::checkedDateTime()
{
  // Обнуляем секунды
  QDateTime checkDateTime = ui->dateTimeEdit->dateTime();
  const QTime checkTime = checkDateTime.time();
  const QTime time(checkTime.hour(), checkTime.minute(), 0);
  checkDateTime.setTime(time);

  // Посылаем команду(запрос в данном случае)
  //const auto data = Client::instance().parseFile(checkDateTime);
}


void SAIndicator::nowToggled()
{

}
