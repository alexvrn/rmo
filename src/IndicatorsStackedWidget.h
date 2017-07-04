#ifndef INDICATORSSTACKEDWIDGET_H
#define INDICATORSSTACKEDWIDGET_H

// Qt
#include <QStackedWidget>

// Local
#include "ShPIndicator.h"
#include "GLIndicator.h"


class IndicatorsStackedWidget : public QStackedWidget
{
  Q_OBJECT

  public:
    IndicatorsStackedWidget(QWidget *parent = Q_NULLPTR);
    ~IndicatorsStackedWidget();

  public slots:
    void setCurrentIndicator(const QString& type, bool checked);

  private:
    QWidget *m_nullIndicator;
    GLIndicator *m_glIndicator;
    ShPIndicator *m_shpIndicator;
};

#endif // INDICATORSSTACKEDWIDGET_H
