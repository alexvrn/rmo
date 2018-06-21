#ifndef TOINDICATOR_H
#define TOINDICATOR_H

// Qt
#include <QWidget>

// Local
#include "Indicator.h"

// UI
namespace Ui
{
  class TOIndicator;
}

class TOIndicator : public Indicator
{
  Q_OBJECT

  public:
    explicit TOIndicator(QWidget *parent = Q_NULLPTR);
    ~TOIndicator();

    QString name() const override;

  public Q_SLOTS:
    void newData(CommandType::Command cmd, const QVariant& value = QVariant()) override;

  private:
    Ui::TOIndicator *ui;
};

#endif // TOINDICATOR_H
