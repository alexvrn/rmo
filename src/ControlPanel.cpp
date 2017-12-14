// Local
#include "ControlPanel.h"

// Qt
#include <QCloseEvent>
#include <QDebug>
#include <QApplication>

ControlPanel::ControlPanel(QWidget *parent)
  : QMainWindow(parent)
  , m_indicatorsStackedWidget(new IndicatorsStackedWidget(this))
  , m_toolBar(new QToolBar(this))
{
  m_toolBar->setMovable(false);
  addToolBar(Qt::TopToolBarArea, m_toolBar);
  m_toolBar->setMovable(true);

  qApp->installEventFilter(this);
}


ControlPanel::~ControlPanel()
{

}


void ControlPanel::setConnectState(bool connect)
{

}


void ControlPanel::data(CommandType::Command cmd, const QByteArray& value)
{
  m_indicatorsStackedWidget->data(cmd, value);
}


void ControlPanel::closeEvent(QCloseEvent *e)
{
  e->ignore();
}


bool ControlPanel::eventFilter(QObject *obj, QEvent *event)
{
  if (obj == this && event->type() == QEvent::KeyPress)
  {
    //QKeyEvent* e = static_cast<QKeyEvent*>(event);
    //Qt::KeyboardModifiers keyMod = QApplication::keyboardModifiers();
    //bool isAlt = keyMod.testFlag(Qt::AltModifier);
    //if (isAlt)
    //if (e->modifiers() & Qt::AltModifier)
    //  qDebug() << "111111";
    //emit windowDeactivate();
  }

  return QMainWindow::eventFilter(obj, event);
}
