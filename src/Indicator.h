#ifndef INDICATOR_H
#define INDICATOR_H

// Qt
#include <QWidget>

// Local
#include "commandType.h"

class Indicator : public QWidget
{
  Q_OBJECT

  public:
    explicit Indicator(QWidget *parent = nullptr);
    virtual ~Indicator();

    virtual QString name() const = 0;

  public Q_SLOTS:
    //! Данных может приходить много, из-за этого частая отрисовка может тормозить,
    //! поэтому обновляем изображение на индикаторах не после каждого нового сообщения с данными, а по таймеру
    virtual void newData(cmd_e cmd, const QVariant& value = QVariant()) = 0;

  signals:
    void info(const QString& text);

  public slots:
};

#endif // INDICATOR_H
