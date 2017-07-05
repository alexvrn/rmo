#ifndef CONTROLRIGHTPANEL_H
#define CONTROLRIGHTPANEL_H

// Local
class RightPanel;
#include "ControlPanel.h"

// Ui
namespace Ui
{
  class ControlRightPanel;
}


class ControlRightPanel : public ControlPanel
{
  Q_OBJECT

  public:
    explicit ControlRightPanel(QWidget *parent = Q_NULLPTR);
    ~ControlRightPanel();

  signals:
    void indicatorChecked(const QString& type, bool checked);

  public slots:
    void indicatorCheck(const QString& type, bool checked);

  private:
    Ui::ControlRightPanel *ui;

    RightPanel *m_panel;
};

#endif // CONTROLRIGHTPANEL_H
