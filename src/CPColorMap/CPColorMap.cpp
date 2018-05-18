// Local
#include "CPColorMap.h"

// Qt
#include <QDebug>

CPColorMap::CPColorMap(QCPAxis *keyAxis, QCPAxis *valueAxis)
  : QCPColorMap(keyAxis, valueAxis)
{
}


void CPColorMap::setPoint(const QPoint& point)
{
  m_point = point;
}


void CPColorMap::draw(QCPPainter *painter)
{
  QCPColorMap::draw(painter);

  painter->setPen(Qt::red);

  const QPointF point = coordsToPixels(m_point.x(), m_point.y());
  painter->drawRect(point.x()-5, point.y()-5, 5, 5);
}
