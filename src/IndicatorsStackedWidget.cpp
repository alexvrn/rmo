// Local
#include "IndicatorsStackedWidget.h"

// Indicators
#include "ShPIndicator.h"
#include "GLIndicator.h"
#include "TOIndicator.h"
#include "SAIndicator.h"
#include "ZPSIndicator.h"

// Qt
#include <QDebug>


IndicatorsStackedWidget::IndicatorsStackedWidget(QWidget *parent)
  : QStackedWidget(parent)
  , m_nullIndicator(new Indicator(this))
  , m_glIndicator(new GLIndicator(this))
  , m_shpIndicator(new ShPIndicator(this))
  , m_toIndicator(new TOIndicator(this))
  , m_saIndicator(new SAIndicator(this))
  , m_zpsIndicator(new ZPSIndicator(this))
{
  addWidget(m_nullIndicator);
  addWidget(m_glIndicator);
  addWidget(m_shpIndicator);
  addWidget(m_toIndicator);
  addWidget(m_saIndicator);
  addWidget(m_zpsIndicator);

  for (int i = 0; i < count(); i++)
    connect(qobject_cast<Indicator*>(widget(i)), SIGNAL(info(QString)), this, SIGNAL(info(QString)));

  setCurrentWidget(m_nullIndicator);
}


IndicatorsStackedWidget::~IndicatorsStackedWidget()
{

}


void IndicatorsStackedWidget::setCurrentIndicator(const QString& type)
{
  if (type.isEmpty())
  {
    hide();
    return;
  }

  // Т.к. индикатор могли сделать невидимым в других операциях
  show();

  if (type == tr("ГЛ"))
    setCurrentWidget(m_glIndicator);
  else if (type == tr("ШП"))
    setCurrentWidget(m_shpIndicator);
  else if (type == tr("ТО"))
    setCurrentWidget(m_toIndicator);
  else if (type == tr("СА"))
    setCurrentWidget(m_saIndicator);
  else if (type == tr("ЗПС"))
    setCurrentWidget(m_zpsIndicator);
  else
    setCurrentWidget(m_nullIndicator);

  m_type = type;
}


void IndicatorsStackedWidget::setOtherCurrentIndicator(const QString& type, bool visible)
{
  setCurrentIndicator(type);

  // Фишка для работы с ГЛ
  if (!visible)
  {
    hide();
    return;
  }
  else
  {
    show();
  }
}


//! TODO: Сделать красиво.
void IndicatorsStackedWidget::sync(const QString& type, bool checked)
{
  if (checked)
  {
    if (m_type == type && m_type != tr("ГЛ"))
    {
      setCurrentWidget(m_nullIndicator);
      m_type = QString();
    }
  }
}


void IndicatorsStackedWidget::setLightMode(const QString& mode)
{
  m_shpIndicator->setLightMode(mode);
}


void IndicatorsStackedWidget::newData(CommandType::Command cmd, const QVariant& value)
{
  m_shpIndicator->newData(cmd, value);
}

