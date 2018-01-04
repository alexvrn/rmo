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
    void newData();
    void setCurrentPgasNumber(int pgasNumber);
    int currentPgasNumber() const;
    void setNowData(bool nowData);
    bool isNowData() const;
    void setSelectedData(const PgasData& selectedData);

  signals:
    void countWidget();

  private slots:
    void colorValue(const QColor &color);
    void brightness(int value);
    void setGradient(int value);

    void shpIndicatorView(QAbstractButton* button, bool checked);

    void on_orientationToolButton_clicked();

    void vertScrollBarChanged(int value);
    void yAxisChanged(QCPRange range);

    void on_toolButtonGrid_toggled(bool checked);

private:
    void dataRepaint();

    Ui::ShPIndicatorWidget *ui;

    Graphic* m_graphic;

    QColor m_graphColor;

    QList<QToolButton*> m_toolButtons;

    int m_pgasNumber;
    QButtonGroup* m_buttonGroup;

    QCPColorMap *m_colorMap;

    bool m_nowData;
    PgasData m_selectedData;
};

#endif // SHPINDICATORWIDGET_H
