// Local
#include "Graphic.h"

// Qt
#include <QPainter>
#include <QPaintEvent>

Graphic::Graphic(QWidget *parent)
  : QWidget(parent)
  , m_currentDataLength(0)
  , m_isGrid(false)
{

}


void Graphic::addData(const QList<int>& data)
{
  m_currentDataLength++;

  update();
}


void Graphic::setBackgroundColor(const QColor& color)
{
  m_backGroundColor = color;
  update();
}


void Graphic::paintEvent(QPaintEvent *event)
{
  Q_UNUSED(event);

  QPainter painter(this); // Создаём объект отрисовщика

  // Устанавливаем кисть абриса
  painter.setPen(m_backGroundColor);
  painter.setBrush(QBrush(m_backGroundColor));

  painter.drawRect(rect());

  for (int i = 0; i < m_currentDataLength; ++i)
  {
    int h = height() - i;
    painter.setPen(QColor(255.0 * qrand() / RAND_MAX, 255.0 * qrand() / RAND_MAX, 255.0 * qrand() / RAND_MAX));
    painter.drawLine(QPoint(0, h), QPoint(width(), h));
  }
}
