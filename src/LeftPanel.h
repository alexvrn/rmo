#ifndef LEFTPANEL_H
#define LEFTPANEL_H

#include <QFrame>

namespace Ui {
class LeftPanel;
}

class LeftPanel : public QFrame
{
    Q_OBJECT

public:
    explicit LeftPanel(QWidget *parent = 0);
    ~LeftPanel();

private:
    Ui::LeftPanel *ui;
};

#endif // LEFTPANEL_H
