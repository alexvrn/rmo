#ifndef RIGHTPANEL_H
#define RIGHTPANEL_H

// Qt
#include <QFrame>
class QTimer;

// UI
namespace Ui {
  class RightPanel;
}

class RightPanel : public QFrame
{
  Q_OBJECT

  public:
    explicit RightPanel(QWidget *parent = 0);
    ~RightPanel();

  private slots:
    void timer();

  private:
    Ui::RightPanel *ui;

    QTimer *m_timer;
};

#endif // RIGHTPANEL_H
