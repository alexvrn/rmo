#ifndef SHPINDICATOR_H
#define SHPINDICATOR_H

// Qt
#include <QWidget>
#include <QVariantMap>

// Local
class ShPIndicatorItem;
#include <commandType.h>
#include "Indicator.h"

// UI
namespace Ui
{
  class ShPIndicator;
}

class ShPIndicator : public Indicator
{
  Q_OBJECT

  public:
    explicit ShPIndicator(QWidget *parent = Q_NULLPTR);
    ~ShPIndicator();

    QString name() const override;

  public slots:
    void setLightMode(const QString& mode);
    void newData(cmd_e cmd, const QVariant& value = QVariant()) override;

  private slots:
    void checkedDateTime();
    void nowToggled();
    void on_spinBox_valueChanged(int value);

private:
    Ui::ShPIndicator *ui;
};

#endif // SHPINDICATOR_H
