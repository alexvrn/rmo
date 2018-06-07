// Local
#include "GLIndicator.h"
#include "ui_GLIndicator.h"
#include "GLIndicatorWidget.h"

GLIndicator::GLIndicator(QWidget *parent)
  : Indicator(parent)
  , ui(new Ui::GLIndicator)
  , m_upWidget(new GLIndicatorWidget(this))
  , m_downWidget(nullptr)
{
  ui->setupUi(this);

  connect(m_upWidget, &GLIndicatorWidget::info, this, &GLIndicator::info);

  m_upWidget->setHasSwitch(true);
  ui->splitter->addWidget(m_upWidget);
  connect(m_upWidget, SIGNAL(countWidget()), SLOT(countWidget()));
}


GLIndicator::~GLIndicator()
{
  delete ui;
}


void GLIndicator::deleteDownWidget()
{
  Q_ASSERT(m_downWidget);

  disconnect(m_downWidget, 0, 0, 0);
  delete m_downWidget;
  m_downWidget = nullptr;
}


void GLIndicator::countWidget()
{
  if (m_downWidget)
    deleteDownWidget();
  else
    insertDownWidget();
}


void GLIndicator::insertDownWidget()
{
  Q_ASSERT(!m_downWidget);

  m_downWidget = new GLIndicatorWidget(this);
  //m_downWidget->setCurrentPgasNumber(m_upWidget->currentPgasNumber());
  //connect(m_downWidget, &ShPIndicatorWidget::info, this, &ShPIndicatorItem::info);

  ui->splitter->addWidget(m_downWidget);
}
