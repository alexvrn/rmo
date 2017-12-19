#ifndef SHPINDICATORWIDGET_H
#define SHPINDICATORWIDGET_H

// Qt
#include <QWidget>
#include <QTimer>
#include <QVariantMap>
class QToolButton;
class QAbstractButton;

// Local
class Graphic;
#include <commandType.h>

// QCustomPlot
#include "qcustomplot.h"

// UI
namespace Ui
{
  class ShPIndicatorWidget;
}

class ShPIndicatorWidget : public QWidget
{
  Q_OBJECT

  public:
    explicit ShPIndicatorWidget(QWidget *parent = Q_NULLPTR);
    ~ShPIndicatorWidget();

    void setHasSwitch(bool hasSwitch);
    bool hasSwitch() const;

  public slots:
    void setLightMode(const QString& mode);
    void data(CommandType::Command cmd, const PgasData& value = PgasData());
    void setCurrentPgasNumber(int pgasNumber);

    void setData(const PgasData& data);
    PgasData data() const;

  signals:
    void countWidget();

  private slots:
    void colorValue(const QColor &color);
    void brightness(int value);

    void shpIndicatorView(QAbstractButton* button, bool checked);

    void on_orientationToolButton_clicked();

private:
    Ui::ShPIndicatorWidget *ui;

    Graphic* m_graphic;

    QColor m_graphColor;

    QList<QToolButton*> m_toolButtons;

    PgasData m_pgasData;
    int m_pgasNumber;
    QCPColorMap *m_colorMap;
};

#endif // SHPINDICATORWIDGET_H
