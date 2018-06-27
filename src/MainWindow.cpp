// Local
#include "MainWindow.h"
#include "LeftPanel.h"
#include "RightPanel.h"
#include "IndicatorList.h"

// Qt
#include <QDebug>
#include <QApplication>
#include <QCloseEvent>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , m_toolBar(new QToolBar(this))
  , m_leftPanel(new LeftPanel(this))
  , m_rightPanel(new RightPanel(this))
  , m_indicatorList(new IndicatorList(this))
  //, m_leftIndicatorsStackedWidget(new IndicatorsStackedWidget(this))
  //, m_rightIndicatorsStackedWidget(new IndicatorsStackedWidget(this))
{
  m_toolBar->setMovable(false);
  addToolBar(Qt::TopToolBarArea, m_toolBar);
  m_toolBar->setMovable(true);
  m_toolBar->addWidget(m_leftPanel);
  m_toolBar->addWidget(m_rightPanel);

  //connect(m_leftPanel, &LeftPanel::indicatorChecked, m_leftIndicatorsStackedWidget, &IndicatorsStackedWidget::setCurrentIndicator);
  //connect(m_rightPanel, &RightPanel::indicatorChecked, m_rightIndicatorsStackedWidget, &IndicatorsStackedWidget::setCurrentIndicator);

  //connect(m_leftPanel, &LeftPanel::otherIndicatorChecked, m_leftIndicatorsStackedWidget, &IndicatorsStackedWidget::setOtherCurrentIndicator);
  //connect(m_rightPanel, &RightPanel::otherIndicatorChecked, m_rightIndicatorsStackedWidget, &IndicatorsStackedWidget::setOtherCurrentIndicator);

  connect(m_leftPanel, &LeftPanel::currentIndicators, m_indicatorList, &IndicatorList::setCurrentIndicators);
  connect(m_rightPanel, &RightPanel::currentIndicators, m_indicatorList, &IndicatorList::setCurrentIndicators);

  connect(m_leftPanel, &LeftPanel::indicatorChecked, m_rightPanel, &RightPanel::fromOtherIndicatorChecked);
  connect(m_rightPanel, &RightPanel::indicatorChecked, m_leftPanel, &LeftPanel::fromOtherIndicatorChecked);
  //QObject::connect(&controlRightPanel, &ControlRightPanel::showWindow, &controlLeftPanel, &ControlLeftPanel::setVisible);
  //QObject::connect(&controlRightPanel, &ControlRightPanel::lightMode, &controlLeftPanel, &ControlLeftPanel::setLightMode);

  QWidget* centralWidget = new QWidget(this);
  QHBoxLayout* hLayout = new QHBoxLayout(centralWidget);
  hLayout->addWidget(m_indicatorList);
  //hLayout->addWidget(m_leftIndicatorsStackedWidget);
  //hLayout->addWidget(m_rightIndicatorsStackedWidget);
  setCentralWidget(centralWidget);

  qApp->installEventFilter(this);
}


MainWindow::~MainWindow()
{

}


void MainWindow::setConnectState(bool connect)
{

}


void MainWindow::setConfiguration(const QString& leftType, const QString& rightType, const QString& mode)
{
  // Производим установку слева направо.
  // leftConfig - используем для правого индикатора для корректного отображения выбора кнопок,
  // вслучае некорректных записей в config-файле
  QString leftConfig = m_leftPanel->setConfiguration(leftType);
  QString rightConfig = m_rightPanel->setConfiguration(rightType, QStringList() << leftConfig, mode);

  m_indicatorList->setCurrentIndicators(leftConfig, rightConfig);
}


void MainWindow::newData(cmd_e cmd, const QVariant& value)
{
  m_indicatorList->newData(cmd, value);
}


void MainWindow::closeEvent(QCloseEvent *e)
{
  e->ignore();
}


bool MainWindow::eventFilter(QObject *obj, QEvent *event)
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

