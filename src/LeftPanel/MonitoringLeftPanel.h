#ifndef MONITORINGLEFTPANEL_H
#define MONITORINGLEFTPANEL_H

// Qt
#include <QWidget>

// UI
namespace Ui
{
  class MonitoringLeftPanel;
}

class MonitoringLeftPanel : public QWidget
{
  Q_OBJECT

  public:
    explicit MonitoringLeftPanel(QWidget *parent = Q_NULLPTR);
    ~MonitoringLeftPanel();

  public:
    void setResultControlComplex(int state);
    void setResultControlDevice(int state);
    void setResultControlSoft(int state);

  private:
    QString styleSheetState(int state) const;

    Ui::MonitoringLeftPanel *ui;
};

#endif // MONITORINGLEFTPANEL_H
