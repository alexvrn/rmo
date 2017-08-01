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
}


ShPIndicatorItem::~ShPIndicatorItem()
{
  delete ui;
}
