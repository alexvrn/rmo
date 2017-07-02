#ifndef LEFTPANEL_H
#define LEFTPANEL_H

// Qt
#include <QFrame>
class QAbstractButton;

// UI
namespace Ui {
  class LeftPanel;
}

class LeftPanel : public QFrame
{
  Q_OBJECT

  public:
    explicit LeftPanel(QWidget *parent = 0);
    ~LeftPanel();

  private slots:
    void buttonToggled(QAbstractButton *button);

  private:
    Ui::LeftPanel *ui;
};

#endif // LEFTPANEL_H
