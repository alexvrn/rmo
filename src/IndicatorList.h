#ifndef INDICATORLIST_H
#define INDICATORLIST_H

// Qt
#include <QWidget>
#include <QVariantMap>
#include <QStatusBar>

// Local
class ShPIndicator;
class GLIndicator;
class TOIndicator;
class SAIndicator;
class ZPSIndicator;
class IZLIndicator;
#include <commandType.h>
#include "Indicator.h"


namespace Ui
{
  class IndicatorList;
}

class IndicatorList : public QWidget
{
  Q_OBJECT

  public:
    explicit IndicatorList(QWidget *parent = 0);
    ~IndicatorList();

  public slots:
    void setCurrentIndicators(const QString& leftType, const QString& rightType);
    void setLightMode(const QString& mode);
    void newData(CommandType::Command cmd, const QVariant& value = QVariant());

  signals:
    void info(const QString& text);

  private:
    Ui::IndicatorList *ui;

    QWidget *m_nullIndicator;
    GLIndicator *m_glIndicator;
    ShPIndicator *m_shpIndicator;
    TOIndicator *m_toIndicator;
    SAIndicator *m_saIndicator;
    ZPSIndicator *m_zpsIndicator;
    IZLIndicator *m_izlIndicator;

    Indicator* m_leftIndicator;
    Indicator* m_rightIndicator;

    QHash<QString, Indicator*> m_indicators;
    QString m_type;
};

#endif // INDICATORLIST_H
