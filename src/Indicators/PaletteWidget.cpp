// Local
#include "PaletteWidget.h"

// Qt
#include <QDebug>

PaletteWidget::PaletteWidget(QWidget *parent)
  : QLabel(parent)
{

}


void PaletteWidget::setPalette(int mode)
{
  if (mode == 0)
  {
    setStyleSheet("QLabel {"
                  "background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #76ff03, stop: 1 #1b5e20);}");
  }
  else if (mode == 1)
  {
    setStyleSheet("QLabel {"
                  "background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 red, stop: .5 yellow, stop: 1 blue);}");
  }
}
