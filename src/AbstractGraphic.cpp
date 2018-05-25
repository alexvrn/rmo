// Local
#include "AbstractGraphic.h"

AbstractGraphic::AbstractGraphic()
{
}


AbstractGraphic::~AbstractGraphic()
{

}


void AbstractGraphic::setIndicatorType(IndicatorType indicatorType)
{
  m_indicatorType = indicatorType;
}


AbstractGraphic::IndicatorType AbstractGraphic::indicatorType() const
{
  return m_indicatorType;
}
