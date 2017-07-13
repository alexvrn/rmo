#ifndef CONTROLLEFTPANEL_H
#define CONTROLLEFTPANEL_H

// Qt
#include <QEvent>

// Local
class LeftPanel;
#include "ControlPanel.h"

// Ui
namespace Ui
{
  class ControlLeftPanel;
}


class ControlLeftPanel : public ControlPanel
{
  Q_OBJECT

  public:
    explicit ControlLeftPanel(QWidget *parent = Q_NULLPTR);
    ~ControlLeftPanel();

    void setConfiguration(const QString& type, const QString& mode = QString()) Q_DECL_OVERRIDE;

  signals:
    void indicatorChecked(const QString& type, bool checked);

  public slots:
    void indicatorCheck(const QString& type, bool checked);

  private:
    Ui::ControlLeftPanel *ui;

    LeftPanel *m_panel;
};

#endif // CONTROLLEFTPANEL_H
