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

  signals:
    void indicatorChecked(const QString& type, bool checked);

  private slots:

  private:
    Ui::LeftPanel *ui;

    ButtonGroup *m_group;
};

#endif // LEFTPANEL_H
