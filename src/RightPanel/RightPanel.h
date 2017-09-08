#ifndef RIGHTPANEL_H
#define RIGHTPANEL_H

// Qt
#include <QFrame>
class QTimer;
class QLabel;

// Local
class ButtonGroup;
class SettingRightPanel;

// UI
namespace Ui {
  class RightPanel;
}

class RightPanel : public QFrame
{
  Q_OBJECT

  public:
    explicit RightPanel(QWidget *parent = Q_NULLPTR);
    ~RightPanel();

    void indicatorCheck(const QString& type, bool checked);
    void setConfiguration(const QString& type, const QString& mode);

  signals:
    void indicatorChecked(const QString& type, bool checked);

    void nightMode();
    void sunMode();

  private slots:
    void timer();
    // Сохранение настроек окна
    void settingsSave(const QString& type, bool checked);

  private:
    Ui::RightPanel *ui;

    SettingRightPanel *m_settingPanel;
    ButtonGroup *m_group;
    QLabel *m_dateTimeLabel;
    QTimer *m_timer;
};

#endif // RIGHTPANEL_H
