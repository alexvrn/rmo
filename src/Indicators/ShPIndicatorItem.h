#ifndef SHPINDICATORITEM_H
#define SHPINDICATORITEM_H

// Qt
#include <QWidget>
#include <QSplitter>
#include <QVariantMap>

// Local
class ShPIndicatorWidget;
#include <commandType.h>

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
    void data(CommandType::Command cmd, const PgasData& value = PgasData());
    void setCurrentPgasNumber(int pgasNumber);

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
