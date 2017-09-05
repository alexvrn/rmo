// Local
#include "ResponseReceiver.h"

ResponseReceiver::ResponseReceiver(const QString& method, QObject* parent)
  : QObject(parent)
  , m_method(method)
  , m_loop(new QEventLoop(this))
  , m_received(false)
{}


QVariantMap ResponseReceiver::responseData() const
{
  return m_responseData;
}


void ResponseReceiver::messageReceived(const QVariantMap& data)
{
  if (!data.isEmpty())
  {
    m_received = true;
    m_responseData = data;
    m_loop->quit();
  }
}


void ResponseReceiver::run()
{
  if (!m_received)
    m_loop->exec();
}
