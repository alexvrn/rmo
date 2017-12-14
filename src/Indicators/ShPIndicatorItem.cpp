// Local
#include "ShPIndicatorItem.h"
#include "ui_ShPIndicatorItem.h"
#include "ShPIndicatorWidget.h"

#include <QSplitter>

ShPIndicatorItem::ShPIndicatorItem(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::ShPIndicatorItem)
  , m_upWidget(new ShPIndicatorWidget(this))
  , m_downWidget(nullptr)
{
  ui->setupUi(this);

  m_upWidget->setHasSwitch(true);
  ui->splitter->addWidget(m_upWidget);
  connect(m_upWidget, SIGNAL(countWidget()), SLOT(countWidget()));
}


ShPIndicatorItem::~ShPIndicatorItem()
{
  delete ui;
}


void ShPIndicatorItem::setLightMode(const QString& mode)
{
  m_upWidget->setLightMode(mode);
  if (m_downWidget)
    m_downWidget->setLightMode(mode);

  if (mode == "sun")
    ui->graphic->setBackground(QBrush(QColor(180, 180, 180)));
  else if (mode == "night")
    ui->graphic->setBackground(QBrush(QColor(130, 130, 130)));
}


void ShPIndicatorItem::insertDownWidget()
{
  Q_ASSERT(!m_downWidget);

  m_downWidget = new ShPIndicatorWidget(this);
  ui->splitter->addWidget(m_downWidget);
}


void ShPIndicatorItem::deleteDownWidget()
{
  Q_ASSERT(m_downWidget);

  delete m_downWidget;
  m_downWidget = nullptr;
}


void ShPIndicatorItem::countWidget()
{
  if (m_downWidget)
    deleteDownWidget();
  else
    insertDownWidget();
}


void ShPIndicatorItem::data(int cmd, const QByteArray& value)
{
  m_upWidget->data(cmd, value);
  if (m_downWidget)
    m_downWidget->data(cmd, value);
}
