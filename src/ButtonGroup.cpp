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

  m_map[tr("ГЛ")  ] = ui->glToolButton;
  m_map[tr("ШП")  ] = ui->shpToolButton;
  m_map[tr("ИТО") ] = ui->itoToolButton;
  m_map[tr("СА")  ] = ui->saToolButton;
  m_map[tr("АНТ") ] = ui->antToolButton;
  m_map[tr("ИЗП") ] = ui->izpToolButton;
  m_map[tr("АТГС")] = ui->atgsToolButton;
  m_map[tr("ОЭ")  ] = ui->oeToolButton;
  m_map[tr("АСТД")] = ui->astdToolButton;

  connect(m_mapper, SIGNAL(mapped(QString)), SLOT(clicked(QString)));

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


void ButtonGroup::indicatorCheck(const QString& type, bool checked)
{
  if (!checked)
    return;

  auto toolButton = m_map.find(type);
  Q_ASSERT(toolButton != m_map.end());

  if (toolButton.value()->isChecked())
    toolButton.value()->setChecked(false);
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

  emit indicatorChecked(type, toolButton->isChecked());
}
