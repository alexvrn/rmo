// Local
#include "MainWindow.h"
#include "Client.h"
#include "ScreenSaver.h"

// Qt
#include <QApplication>
#include <QSettings>
#include <QDebug>
#include <QScreen>
#include <QMessageBox>


int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  app.setOrganizationName("SAMI_DVO_RAN");
  app.setOrganizationDomain("skbsami.ru");
  app.setApplicationName("rmo");

  QSettings settings("SAMI_DVO_RAN", "rmo");

  // Установка локали по умолчанию
  QLocale russianLocale(QLocale::Russian, QLocale::RussianFederation);
  QLocale::setDefault(russianLocale);

  const bool release = settings.value("release", true).toBool();
  if (!release)
  {
    //const auto screen = qApp->primaryScreen();
    //const auto screenGeometry = screen->geometry();
  }
  else
  {
    const auto screens = qApp->screens();
//    const int window1 = settings.value("window1", 1).toInt();
//    const int window2 = settings.value("window2", 2).toInt();
    Q_ASSERT_X(screens.count() >= 2, "main", "Количество мониторов должно быть минимум два");
//    Q_ASSERT_X((window1 >= 1 && window1 <= 2)
//               && (window2 >= 1 && window2 <= 2)
//               && (window1 != window2), "config", "Ошибка в задании номеров мониторов");
  }

  // Сохранённые настройки приложения
  QString indicatorRight = settings.value("right/indicator", QObject::tr("ГЛ")).toString();
  QString indicatorLeft = settings.value("left/indicator", QObject::tr("ГЛ")).toString();
  QString mode = settings.value("mode", "sun").toString();

  MainWindow mainWindow;
  mainWindow.setConfiguration(indicatorLeft, indicatorRight, mode);

  // Подключение к серверу
  Client& client = Client::instance();
  if (!client.connectToServer(settings.value("rmoServerName", "rmoserver").toString()))
  {
    QMessageBox::critical(0, QObject::tr("Подключение к локальному серверу"),
                             QObject::tr("Не удаётся подключиться к серверу."));
    return 0;
  }

  QObject::connect(&client, &Client::success, &mainWindow, &MainWindow::show);

  // Авторизация
  if (!client.logout())
    return 0;

  QObject::connect(&client, &Client::newData, &mainWindow, &MainWindow::newData);

  // Проверка бездействия пользователя
  ScreenSaver& screenSaver = ScreenSaver::instance();

  QObject::connect(&screenSaver, &ScreenSaver::logout, &mainWindow, &MainWindow::hide);
  QObject::connect(&screenSaver, &ScreenSaver::logout, &client, &Client::logout);
  QObject::connect(&client, &Client::success, &screenSaver, &ScreenSaver::checkIdle);

  return app.exec();
}
