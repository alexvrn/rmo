#ifndef CONTROLLEFTPANEL_H
#define CONTROLLEFTPANEL_H

// Qt
#include <QMainWindow>
#include <QEvent>

// Local
class LeftPanel;
class IndicatorsStackedWidget;

// Ui
namespace Ui
{
  class ControlLeftPanel;
}


class ControlLeftPanel : public QMainWindow
{
  Q_OBJECT

  public:
    explicit ControlLeftPanel(QWidget *parent = Q_NULLPTR);
    ~ControlLeftPanel();

  signals:
    void indicatorChecked(const QString& type, bool checked);

  public slots:
    void indicatorCheck(const QString& type, bool checked);

  private:
    Ui::ControlLeftPanel *ui;

    LeftPanel *m_panel;
    IndicatorsStackedWidget *m_indicatorsStackedWidget;
};

#endif // CONTROLLEFTPANEL_H
