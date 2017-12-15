#ifndef GRAPHIC_H
#define GRAPHIC_H

// Qt
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsItemGroup>

class Graphic : public QGraphicsView
{
  Q_OBJECT

  public:
    explicit Graphic(QWidget *parent = nullptr);
    ~Graphic();

    void setBackgroundColor(const QColor& color);
    void addData(const QList<QVariantMap>& data);

    bool orientation() const;

  signals:

  public slots:
    void setOrientation(bool up);

  protected:
    void resizeEvent(QResizeEvent *event);

  private slots:
    void slotAlarmTimer();

  private:
    void deleteItemsFromGroup(QGraphicsItemGroup *group);

    QGraphicsScene* m_graphicsScene;
    QColor m_backGroundColor;
    int m_currentDataLength;
    bool m_isGrid;
    bool m_up;

    QGraphicsItemGroup* m_group1; // Объявляем первую группу элементов

    QTimer* m_resizeTimer;

    QList<QVariantMap> m_data;
};

#endif // GRAPHIC_H
