#ifndef GLMARKERFORMULAR_H
#define GLMARKERFORMULAR_H

// Qt
#include <QWidget>

// UI
namespace Ui
{
  class GLMarkerFormular;
}

class GLMarkerFormular : public QWidget
{
  Q_OBJECT

  public:
    explicit GLMarkerFormular(QWidget *parent = nullptr);
    ~GLMarkerFormular();

  private:
    Ui::GLMarkerFormular *ui;
};

#endif // GLMARKERFORMULAR_H
