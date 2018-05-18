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

  painter->setPen(Qt::white);

  const QPointF point = coordsToPixels(m_point.x(), m_point.y());

  QPainterPath path;
  path.addEllipse(point, 5, 5);
  path.addPolygon(QPolygonF(QVector<QPointF>() << QPointF(point.x(), point.y() - 15) << QPointF(point.x(), point.y() + 15)));
  path.addPolygon(QPolygonF(QVector<QPointF>() << QPointF(point.x() - 15, point.y()) << QPointF(point.x() + 15, point.y())));
  painter->drawPath(path);
}
