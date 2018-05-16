#ifndef RESPONSERECEIVER_H
#define RESPONSERECEIVER_H

// Qt
#include <QObject>
#include <QEventLoop>
#include <QVariantMap>

// Local
#include <commandType.h>


class ResponseReceiver : public QObject
{
  Q_OBJECT

  public:
    explicit ResponseReceiver(QObject* parent = Q_NULLPTR);

    PgasData responseData() const;

  public slots:
    void messageReceived(const PgasData& data);
    void run();

  private:
    QEventLoop* m_loop;
    PgasData m_responseData;
};

#endif // RESPONSERECEIVER_H
