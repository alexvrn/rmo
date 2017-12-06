#ifndef SHPINDICATOR_H
#define SHPINDICATOR_H

// Qt
#include <QWidget>

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
    void data(CommandType::Command cmd, const QByteArray& value = QByteArray());

  private slots:
    void checkedDateTime();

    void on_spinBox_valueChanged(int value);

private:
    Ui::ShPIndicator *ui;

    ShPIndicatorItem *indicatorItem1;
    ShPIndicatorItem *indicatorItem2;
};

#endif // SHPINDICATOR_H
