#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// Qt
#include <QMainWindow>
#include <QToolBar>

// Local
class LeftPanel;
class RightPanel;
class IndicatorList;
#include "commandType.h"

// cmd
#include <cmd.h>

class MainWindow : public QMainWindow
{
  Q_OBJECT

  public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // Изменение внешнего вида окна при подключении\отключении сервера
    void setConnectState(bool connect);

    void setConfiguration(const QString& leftType, const QString& rightType, const QString& mode = QString());

  public slots:
    virtual void newData(cmd_e cmd, const QVariant& value = QVariant());

  protected:
    void closeEvent(QCloseEvent *e) Q_DECL_OVERRIDE;
    bool eventFilter(QObject *obj, QEvent *event) Q_DECL_OVERRIDE;

  private:
    QToolBar* m_toolBar;
    LeftPanel* m_leftPanel;
    RightPanel* m_rightPanel;

    IndicatorList* m_indicatorList;
    //IndicatorsStackedWidget* m_leftIndicatorsStackedWidget;
    //IndicatorsStackedWidget* m_rightIndicatorsStackedWidget;
};

#endif // MAINWINDOW_H
