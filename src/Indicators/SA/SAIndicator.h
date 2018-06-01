#ifndef SAINDICATOR_H
#define SAINDICATOR_H

// Qt
#include <QWidget>

// Local
#include "commandType.h"

// UI
namespace Ui
{
  class SAIndicator;
}

class SAIndicator : public QWidget
{
  Q_OBJECT

  public:
    explicit SAIndicator(QWidget *parent = Q_NULLPTR);
    ~SAIndicator();

  public slots:
    void setLightMode(const QString& mode);
    void newData(CommandType::Command cmd, const QVariant& value = QVariant());

  private slots:
    void checkedDateTime();
    void nowToggled();

  private:
    Ui::SAIndicator *ui;

    PgasData m_selectedData;
};

#endif // SAINDICATOR_H
