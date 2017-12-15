#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H

// Qt
#include <QMainWindow>
#include <QToolBar>

// Local
#include "IndicatorsStackedWidget.h"
#include <commandType.h>

class ControlPanel : public QMainWindow
{
  Q_OBJECT

  public:
    explicit ControlPanel(QWidget *parent = Q_NULLPTR);
    virtual ~ControlPanel();

    // Изменение внешнего вида окна при подключении\отключении сервера
    void setConnectState(bool connect);

    virtual void setConfiguration(const QString& type, const QString& mode = QString()) = 0;

  public slots:
    virtual void data(CommandType::Command cmd, const PgasData& value = PgasData());

  signals:
    void windowDeactivate();

  protected:
    void closeEvent(QCloseEvent *e);
    bool eventFilter(QObject *obj, QEvent *event) Q_DECL_OVERRIDE;

  protected:
    IndicatorsStackedWidget *m_indicatorsStackedWidget;
    QToolBar* m_toolBar;
};

#endif // CONTROLPANEL_H
