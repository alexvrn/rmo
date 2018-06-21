#ifndef ZPSINDICATOR_H
#define ZPSINDICATOR_H

// Qt
#include <QWidget>

// Local
#include "Indicator.h"

// UI
namespace Ui
{
  class ZPSIndicator;
}

class ZPSIndicator : public Indicator
{
  Q_OBJECT

  public:
    explicit ZPSIndicator(QWidget *parent = 0);
    ~ZPSIndicator();

    QString name() const override;

  public Q_SLOTS:
    void newData(CommandType::Command cmd, const QVariant& value = QVariant()) override;

  private:
    Ui::ZPSIndicator *ui;
};

#endif // ZPSINDICATOR_H
