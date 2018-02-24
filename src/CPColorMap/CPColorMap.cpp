// Local
#include "CPColorMap.h"

// Qt
#include <QDebug>


CPColorMap::CPColorMap(QCPAxis *keyAxis, QCPAxis *valueAxis)
  : QCPColorMap(keyAxis, valueAxis)
{
}



void CPColorMap::mouseMoveEvent(QMouseEvent *event, const QPointF &startPos)
{
  qDebug() << startPos << "1111" << event->x();
}


void CPColorMap::mousePressEvent(QMouseEvent *event, const QVariant &details)
{
  qDebug() << details << "22222";
}
