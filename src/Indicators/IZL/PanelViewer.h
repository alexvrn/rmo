#ifndef PANELVIEWER_H
#define PANELVIEWER_H

// Qt
#include <QWidget>

// Local
#include "ViewerModel.h"

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

    ViewerModel* m_viewerModel;
};

#endif // PANELVIEWER_H
