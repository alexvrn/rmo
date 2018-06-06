#ifndef LEFTPANEL_H
#define LEFTPANEL_H

// Qt
#include <QFrame>
class QAbstractButton;

// Local
class ButtonGroup;

// UI
namespace Ui {
  class LeftPanel;
}

class LeftPanel : public QFrame
{
  Q_OBJECT

  public:
    explicit LeftPanel(QWidget *parent = Q_NULLPTR);
    ~LeftPanel();

  public slots:
    void indicatorCheck(const QString& type, bool checked);
    void setConfiguration(const QString& type);
    void fromOtherIndicatorChecked(const QString& type);

  signals:
    void indicatorChecked(const QString& type);
    void otherIndicatorChecked(const QString& type, bool visible = true);

  private slots:
    // Сохранение настроек окна
    void settingsSave(const QString& type);

  private:
    Ui::LeftPanel *ui;

    ButtonGroup *m_group;
};

#endif // LEFTPANEL_H
