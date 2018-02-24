#ifndef CPCOLORMAP_H
#define CPCOLORMAP_H

// QCustomPlot
#include "qcustomplot.h"


class CPColorMap : public QCPColorMap
{
  Q_OBJECT

  public:
    explicit CPColorMap(QCPAxis *keyAxis, QCPAxis *valueAxis);

  protected:
    virtual void mouseMoveEvent(QMouseEvent *event, const QPointF &startPos);
    virtual void mousePressEvent(QMouseEvent *event, const QVariant &details);
};

#endif // CPCOLORMAP_H
