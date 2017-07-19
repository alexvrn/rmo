#ifndef PALETTEWIDGET_H
#define PALETTEWIDGET_H

// Qt
#include <QLabel>

class PaletteWidget : public QLabel
{
  Q_OBJECT

  public:
    explicit PaletteWidget(QWidget *parent = Q_NULLPTR);

  public slots:
    void setPalette(int mode);
};

#endif // PALETTEWIDGET_H
