// Local
#include "ShPIndicator.h"
#include "ui_ShPIndicator.h"
#include "ShPIndicatorItem.h"

ShPIndicator::ShPIndicator(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::ShPIndicator)
{
  ui->setupUi(this);

  ui->undoToolButton->setIcon(QIcon(":/icons/undo-circular-arrow.png"));
  ui->redoToolButton->setIcon(QIcon(":/icons/redo-circular-arrow.png"));
  ui->checkedToolButton->setIcon(QIcon(":/icons/checked.png"));

  ui->indicatorsHorizontalLayout->addWidget(new ShPIndicatorItem(this));
  ui->indicatorsHorizontalLayout->addWidget(new ShPIndicatorItem(this));
}


ShPIndicator::~ShPIndicator()
{
  delete ui;
}
