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
    void newData(bool update = false);
    void setCurrentPgasNumber(int pgasNumber);
    int currentPgasNumber() const;
    void setNowData(bool nowData);
    bool isNowData() const;
    void setSelectedData(const PgasData& selectedData, const QDateTime& checkDateTime = QDateTime());

  signals:
    void countWidget();

  private slots:
    void shpIndicatorView(QAbstractButton* button, bool checked);
    void dataRepaint();

private:
    Ui::ShPIndicatorWidget *ui;

    Graphic* m_graphic;

    QColor m_graphColor;

    QList<QToolButton*> m_toolButtons;

    int m_pgasNumber;
    QButtonGroup* m_buttonGroup;

    bool m_nowData;
    PgasData m_selectedData;

    int m_seconds;
    QDateTime m_checkDateTime;

    QTimer m_replotTimer;
};

#endif // SHPINDICATORWIDGET_H
