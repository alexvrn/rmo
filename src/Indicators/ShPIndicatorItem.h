#ifndef SHPINDICATORITEM_H
#define SHPINDICATORITEM_H

// Qt
#include <QWidget>
#include <QSplitter>

// Local
class ShPIndicatorWidget;

// UI
namespace Ui
{
  class ShPIndicatorItem;
}

class ShPIndicatorItem : public QWidget
{
  Q_OBJECT

  public:
    explicit ShPIndicatorItem(QWidget *parent = Q_NULLPTR);
    ~ShPIndicatorItem();

  public slots:
    void setLightMode(const QString& mode);
    void data(int cmd, const QByteArray& value = QByteArray());

  private slots:
    void deleteDownWidget();
    void insertDownWidget();
    void countWidget();

  private:
    Ui::ShPIndicatorItem *ui;

    ShPIndicatorWidget *m_upWidget;
    ShPIndicatorWidget *m_downWidget;
};

#endif // SHPINDICATORITEM_H
