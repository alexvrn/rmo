#ifndef SHPINDICATORITEM_H
#define SHPINDICATORITEM_H

// Qt
#include <QWidget>
#include <QSplitter>
#include <QVariantMap>
#include <QDateTime>

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
    void newData();
    void setCurrentPgasNumber(int pgasNumber);
    // Режим
    void setNowData(bool nowData);
    // Данные для выбранной даты
    void setSelectedData(const PgasData& selectedData, const QDateTime& checkDateTime = QDateTime());

  private slots:
    void deleteDownWidget();
    void insertDownWidget();
    void countWidget();

  signals:
    void info(const QString& text);

  private:
    Ui::ShPIndicatorItem *ui;

    ShPIndicatorWidget *m_upWidget;
    ShPIndicatorWidget *m_downWidget;
};

#endif // SHPINDICATORITEM_H
