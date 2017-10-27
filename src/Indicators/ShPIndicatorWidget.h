#ifndef SHPINDICATORWIDGET_H
#define SHPINDICATORWIDGET_H

// Qt
#include <QWidget>
#include <QTimer>
class QToolButton;
class QAbstractButton;

// Local
class Graphic;

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

    void shpIndicatorView(QAbstractButton* button, bool checked);

    void on_orientationToolButton_clicked();

private:
    Ui::ShPIndicatorWidget *ui;

    Graphic* m_graphic;

    QColor m_graphColor;

    QList<QToolButton*> m_toolButtons;
};

#endif // SHPINDICATORWIDGET_H
