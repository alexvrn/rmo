// Local
#include "GLSection.h"
#include "ui_GLSection.h"

// QCustomPlot
#include "qcustomplot.h"


GLSection::GLSection(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::GLSection)
{
  ui->setupUi(this);

  ui->graphic1->setBackground(QBrush(Qt::black));
  ui->graphic2->setBackground(QBrush(Qt::black));
  ui->graphic3->setBackground(QBrush(Qt::black));
}


GLSection::~GLSection()
{
  delete ui;
}
