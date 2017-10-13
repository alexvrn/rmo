#ifndef SHPINDICATORWIDGET_H
#define SHPINDICATORWIDGET_H

// Qt
#include <QWidget>
#include <QTimer>
class QToolButton;

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
    void data(double key, double value);

  private slots:
    void colorValue(const QColor &color);
    void brightness(int value);

    void shpIndicatorView();

private:
    Ui::ShPIndicatorWidget *ui;

    QColor m_graphColor;

    QList<QToolButton*> m_toolButtons;
};

#endif // SHPINDICATORWIDGET_H
