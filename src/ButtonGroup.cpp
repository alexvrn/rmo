// Local
#include "ButtonGroup.h"
#include "ui_ButtonGroup.h"

// Qt
#include <QSignalMapper>
#include <QToolButton>
#include <QDebug>


ButtonGroup::ButtonGroup(SideType sideType, QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::ButtonGroup)
  , m_mapper(new QSignalMapper(this))
  , m_sideType(sideType)
{
  ui->setupUi(this);

  m_map[tr("ГЛ")  ] = ui->glToolButton;
  m_map[tr("ШП")  ] = ui->shpToolButton;
  m_map[tr("ТО")  ] = ui->toToolButton;
  m_map[tr("СА")  ] = ui->saToolButton;
  m_map[tr("АНТ") ] = ui->antToolButton;
  m_map[tr("ИЗЛ") ] = ui->izlToolButton;
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


QString ButtonGroup::fromOtherIndicatorChecked(const QString& type)
{
  if (type == tr("ГЛ"))
  {
    clear();
    if (m_sideType == SideType::Left)
      emit currentIndicators(QString(), tr("ГЛ"));
    else
      emit currentIndicators(tr("ГЛ"), QString());
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

        if (m_sideType == SideType::Left)
          emit currentIndicators(it.key(), type);
        else
          emit currentIndicators(type, it.key());
        return it.key();
      }
    }
    return QString();
  }
  else
  {
    if (m_sideType == SideType::Left)
      emit currentIndicators(currentType(), type);
    else
      emit currentIndicators(type, currentType());
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

  // Кнопка отключается при повторном нажатии. Поэтому в любом случае делаем её активной
  //! TODO: Хотя надо более красивое решение. Например переопределить какой-то метод. Но пока та :)
  toolButton->setChecked(true);

  // Отключаем все кнопки, кроме той, на которую нажали
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

