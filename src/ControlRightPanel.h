#ifndef CONTROLRIGHTPANEL_H
#define CONTROLRIGHTPANEL_H

// Qt
#include <QMainWindow>

// Ui
namespace Ui
{
  class ControlRightPanel;
}


class ControlRightPanel : public QMainWindow
{
  Q_OBJECT

  public:
    explicit ControlRightPanel(QWidget *parent = 0);
    ~ControlRightPanel();

  private:
    Ui::ControlRightPanel *ui;
};

#endif // CONTROLRIGHTPANEL_H
