#ifndef PANELVIEWER_H
#define PANELVIEWER_H

// Qt
#include <QWidget>

// UI
namespace Ui
{
  class PanelViewer;
}

class PanelViewer : public QWidget
{
  Q_OBJECT

  public:
    explicit PanelViewer(QWidget *parent = 0);
    ~PanelViewer();

  private:
    Ui::PanelViewer *ui;
};

#endif // PANELVIEWER_H
