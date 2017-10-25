#ifndef GRAPHIC_H
#define GRAPHIC_H

// Qt
#include <QWidget>

class Graphic : public QWidget
{
  Q_OBJECT

  public:
    explicit Graphic(QWidget *parent = nullptr);

    void setBackgroundColor(const QColor& color);
    void addData(const QList<int>& data);

  signals:

  public slots:

  protected:
    void paintEvent(QPaintEvent *event);

  private:
    QColor m_backGroundColor;
    int m_currentDataLength;
    bool m_isGrid;
};

#endif // GRAPHIC_H
