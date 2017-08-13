// Local
#include "PaletteWidget.h"

// Qt
#include <QDebug>
#include <QLabel>
#include <QSlider>
#include <QHBoxLayout>

PaletteWidget::PaletteWidget(QWidget *parent)
  : QWidget(parent)
  , m_label(new QLabel(this))
  , m_slider(new QSlider(Qt::Vertical, this))
  , m_mode(0)
{   
  m_label->setMinimumWidth(20);

  m_slider->setMinimum(0);
  m_slider->setMaximum(100);

  QHBoxLayout * layout = new QHBoxLayout(this);
  layout->setContentsMargins(1, 1, 1, 1);
  layout->setSpacing(1);
  layout->addWidget(m_label);
  layout->addWidget(m_slider);

  connect(m_slider, SIGNAL(valueChanged(int)), this, SLOT(valueChanged(int)));

  setPalette(m_mode);
}


void PaletteWidget::setPalette(int mode)
{
  m_mode = mode;
  if (mode == 0)
  {
    setStyleSheet("QLabel {"
                  "background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #76ff03, stop: 1 #1b5e20);}");
  }
  else if (mode == 1)
  {
    setStyleSheet("QLabel {"
                  "background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 red, stop: .25 yellow, stop: .5 green, stop: .75 blue, stop: 1 violet);}");
  }
  else
  {
    qWarning() << tr("Неизвестный режим выбора цвета:") << mode;
  }
}


void PaletteWidget::valueChanged(int value)
{
  value = 100 - value;

  QColor color;
  if (value <= 25) // Красный => Жёлтый
  {
    color = QColor(255,255 * value / 25.,0);
  }
  else if (value > 25 && value <= 50) // Жёлтый => Зелёный
  {
    color = QColor(255 * (1 - (value - 25.) / 25),255,0);
  }
  else if (value > 50 && value <= 75) // Зеленый => Синий
  {
    color = QColor(0,255 * (1 - (value - 50) / 25.),255 * (value - 50) / 25.);
  }
  else if (value > 75 && value <= 100) // Синий => Фиолетовый
  {
    color = QColor(255 * (value - 75) / 25.,0,255);
  }
  emit colorValue(color);
}
