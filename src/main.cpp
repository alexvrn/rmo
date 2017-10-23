// Local
#include "ControlLeftPanel.h"
#include "ControlRightPanel.h"
#include "Client.h"
#include "ScreenSaver.h"

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

  // Не показываем окно, пока не авторизуемся
  ControlLeftPanel controlLeftPanel;

  // Не показываем окно, пока не авторизуемся
  ControlRightPanel controlRightPanel;

  QObject::connect(&controlLeftPanel, &ControlLeftPanel::indicatorChecked, &controlRightPanel, &ControlRightPanel::indicatorCheck);
  QObject::connect(&controlRightPanel, &ControlRightPanel::indicatorChecked, &controlLeftPanel, &ControlLeftPanel::indicatorCheck);
  QObject::connect(&controlRightPanel, &ControlRightPanel::showWindow, &controlLeftPanel, &ControlLeftPanel::setVisible);
  QObject::connect(&controlRightPanel, &ControlRightPanel::lightMode, &controlLeftPanel, &ControlLeftPanel::setLightMode);

  const bool release = settings.value("release", true).toBool();
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
  QString indicatorRight = settings.value("right/indicator", QObject::tr("ГЛ")).toString();
  QString indicatorLeft = settings.value("left/indicator", QObject::tr("ГЛ")).toString();
  QString mode = settings.value("mode", "sun").toString();

  controlLeftPanel.setConfiguration(indicatorLeft, mode);
  controlRightPanel.setConfiguration(indicatorRight, mode);

  // Подключение к серверу
  Client client;
  //client.connectToServer(settings.value("server/endpoint", "127.0.0.1").toString());
  client.connectToServer("rmoserver");

  QObject::connect(&client, &Client::authentication, &controlLeftPanel, &ControlRightPanel::show);
  QObject::connect(&client, &Client::authentication, &controlRightPanel, &ControlLeftPanel::show);

  QObject::connect(&client, &Client::data, &controlRightPanel, &ControlLeftPanel::data);
  QObject::connect(&client, &Client::data, &controlLeftPanel, &ControlLeftPanel::data);

  // Проверка бездействия пользователя
  ScreenSaver& screenSaver = ScreenSaver::instance();

  QObject::connect(&screenSaver, &ScreenSaver::logout, &controlLeftPanel, &ControlLeftPanel::hide);
  QObject::connect(&screenSaver, &ScreenSaver::logout, &controlRightPanel, &ControlRightPanel::hide);
  QObject::connect(&screenSaver, &ScreenSaver::logout, &client, &Client::logout);
  QObject::connect(&client, &Client::authentication, &screenSaver, &ScreenSaver::checkIdle);

  return app.exec();
}
