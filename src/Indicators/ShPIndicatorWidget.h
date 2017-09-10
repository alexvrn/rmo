#ifndef SHPINDICATORWIDGET_H
#define SHPINDICATORWIDGET_H

// Qt
#include <QWidget>
#include <QTimer>

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

  public slots:
    void setLightMode(const QString& mode);

  private slots:
    void colorValue(const QColor &color);
    void realtimeDataSlot();

    void brightness(int value);

  private:
    Ui::ShPIndicatorWidget *ui;

    QTimer dataTimer;
    QColor m_graphColor;
};

#endif // SHPINDICATORWIDGET_H
