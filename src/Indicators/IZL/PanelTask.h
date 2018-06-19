#ifndef PANELTASK_H
#define PANELTASK_H

// Qt
#include <QWidget>

// Local
#include "TonalModel.h"

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

    TonalModel* m_tonalModel;
    TonalModel* m_complicatedModel;
};

#endif // PANELTASK_H
