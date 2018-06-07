// Local
#include "GLMarkerFormular.h"
#include "ui_GLMarkerFormular.h"

GLMarkerFormular::GLMarkerFormular(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::GLMarkerFormular)
{
  ui->setupUi(this);
}


GLMarkerFormular::~GLMarkerFormular()
{
  delete ui;
}
