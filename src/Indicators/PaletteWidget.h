#ifndef PALETTEWIDGET_H
#define PALETTEWIDGET_H

// Qt
#include <QColor>
#include <QWidget>
class QLabel;
class QSlider;

class PaletteWidget : public QWidget
{
  Q_OBJECT

  public:
    explicit PaletteWidget(QWidget *parent = Q_NULLPTR);

  public slots:
    void setPalette(int mode);

  signals:
    void colorValue(const QColor& color);

  private slots:
    void valueChanged(int value);

  private:
    QLabel *m_label;
    QSlider *m_slider;
    int m_mode;
};

#endif // PALETTEWIDGET_H
