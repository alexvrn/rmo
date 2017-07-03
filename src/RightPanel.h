#ifndef RIGHTPANEL_H
#define RIGHTPANEL_H

// Qt
#include <QFrame>
class QTimer;
class QLabel;

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

  private slots:
    void timer();

  private:
    Ui::RightPanel *ui;

    QLabel* m_dateTimeLabel;
    QTimer *m_timer;
};

#endif // RIGHTPANEL_H
