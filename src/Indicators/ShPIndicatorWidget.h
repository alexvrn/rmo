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

  private slots:
    void colorValue(const QColor &color);
    void realtimeDataSlot();

  private:
    Ui::ShPIndicatorWidget *ui;

    QTimer dataTimer;
};

#endif // SHPINDICATORWIDGET_H
