// Local
#include "ButtonGroup.h"
#include "ui_ButtonGroup.h"

// Qt
#include <QSignalMapper>
#include <QToolButton>
#include <QDebug>


ButtonGroup::ButtonGroup(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::ButtonGroup)
  , m_mapper(new QSignalMapper(this))
{
  ui->setupUi(this);

  m_mapper = new QSignalMapper(this);
  connect(m_mapper, SIGNAL(mapped(QString)), SLOT(clicked(QString)));

  m_map["ГЛ"  ] = ui->glToolButton;
  m_map["ШП"  ] = ui->shpToolButton;
  m_map["ИТО" ] = ui->itoToolButton;
  m_map["СА"  ] = ui->saToolButton;
  m_map["АНТ" ] = ui->antToolButton;
  m_map["ИЗП" ] = ui->izpToolButton;
  m_map["АТГС"] = ui->atgsToolButton;
  m_map["ОЭ"  ] = ui->oeToolButton;
  m_map["АСТД"] = ui->astdToolButton;

  for (auto it = m_map.constBegin(); it != m_map.constEnd(); ++it)
  {
    connect(it.value(), SIGNAL(clicked()), m_mapper, SLOT(map()));
    m_mapper->setMapping(it.value(), it.key());
  }
}


ButtonGroup::~ButtonGroup()
{
  delete ui;
}


void ButtonGroup::clicked(const QString& type)
{
  QToolButton* toolButton = qobject_cast<QToolButton*>(m_mapper->mapping(type));
  Q_ASSERT(toolButton);
  for (auto it = m_map.begin(); it != m_map.end(); ++it)
  {
    if (it.value() != toolButton)
      it.value()->setChecked(false);
  }
}
