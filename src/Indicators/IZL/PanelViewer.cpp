// Local
#include "PanelViewer.h"
#include "ui_PanelViewer.h"

PanelViewer::PanelViewer(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::PanelViewer)
{
  ui->setupUi(this);
}


PanelViewer::~PanelViewer()
{
  delete ui;
}
