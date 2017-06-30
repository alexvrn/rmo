#ifndef CONTROLLEFTPANEL_H
#define CONTROLLEFTPANEL_H

// Qt
#include <QMainWindow>

// Ui
namespace Ui
{
  class ControlLeftPanel;
}


class ControlLeftPanel : public QMainWindow
{
  Q_OBJECT

  public:
    explicit ControlLeftPanel(QWidget *parent = 0);
    ~ControlLeftPanel();

  private:
    Ui::ControlLeftPanel *ui;
};

#endif // CONTROLLEFTPANEL_H
