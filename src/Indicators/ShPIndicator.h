#ifndef SHPINDICATOR_H
#define SHPINDICATOR_H

// Qt
#include <QWidget>

// Local
class ShPIndicatorItem;

// UI
namespace Ui
{
  class ShPIndicator;
}

class ShPIndicator : public QWidget
{
  Q_OBJECT

  public:
    explicit ShPIndicator(QWidget *parent = Q_NULLPTR);
    ~ShPIndicator();

  public slots:
    void setLightMode(const QString& mode);

  private:
    Ui::ShPIndicator *ui;

    ShPIndicatorItem *indicatorItem1;
    ShPIndicatorItem *indicatorItem2;
};

#endif // SHPINDICATOR_H
