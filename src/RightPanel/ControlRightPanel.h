#ifndef CONTROLRIGHTPANEL_H
#define CONTROLRIGHTPANEL_H

// Local
class RightPanel;
#include "ControlPanel.h"

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
    void showWindow(bool show);

    void lightMode(const QString& mode);

  public slots:
    void indicatorCheck(const QString& type, bool checked);

  private slots:
    void setLightMode(const QString& mode);

  private:
    Ui::ControlRightPanel *ui;

    RightPanel *m_panel;
    //QSystemTrayIcon *m_trayIcon;
};

#endif // CONTROLRIGHTPANEL_H
