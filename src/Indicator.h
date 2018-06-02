#ifndef INDICATOR_H
#define INDICATOR_H

// Qt
#include <QWidget>

class Indicator : public QWidget
{
  Q_OBJECT

  public:
    explicit Indicator(QWidget *parent = nullptr);

  signals:
    void info(const QString& text);

  public slots:
};

#endif // INDICATOR_H
