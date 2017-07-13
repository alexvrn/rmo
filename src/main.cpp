// Local
#include "ControlLeftPanel.h"
#include "ControlRightPanel.h"
#include "Client.h"

// Qt
#include <QApplication>
#include <QSettings>
#include <QDebug>
#include <QScreen>


int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  app.setOrganizationName("SAMI DVO RAN");
  app.setOrganizationDomain("skbsami.ru");
  app.setApplicationName("rmo");

  QSettings settings("SAMI DVO RAN", "rmo");

  // Установка локали по умолчанию
  QLocale russianLocale(QLocale::Russian, QLocale::RussianFederation);
  QLocale::setDefault(russianLocale);

  ControlLeftPanel controlLeftPanel;
  controlLeftPanel.show();

  ControlRightPanel controlRightPanel;
  controlRightPanel.show();

  QObject::connect(&controlLeftPanel, &ControlLeftPanel::indicatorChecked, &controlRightPanel, &ControlRightPanel::indicatorCheck);
  QObject::connect(&controlRightPanel, &ControlRightPanel::indicatorChecked, &controlLeftPanel, &ControlLeftPanel::indicatorCheck);

  const bool release = settings.value("release", false).toBool();
  if (!release)
  {
    const auto screen = qApp->primaryScreen();
    const auto screenGeometry = screen->geometry();
    controlLeftPanel.setGeometry(0, 0, screenGeometry.width(), screenGeometry.height() / 2);
    controlRightPanel.setGeometry(0, screenGeometry.height() / 2, screenGeometry.width(), screenGeometry.height() / 2);
  }
  else
  {
    const auto screens = qApp->screens();
    const int window1 = settings.value("window1", 1).toInt();
    const int window2 = settings.value("window2", 2).toInt();
    Q_ASSERT_X(screens.count() >= 2, "main", "Количество мониторов должно быть больше 2-х");
    Q_ASSERT_X((window1 >= 1 && window1 <= 2)
               && (window2 >= 1 && window2 <= 2)
               && (window1 != window2), "config", "Ошибка в задании номеров мониторов");

    controlLeftPanel.setGeometry(screens[window1 - 1]->geometry());
    controlLeftPanel.setWindowState(Qt::WindowFullScreen);
    controlRightPanel.setGeometry(screens[window2 - 1]->geometry());
    controlRightPanel.setWindowState(Qt::WindowFullScreen);
  }

  // Сохранённые настройки приложения
  QString indicatorRight = settings.value("Right/indicator", "ГЛ").toString();
  QString indicatorLeft = settings.value("Left/indicator", "ГЛ").toString();
  QString mode = settings.value("Mode", "SUN").toString();

  controlLeftPanel.setConfiguration(indicatorLeft);
  controlRightPanel.setConfiguration(indicatorRight, mode);

  // Подключение к серверу
  Client client;
  client.connectToHost(settings.value("Server/endpoint", "127.0.0.1").toString(),
                       settings.value("Server/port", 0).toInt());

  return app.exec();
}
