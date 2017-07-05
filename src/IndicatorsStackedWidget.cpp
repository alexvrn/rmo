// Local
#include "IndicatorsStackedWidget.h"

// Indicators
#include "ShPIndicator.h"
#include "GLIndicator.h"
#include "TOIndicator.h"
#include "SAIndicator.h"

// Qt
#include <QDebug>


IndicatorsStackedWidget::IndicatorsStackedWidget(QWidget *parent)
  : QStackedWidget(parent)
  , m_nullIndicator(new QWidget(this))
  , m_glIndicator(new GLIndicator(this))
  , m_shpIndicator(new ShPIndicator(this))
  , m_toIndicator(new TOIndicator(this))
  , m_saIndicator(new SAIndicator(this))
{
  addWidget(m_nullIndicator);
  addWidget(m_glIndicator);
  addWidget(m_shpIndicator);
  addWidget(m_toIndicator);
  addWidget(m_saIndicator);

  setCurrentWidget(m_nullIndicator);
}


IndicatorsStackedWidget::~IndicatorsStackedWidget()
{

}


void IndicatorsStackedWidget::setCurrentIndicator(const QString& type, bool checked)
{
  if (checked)
  {
    if (type == tr("ГЛ"))
      setCurrentWidget(m_glIndicator);
    else if (type == tr("ШП"))
      setCurrentWidget(m_shpIndicator);
    else if (type == tr("ТО"))
      setCurrentWidget(m_toIndicator);
    else if (type == tr("СА"))
      setCurrentWidget(m_saIndicator);

    m_type = type;
  }
  else
  {
    setCurrentWidget(m_nullIndicator);
    m_type = QString();
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
