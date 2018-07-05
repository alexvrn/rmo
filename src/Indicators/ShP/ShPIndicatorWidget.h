#ifndef SHPINDICATORWIDGET_H
#define SHPINDICATORWIDGET_H

// Qt
#include <QWidget>
#include <QVariantMap>
class QToolButton;
class QAbstractButton;

// Local
class Graphic;
#include "AbstractGraphic.h"

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
    void info(const QString& text);
    void sectionData(const QVector<double>& keys, const QVector<double>& values);

  private slots:
    void shpIndicatorView(QAbstractButton* button, bool checked);
    void setIndicatorType(AbstractGraphic::IndicatorType indicatorType);
    void setData(const QList<QVariantMap> &data, const QDateTime& dateTime = QDateTime());
    void clearData();
    void setDataType(const QString& text, cmd_e type);
    void dataGraphicRepaint();
    void visorClick(int beamCount, const QTime& time);

private:
    Ui::ShPIndicatorWidget *ui;

    QColor m_graphColor;

    QList<QToolButton*> m_toolButtons;

    int m_pgasNumber;
    QButtonGroup* m_buttonGroup;

    bool m_nowData;
    PgasData m_selectedData;

    int m_seconds;
    QDateTime m_checkDateTime;
    QList<QVariantMap> m_data;

    QList<AbstractGraphic*> m_graphics;
    // Текущий график
    AbstractGraphic* m_graphic;

    cmd_e m_type; //! TODO: нужна ли эта переменная
};

#endif // SHPINDICATORWIDGET_H
