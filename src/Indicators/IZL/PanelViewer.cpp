// Local
#include "PanelViewer.h"
#include "ui_PanelViewer.h"

PanelViewer::PanelViewer(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::PanelViewer)
  , m_viewerModel(new ViewerModel(this))
{
  ui->setupUi(this);

  ui->tableView->setModel(m_viewerModel);
}


PanelViewer::~PanelViewer()
{
  delete ui;
}
