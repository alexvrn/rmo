#ifndef SCREENSAVER_H
#define SCREENSAVER_H

// Qt
#include <QObject>

class ScreenSaver : public QObject
{
  Q_OBJECT

  private:
    ScreenSaver(QObject *parent = Q_NULLPTR) { Q_UNUSED(parent); }
    ScreenSaver& operator=(const ScreenSaver&);

  signals:
    void logout();

  public:
    static ScreenSaver& instance();

  public slots:
    void checkIdle();
};

#endif // SCREENSAVER_H
