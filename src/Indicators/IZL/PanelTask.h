#ifndef PANELTASK_H
#define PANELTASK_H

// Local
#include <QWidget>

// UI
namespace Ui
{
  class PanelTask;
}

class PanelTask : public QWidget
{
  Q_OBJECT

  public:
    explicit PanelTask(QWidget *parent = 0);
    ~PanelTask();

  private:
    Ui::PanelTask *ui;
};

#endif // PANELTASK_H
