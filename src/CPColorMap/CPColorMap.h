#ifndef CPCOLORMAP_H
#define CPCOLORMAP_H

// QCustomPlot
#include "qcustomplot.h"

class CPColorMap : public QCPColorMap
{
  Q_OBJECT

  public:
    explicit CPColorMap(QCPAxis *keyAxis, QCPAxis *valueAxis);

    void setPoint(const QPoint& point);

  protected:
    virtual void draw(QCPPainter *painter);

  private:
    QPoint m_point;
};

#endif // CPCOLORMAP_H
