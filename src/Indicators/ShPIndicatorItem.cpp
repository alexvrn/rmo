// Local
#include "ShPIndicatorItem.h"
#include "ui_ShPIndicatorItem.h"
#include "ShPIndicatorWidget.h"

ShPIndicatorItem::ShPIndicatorItem(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::ShPIndicatorItem)
{
  ui->setupUi(this);

  ui->nextRightToolButton->setIcon(QIcon(":/icons/right-arrow.png"));
  ui->targetToolButton->setIcon(QIcon(":/icons/target.png"));

  ui->widgetsVerticalLayout->addWidget(new ShPIndicatorWidget(this));
  ui->widget_2->setBackground(QBrush(QColor(180, 180, 180)));
}


ShPIndicatorItem::~ShPIndicatorItem()
{
  delete ui;
}
