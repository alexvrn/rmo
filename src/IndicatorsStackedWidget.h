#ifndef INDICATORSSTACKEDWIDGET_H
#define INDICATORSSTACKEDWIDGET_H

// Qt
#include <QStackedWidget>
#include <QVariantMap>

// Local
class ShPIndicator;
class GLIndicator;
class TOIndicator;
class SAIndicator;
#include <commandType.h>


class IndicatorsStackedWidget : public QStackedWidget
{
  Q_OBJECT

  public:
    IndicatorsStackedWidget(QWidget *parent = Q_NULLPTR);
    ~IndicatorsStackedWidget();

  public slots:
    void setCurrentIndicator(const QString& type, bool checked);
    void sync(const QString& type, bool checked);
    void setLightMode(const QString& mode);
    void newData(CommandType::Command cmd, const QVariant& value = QVariant());

  private:
    QWidget *m_nullIndicator;
    GLIndicator *m_glIndicator;
    ShPIndicator *m_shpIndicator;
    TOIndicator *m_toIndicator;
    SAIndicator *m_saIndicator;

    QString m_type;
};

#endif // INDICATORSSTACKEDWIDGET_H
