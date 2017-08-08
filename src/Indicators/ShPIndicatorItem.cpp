// Local
#include "ShPIndicatorItem.h"
#include "ui_ShPIndicatorItem.h"
#include "ShPIndicatorWidget.h"

ShPIndicatorItem::ShPIndicatorItem(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::ShPIndicatorItem)
{
  ui->setupUi(this);

  ui->nextRightToolButton->setIcon(QIcon::fromTheme("arrow-right-icon"));

  ui->widgetsVerticalLayout->addWidget(new ShPIndicatorWidget(this));
  ui->widget_2->setBackground(QColor(0,0,0));
}


ShPIndicatorItem::~ShPIndicatorItem()
{
  delete ui;
}
