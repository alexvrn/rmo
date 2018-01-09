#ifndef SAINDICATOR_H
#define SAINDICATOR_H

// Qt
#include <QWidget>

// UI
namespace Ui
{
  class SAIndicator;
}

class SAIndicator : public QWidget
{
  Q_OBJECT

  public:
    explicit SAIndicator(QWidget *parent = Q_NULLPTR);
    ~SAIndicator();

  private:
    Ui::SAIndicator *ui;
};

#endif // SAINDICATOR_H
