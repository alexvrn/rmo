#ifndef GLINDICATOR_H
#define GLINDICATOR_H

// Qt
#include <QWidget>

// UI
namespace Ui
{
  class GLIndicator;
}

class GLIndicator : public QWidget
{
  Q_OBJECT

  public:
    explicit GLIndicator(QWidget *parent = Q_NULLPTR);
    ~GLIndicator();

  private:
    Ui::GLIndicator *ui;
};

#endif // GLINDICATOR_H
