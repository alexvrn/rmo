// Local
#include "ScreenSaver.h"

// Qt
#include <QTimer>
#include <QSettings>

// System
#if defined(Q_OS_LINUX)
#include <X11/extensions/scrnsaver.h>
#endif

ScreenSaver& ScreenSaver::instance()
{
  static ScreenSaver screenSaverInstance;
  return screenSaverInstance;
}


// отслеживание периода бездействия пользователя
void ScreenSaver::checkIdle()
{
#if defined(Q_OS_LINUX)
  static Display *display = XOpenDisplay(NULL);

  if (display == NULL)
  {
    return;
  }

  static XScreenSaverInfo *info = XScreenSaverAllocInfo();
  XScreenSaverQueryInfo(display, DefaultRootWindow(display), info);

  QSettings settings("SAMI_DVO_RAN", "rmo");
  const int second = settings.value("screensaver", 60).toInt();

  const int targetIdleMs = second * 1000;   // целевое время бездействия в миллисекундах
  const int actualIdleMs = info->idle; // фактическое время бездействия в мс
  if (actualIdleMs < targetIdleMs)
  {
    // ждем оставшееся время до целевого и потом снова проверяем
    QTimer::singleShot(targetIdleMs - actualIdleMs, &instance(), SLOT(checkIdle()));
  }
  else
  {
    // целевое время достигнуто
    emit logout();
  }
#endif
}

