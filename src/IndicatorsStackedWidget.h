#ifndef INDICATORSSTACKEDWIDGET_H
#define INDICATORSSTACKEDWIDGET_H

// Qt
#include <QStackedWidget>
#include <QVariantMap>
#include <QStatusBar>

// Local
class ShPIndicator;
class GLIndicator;
class TOIndicator;
class SAIndicator;
class ZPSIndicator;
#include <commandType.h>
#include "Indicator.h"


class IndicatorsStackedWidget : public QStackedWidget
{
  Q_OBJECT

  public:
    IndicatorsStackedWidget(QWidget *parent = Q_NULLPTR);
    ~IndicatorsStackedWidget();

  public slots:
    void setCurrentIndicator(const QString& type);
    void setOtherCurrentIndicator(const QString& type, bool visible);
    void sync(const QString& type, bool checked);
    void setLightMode(const QString& mode);
    void newData(CommandType::Command cmd, const QVariant& value = QVariant());

   signals:
    void info(const QString& text);

  private:
    Indicator *m_nullIndicator;
    GLIndicator *m_glIndicator;
    ShPIndicator *m_shpIndicator;
    TOIndicator *m_toIndicator;
    SAIndicator *m_saIndicator;
    ZPSIndicator *m_zpsIndicator;

    QString m_type;
};

#endif // INDICATORSSTACKEDWIDGET_H
