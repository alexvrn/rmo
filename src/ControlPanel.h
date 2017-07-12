#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H

// Qt
#include <QMainWindow>
#include <QToolBar>

// Local
#include "IndicatorsStackedWidget.h"

class ControlPanel : public QMainWindow
{
  Q_OBJECT

  public:
    explicit ControlPanel(QWidget *parent = Q_NULLPTR);
    virtual ~ControlPanel();

    // Изменение внешнего вида окна при подключении\отключении сервера
    void setConnectState(bool connect);

    virtual void setConfiguration(const QString& type) = 0;

  protected:
    void closeEvent(QCloseEvent *e);

  protected:
    IndicatorsStackedWidget *m_indicatorsStackedWidget;
    QToolBar* m_toolBar;
};

#endif // CONTROLPANEL_H
