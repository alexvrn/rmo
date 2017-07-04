#ifndef SHPINDICATOR_H
#define SHPINDICATOR_H

// Qt
#include <QWidget>

// UI
namespace Ui
{
  class ShPIndicator;
}

class ShPIndicator : public QWidget
{
  Q_OBJECT

  public:
    explicit ShPIndicator(QWidget *parent = 0);
    ~ShPIndicator();

  private:
    Ui::ShPIndicator *ui;
};

#endif // SHPINDICATOR_H
