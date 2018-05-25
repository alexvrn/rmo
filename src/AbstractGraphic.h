#ifndef ABSTRACTGRAPHIC_H
#define ABSTRACTGRAPHIC_H

// QCustomPlot
#include "qcustomplot.h"

class AbstractGraphic
{
  public:
    // Типы пред-индикаторной обработки
    enum PredIndicatorType
    {
      Logarithm,
      Linear,
      Marker,
      Threshold,
      GL_Reverberation,
      GL_Noise,
      PseudoLinear
    };

    // Типы индикатора
    //! TODO: перенести куда-то
    enum IndicatorType
    {
      ShP,
      SA
    };

    AbstractGraphic();
    virtual ~AbstractGraphic();

    virtual void clearData() = 0;
    virtual void setGradient(const QCPColorGradient& gradient) = 0;
    virtual void setLabel(const QString& text) = 0;
    virtual void replot(const QList<QVariantMap>& data, const QDateTime& dateTime = QDateTime()) = 0;
    virtual void setNowData(bool nowData) = 0;

    void setIndicatorType(IndicatorType indicatorType);
    IndicatorType indicatorType() const;

  private:
    IndicatorType m_indicatorType;
};

#endif // ABSTRACTGRAPHIC_H
