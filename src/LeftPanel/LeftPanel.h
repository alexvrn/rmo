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
    explicit LeftPanel(QWidget *parent = Q_NULLPTR);
    ~LeftPanel();

  private slots:

  private:
    Ui::LeftPanel *ui;
};

#endif // LEFTPANEL_H
