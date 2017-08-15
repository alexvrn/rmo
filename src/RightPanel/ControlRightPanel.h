#ifndef CONTROLRIGHTPANEL_H
#define CONTROLRIGHTPANEL_H

// Local
class RightPanel;
#include "ControlPanel.h"
#include "AuthDialog.h"

// Qt
class QSystemTrayIcon;

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

    void setConfiguration(const QString& type, const QString& mode = QString()) Q_DECL_OVERRIDE;

  signals:
    void indicatorChecked(const QString& type, bool checked);

  public slots:
    void indicatorCheck(const QString& type, bool checked);

  private:
    Ui::ControlRightPanel *ui;

    RightPanel *m_panel;
    AuthDialog m_authDialog;
    //QSystemTrayIcon *m_trayIcon;
};

#endif // CONTROLRIGHTPANEL_H
