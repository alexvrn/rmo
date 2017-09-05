#ifndef RESPONSERECEIVER_H
#define RESPONSERECEIVER_H

// Qt
#include <QObject>
#include <QEventLoop>
#include <QVariantMap>

class ResponseReceiver : public QObject
{
  Q_OBJECT

  public:
    explicit ResponseReceiver(const QString& method, QObject* parent = Q_NULLPTR);

    QVariantMap responseData() const;

  public slots:
    void messageReceived(const QVariantMap& data);
    void run();

  private:
    QString m_method;
    QEventLoop* m_loop;
    QVariantMap m_responseData;
    bool m_received;
};

#endif // RESPONSERECEIVER_H
