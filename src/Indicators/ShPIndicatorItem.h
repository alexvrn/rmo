#ifndef SHPINDICATORITEM_H
#define SHPINDICATORITEM_H

// Qt
#include <QWidget>

// UI
namespace Ui
{
  class ShPIndicatorItem;
}

class ShPIndicatorItem : public QWidget
{
  Q_OBJECT

  public:
    explicit ShPIndicatorItem(QWidget *parent = Q_NULLPTR);
    ~ShPIndicatorItem();

  private:
    Ui::ShPIndicatorItem *ui;
};

#endif // SHPINDICATORITEM_H
