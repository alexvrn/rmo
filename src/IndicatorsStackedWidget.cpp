// Local
#include "IndicatorsStackedWidget.h"

// Indicators
#include "ShPIndicator.h"
#include "GLIndicator.h"


IndicatorsStackedWidget::IndicatorsStackedWidget(QWidget *parent)
  : QStackedWidget(parent)
  , m_nullIndicator(new QWidget(this))
  , m_glIndicator(new GLIndicator(this))
  , m_shpIndicator(new ShPIndicator(this))
{
  addWidget(m_nullIndicator);
  addWidget(m_glIndicator);
  addWidget(m_shpIndicator);

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
  }
  else
  {
    setCurrentWidget(m_nullIndicator);
  }
}
