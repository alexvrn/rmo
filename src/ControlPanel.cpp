// Local
#include "ControlPanel.h"

// Qt
#include <QCloseEvent>

ControlPanel::ControlPanel(QWidget *parent)
  : QMainWindow(parent)
  , m_indicatorsStackedWidget(new IndicatorsStackedWidget(this))
  , m_toolBar(new QToolBar(this))
{
  m_toolBar->setMovable(false);
  addToolBar(Qt::TopToolBarArea, m_toolBar);
}


ControlPanel::~ControlPanel()
{

}


void ControlPanel::closeEvent(QCloseEvent *e)
{
  e->ignore();
}
