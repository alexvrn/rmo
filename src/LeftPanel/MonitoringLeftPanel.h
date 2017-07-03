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

  private:
    Ui::MonitoringLeftPanel *ui;
};

#endif // MONITORINGLEFTPANEL_H
