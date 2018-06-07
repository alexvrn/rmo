#ifndef GLMARKERFORMULAR_H
#define GLMARKERFORMULAR_H

#include <QWidget>

namespace Ui {
class GLMarkerFormular;
}

class GLMarkerFormular : public QWidget
{
    Q_OBJECT

public:
    explicit GLMarkerFormular(QWidget *parent = 0);
    ~GLMarkerFormular();

private:
    Ui::GLMarkerFormular *ui;
};

#endif // GLMARKERFORMULAR_H
