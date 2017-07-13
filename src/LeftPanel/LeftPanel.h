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

    void indicatorCheck(const QString& type, bool checked);
    void setConfiguration(const QString& type);

  signals:
    void indicatorChecked(const QString& type, bool checked);

  private slots:
    // Сохранение настроек окна
    void settingsSave(const QString& type, bool checked);

  private:
    Ui::LeftPanel *ui;

    ButtonGroup *m_group;
};

#endif // LEFTPANEL_H
