#ifndef SHPINDICATOR_H
#define SHPINDICATOR_H

// Qt
#include <QWidget>
#include <QVariantMap>

// Local
class ShPIndicatorItem;
#include <commandType.h>

// UI
namespace Ui
{
  class ShPIndicator;
}

class ShPIndicator : public QWidget
{
  Q_OBJECT

  public:
    explicit ShPIndicator(QWidget *parent = Q_NULLPTR);
    ~ShPIndicator();

  public slots:
    void setLightMode(const QString& mode);
    void newData(CommandType::Command cmd, const QVariant& value = QVariant());

  private slots:
    void checkedDateTime();

    void on_spinBox_valueChanged(int value);

private:
    Ui::ShPIndicator *ui;

    ShPIndicatorItem *m_indicatorItem1;
    ShPIndicatorItem *m_indicatorItem2;
};

#endif // SHPINDICATOR_H
