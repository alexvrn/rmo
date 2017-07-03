#ifndef MONITORINGLEFTPANEL_H
#define MONITORINGLEFTPANEL_H

#include <QWidget>

namespace Ui {
class MonitoringLeftPanel;
}

class MonitoringLeftPanel : public QWidget
{
    Q_OBJECT

public:
    explicit MonitoringLeftPanel(QWidget *parent = 0);
    ~MonitoringLeftPanel();

private:
    Ui::MonitoringLeftPanel *ui;
};

#endif // MONITORINGLEFTPANEL_H
