#ifndef IZLINDICATOR_H
#define IZLINDICATOR_H

// Qt
#include <QWidget>

// Local
#include "Indicator.h"

// UI
namespace Ui
{
  class IZLIndicator;
}


class IZLIndicator : public Indicator
{
  Q_OBJECT

  public:
    explicit IZLIndicator(QWidget *parent = 0);
    ~IZLIndicator();

  private:
    Ui::IZLIndicator *ui;
};

#endif // IZLINDICATOR_H
