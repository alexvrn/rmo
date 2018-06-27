#ifndef IZLINDICATOR_H
#define IZLINDICATOR_H

// Qt
#include <QWidget>

// Local
#include "Indicator.h"

// UI
namespace Ui
{
  class IZLIndicator;
}


class IZLIndicator : public Indicator
{
  Q_OBJECT

  public:
    explicit IZLIndicator(QWidget *parent = 0);
    ~IZLIndicator();

    QString name() const override;

  public Q_SLOTS:
    void newData(cmd_e cmd, const QVariant& value = QVariant()) override;

  private:
    Ui::IZLIndicator *ui;
};

#endif // IZLINDICATOR_H
