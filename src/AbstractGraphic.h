#ifndef ABSTRACTGRAPHIC_H
#define ABSTRACTGRAPHIC_H

// QCustomPlot
#include "qcustomplot.h"

class AbstractGraphic : public QCustomPlot
{
  Q_OBJECT

  public:
    AbstractGraphic(QWidget* parent = nullptr);

  public Q_SLOTS:
    virtual void clearData() = 0;
    virtual void setGradient(const QCPColorGradient& gradient) = 0;
};

#endif // ABSTRACTGRAPHIC_H
