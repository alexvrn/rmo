// Local
#include "Graphic.h"

// Qt
#include <QPainter>
#include <QPaintEvent>
#include <QGraphicsItem>

Graphic::Graphic(QWidget *parent)
  : QGraphicsView(parent)
  , m_graphicsScene(new QGraphicsScene(this))
  , m_currentDataLength(0)
  , m_isGrid(false)
  , m_up(true)
  , m_group1(new QGraphicsItemGroup())
  , m_resizeTimer(new QTimer(this))
{
  setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Отключим скроллбар по горизонтали
  setAlignment(Qt::AlignBottom); // Делаем привязку содержимого
  setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding); // Растягиваем содержимое по виджету

  setScene(m_graphicsScene);

  m_graphicsScene->addItem(m_group1);

  connect(m_resizeTimer, SIGNAL(timeout()), SLOT(slotAlarmTimer()));
  //m_resizeTimer->setSingleShot(true);
  //m_resizeTimer->start(50);
  QTimer::singleShot(50, this, SLOT(slotAlarmTimer()));
}


Graphic::~Graphic()
{
  delete m_group1;
}


void Graphic::resizeEvent(QResizeEvent *event)
{
  //m_resizeTimer->start(50); // Как только событие произошло стартуем таймер для отрисовки
  QTimer::singleShot(50, this, SLOT(slotAlarmTimer()));
  QGraphicsView::resizeEvent(event); // Запускаем событие родителького класса
}


void Graphic::slotAlarmTimer()
{
  deleteItemsFromGroup(m_group1);

  int width = this->width();
  int height = 500;//this->height();

  //m_graphicsScene->setSceneRect(0, 0, width, height);
  m_graphicsScene->setSceneRect(0, 0, width, height);

  auto mdata = m_data[CommandType::Stream_3];
  for (int i = 0; i < mdata.length(); ++i)
  {
    int h = m_up ? height - i : i;
    QColor color = QColor(255.0 * qrand() / RAND_MAX, 255.0 * qrand() / RAND_MAX, 255.0 * qrand() / RAND_MAX);
    m_group1->addToGroup(m_graphicsScene->addLine(QLineF(QPoint(0, h), QPoint(width, h)), color));
  }
//  for (int i = 0; i < m_listData.length(); ++i)
//  {
//    int h = m_up ? height - i : i;
//    m_group1->addToGroup(m_graphicsScene->addLine(QLineF(QPoint(0, h), QPoint(width, h)), m_listData[i]));
//  }
}


void Graphic::addData(const QMap<CommandType::Command, QList<QVariantMap> >& data)
{
  m_data = data;
  //QColor color = QColor(255.0 * qrand() / RAND_MAX, 255.0 * qrand() / RAND_MAX, 255.0 * qrand() / RAND_MAX);
  //m_listData.push_front(color);

  //m_currentDataLength = m_data.length();

  QTimer::singleShot(50, this, SLOT(slotAlarmTimer()));
}


void Graphic::setOrientation(bool up)
{
  m_up = up;
  update();
}


bool Graphic::orientation() const
{
  return m_up;
}


void Graphic::setBackgroundColor(const QColor& color)
{
  setBackgroundBrush(QBrush(color));
  update();
}


void Graphic::deleteItemsFromGroup(QGraphicsItemGroup *group)
{
  /* Перебираем все элементы сцены, и если они принадлежат группе,
   * переданной в метод, то удаляем их
  * */
  for (auto item : m_graphicsScene->items(group->boundingRect()))
  {
    if (item->group() == group)
      delete item;
  }
}
