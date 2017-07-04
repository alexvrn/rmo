// Local
#include "GLIndicator.h"
#include "ui_GLIndicator.h"

GLIndicator::GLIndicator(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::GLIndicator)
{
  ui->setupUi(this);
}


GLIndicator::~GLIndicator()
{
  delete ui;
}
