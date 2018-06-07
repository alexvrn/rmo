// Local
#include "GLIndicatorWidget.h"
#include "ui_GLIndicatorWidget.h"


GLIndicatorWidget::GLIndicatorWidget(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::GLIndicatorWidget)
{
  ui->setupUi(this);

  setHasSwitch(false);
  connect(ui->countToolButton, SIGNAL(clicked(bool)), this, SIGNAL(countWidget()));

  setStyleSheet("#GLIndicatorWidget {background-color: rgb(221, 221, 221);}");
}


GLIndicatorWidget::~GLIndicatorWidget()
{
  delete ui;
}


void GLIndicatorWidget::setHasSwitch(bool hasSwitch)
{
  ui->countToolButton->setVisible(hasSwitch);
}


bool GLIndicatorWidget::hasSwitch() const
{
  return ui->countToolButton->isVisible();
}
