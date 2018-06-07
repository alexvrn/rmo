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
  m_map[tr("ТО")  ] = ui->toToolButton;
  m_map[tr("СА")  ] = ui->saToolButton;
  m_map[tr("АНТ") ] = ui->antToolButton;
  m_map[tr("ИЗП") ] = ui->izpToolButton;
  m_map[tr("ЗПС")]  = ui->zpsToolButton;
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


QString ButtonGroup::indicatorCheck(const QString& type, bool checked)
{
  if (!checked)
    return currentType();

  auto toolButton = m_map.find(type);
  Q_ASSERT(toolButton != m_map.end());

  if (toolButton.value()->isChecked())
  {
    toolButton.value()->setChecked(false);
    return QString();
  }
  else
  {
    return currentType();
  }
}


QString ButtonGroup::fromOtherIndicatorChecked(const QString& type)
{
  if (type == tr("ГЛ"))
  {
    clear();
    emit otherIndicatorChecked(tr("ГЛ"), false);
    return QString();
  }
  else if ((currentType() == type || currentType() == tr("ГЛ")) || currentType().isEmpty())
  {
    for (auto it = m_map.begin(); it != m_map.end(); ++it)
    {
      if (it.key() != type && it.key() != tr("ГЛ"))
      {
        clear();
        it.value()->setChecked(true);
        emit otherIndicatorChecked(it.key(), true);
        return it.key();
      }
    }
    return QString();
  }
//  if (currentType().isEmpty())
//  {
//    for (auto it = m_map.begin(); it != m_map.end(); ++it)
//    {
//      if (it.key() != type && it.key() != tr("ГЛ"))
//      {
//    }
//  }
  else
  {
    return currentType();
  }
}


//! Установка данных из конфигурационного файла
void ButtonGroup::setConfiguration(const QString& type)
{
  for (auto it = m_map.begin(); it != m_map.end(); ++it)
    it.value()->setChecked(it.key() == type);
}


//! Нажатие на кнопку индикатора
void ButtonGroup::clicked(const QString& type)
{
  QToolButton* toolButton = qobject_cast<QToolButton*>(m_mapper->mapping(type));
  Q_ASSERT(toolButton);
  for (auto it = m_map.begin(); it != m_map.end(); ++it)
  {
    if (it.value() != toolButton)
      it.value()->setChecked(false);
  }

  emit indicatorChecked(type);
}


//! Текущий выбранный индикатор
QString ButtonGroup::currentType() const
{
  for (auto it = m_map.begin(); it != m_map.end(); ++it)
    if (it.value()->isChecked())
      return it.key();

  return QString();
}


//! Установка всех кнопок в неактивное состояние
void ButtonGroup::clear()
{
  for (auto it = m_map.begin(); it != m_map.end(); ++it)
    it.value()->setChecked(false);
}

