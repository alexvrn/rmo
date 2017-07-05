#ifndef TOINDICATOR_H
#define TOINDICATOR_H

// Qt
#include <QWidget>

// UI
namespace Ui
{
  class TOIndicator;
}

class TOIndicator : public QWidget
{
  Q_OBJECT

  public:
    explicit TOIndicator(QWidget *parent = Q_NULLPTR);
    ~TOIndicator();

  private:
    Ui::TOIndicator *ui;
};

#endif // TOINDICATOR_H
