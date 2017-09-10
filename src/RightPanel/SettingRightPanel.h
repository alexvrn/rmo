#ifndef SETTINGRIGHTPANEL_H
#define SETTINGRIGHTPANEL_H

// Qt
#include <QWidget>

// UI
namespace Ui
{
  class SettingRightPanel;
}

class SettingRightPanel : public QWidget
{
  Q_OBJECT

  public:
    explicit SettingRightPanel(QWidget *parent = Q_NULLPTR);
    ~SettingRightPanel();

    void setConfiguration(const QString& mode);

  signals:
    void lightMode(const QString& mode);

  private slots:
    void on_exitToolButton_clicked();
    void modeChecked(const QString& mode);

private:
    Ui::SettingRightPanel *ui;
};

#endif // SETTINGRIGHTPANEL_H
