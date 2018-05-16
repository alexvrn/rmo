// Local
#include "ResponseReceiver.h"

ResponseReceiver::ResponseReceiver(QObject* parent)
  : QObject(parent)
  , m_loop(new QEventLoop(this))
{}


PgasData ResponseReceiver::responseData() const
{
  return m_responseData;
}


void ResponseReceiver::messageReceived(const PgasData& data)
{
  m_responseData = data;
  m_loop->quit();
}


void ResponseReceiver::run()
{
  m_loop->exec();
}
