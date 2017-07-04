#ifndef RIGHTPANEL_H
#define RIGHTPANEL_H

// Qt
#include <QFrame>
class QTimer;
class QLabel;

// Local
class ButtonGroup;

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

  signals:
    void indicatorChecked(const QString& type, bool checked);

  private slots:
    void timer();

  private:
    Ui::RightPanel *ui;

    ButtonGroup *m_group;
    QLabel *m_dateTimeLabel;
    QTimer *m_timer;
};

#endif // RIGHTPANEL_H
