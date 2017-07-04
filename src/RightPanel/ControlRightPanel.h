#ifndef CONTROLRIGHTPANEL_H
#define CONTROLRIGHTPANEL_H

// Qt
#include <QMainWindow>

// Local
class RightPanel;
class IndicatorsStackedWidget;

// Ui
namespace Ui
{
  class ControlRightPanel;
}


class ControlRightPanel : public QMainWindow
{
  Q_OBJECT

  public:
    explicit ControlRightPanel(QWidget *parent = Q_NULLPTR);
    ~ControlRightPanel();

  signals:
    void indicatorChecked(const QString& type, bool checked);

  public slots:
    void indicatorCheck(const QString& type, bool checked);

  private:
    Ui::ControlRightPanel *ui;

    RightPanel *m_panel;
    IndicatorsStackedWidget *m_indicatorsStackedWidget;
};

#endif // CONTROLRIGHTPANEL_H
