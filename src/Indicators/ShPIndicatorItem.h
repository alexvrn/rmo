#ifndef SHPINDICATORITEM_H
#define SHPINDICATORITEM_H

// Qt
#include <QWidget>

// Local
class ShPIndicatorWidget;

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

  public slots:
    void setLightMode(const QString& mode);

  private:
    Ui::ShPIndicatorItem *ui;

    ShPIndicatorWidget *m_widget;
};

#endif // SHPINDICATORITEM_H
