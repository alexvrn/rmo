#ifndef SAINDICATOR_H
#define SAINDICATOR_H

// Qt
#include <QWidget>

// Local
#include "commandType.h"
#include "Indicator.h"

// QCustomPlot
#include "qcustomplot.h"

// UI
namespace Ui
{
  class SAIndicator;
}

class SAIndicator : public Indicator
{
  Q_OBJECT

  public:
    explicit SAIndicator(QWidget *parent = Q_NULLPTR);
    ~SAIndicator();

    QString name() const override;

  public slots:
    void setLightMode(const QString& mode);
    void newData(cmd_e cmd, const QVariant& value = QVariant()) override;

  private slots:
    void checkedDateTime();
    void nowToggled();

  private:
    Ui::SAIndicator *ui;

    PgasData m_selectedData;
};

#endif // SAINDICATOR_H
