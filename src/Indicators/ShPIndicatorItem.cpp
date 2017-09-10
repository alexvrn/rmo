// Local
#include "ShPIndicatorItem.h"
#include "ui_ShPIndicatorItem.h"
#include "ShPIndicatorWidget.h"

ShPIndicatorItem::ShPIndicatorItem(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::ShPIndicatorItem)
  , m_widget(new ShPIndicatorWidget(this))
{
  ui->setupUi(this);

  ui->nextRightToolButton->setIcon(QIcon(":/icons/right-arrow.png"));

  ui->widgetsVerticalLayout->addWidget(m_widget);
}


ShPIndicatorItem::~ShPIndicatorItem()
{
  delete ui;
}


void ShPIndicatorItem::setLightMode(const QString& mode)
{
  m_widget->setLightMode(mode);
  if (mode == "sun")
    ui->widget_2->setBackground(QBrush(QColor(180, 180, 180)));
  else if (mode == "night")
    ui->widget_2->setBackground(QBrush(QColor(130, 130, 130)));
}
