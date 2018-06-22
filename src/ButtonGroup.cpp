// Local
#include "ButtonGroup.h"
#include "ui_ButtonGroup.h"

// Qt
#include <QSignalMapper>
#include <QToolButton>
#include <QSettings>
#include <QDebug>


ButtonGroup::ButtonGroup(SideType sideType, QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::ButtonGroup)
  , m_mapper(new QSignalMapper(this))
  , m_sideType(sideType)
{
  ui->setupUi(this);

  QHash<QPair<QString,QToolButton*>, QString> names = QHash<QPair<QString,QToolButton*>, QString>
  {
    { qMakePair(tr("ГЛ"),   ui->glToolButton),   "HydroLocation" },
    { qMakePair(tr("ШП"),   ui->shpToolButton),  "NoiseControl" },
    { qMakePair(tr("ТО"),   ui->toToolButton),   "TacticalSituation" },
    { qMakePair(tr("СА"),   ui->saToolButton),   "SpectralAnalysis" },
    { qMakePair(tr("АНТ"),  ui->antToolButton),  "AntennaChannel" },
    { qMakePair(tr("ИЗЛ"),  ui->izlToolButton),  "Radiation" },
    { qMakePair(tr("ЗПС"),  ui->zpsToolButton),  "SoundCommunication" },
    { qMakePair(tr("ОЭ"),   ui->oeToolButton),   "EfficiencyMark" },
    { qMakePair(tr("АСТД"), ui->astdToolButton), "FunctionalDiagnosticsComplex" }
  };

  // Делаем все кнопки невидимыми
  for (auto key : names.keys())
    key.second->hide();

  QSettings settings("SAMI_DVO_RAN", "rmo");
  for (auto indicatorName : names.values())
  {
    bool exists = settings.value(QString("Indicators/%1").arg(indicatorName), false).toBool();
    if (exists)
    {
      m_map[names.key(indicatorName).first] = names.key(indicatorName).second;
      names.key(indicatorName).second->show();
    }
  }

  Q_ASSERT_X(m_map.count() >= 2, "ButtonGroup", "Количество индикаторов должно быть минимум два");

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
QString ButtonGroup::setConfiguration(const QString& type, const QStringList& filter)
{
  if (type.isEmpty())
  {
    clear();
    return QString();
  }
  if (m_map.contains(type))
  {
    for (auto it = m_map.begin(); it != m_map.end(); ++it)
      it.value()->setChecked(it.key() == type);
    return type;
  }
  else
  {
    // Если список не содержит выбранного типа индикатора, то пытаемся найти первый подходящий,
    // кроме индикаторов, входящий в список filter
    // Защита от некорректного config-файла
    clear();
    QString newType;
    for (auto it = m_map.begin(); it != m_map.end(); ++it)
    {
      if (!filter.contains(it.key()) && (it.key() != tr("ГЛ")))
      {
        newType = it.key();
        break;
      }
    }
    return newType;
  }
}


//! Нажатие на кнопку индикатора
void ButtonGroup::clicked(const QString& type)
{
  QToolButton* toolButton = qobject_cast<QToolButton*>(m_mapper->mapping(type));
  Q_ASSERT(toolButton);

  // Кнопка отключается при повторном нажатии. Поэтому в любом случае делаем её активной
  //! TODO: Хотя надо более красивое решение. Например переопределить какой-то метод. Но пока так :)
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

