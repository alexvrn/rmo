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

  public Q_SLOTS:
    void setConfiguration(const QString& type, const QString& mode);
    void fromOtherIndicatorChecked(const QString& type);

  signals:
    void indicatorChecked(const QString& type);
    void currentIndicators(const QString& leftType, const QString& rightType);

    void lightMode(const QString& mode);

  private Q_SLOTS:
    void timer();
    // Сохранение настроек окна
    void settingsSave(const QString& type);

  private:
    Ui::RightPanel *ui;

    SettingRightPanel *m_settingPanel;
    ButtonGroup *m_group;
    QLabel *m_dateTimeLabel;
    QTimer *m_timer;
};

#endif // RIGHTPANEL_H
