// Local
#include "Client.h"

// Qt
#include <QApplication>
#include <QTimer>
#include <QNetworkAccessManager>

// MATH
#include <QtMath>

Client::Client(QObject *parent)
  : QObject(parent)
  , m_networkManager(new QNetworkAccessManager(this))
{
  connect(&m_authDialog, &AuthDialog::authentication, this, &Client::authAccess);

  // Через секунду запрашиваем авторизацию
  QTimer::singleShot(1000, this, SLOT(logout()));

  //! FAKE
  // setup a timer that repeatedly calls MainWindow::realtimeDataSlot:
  connect(&m_dataTimer, SIGNAL(timeout()), this, SLOT(realtimeDataSlot()));
  m_dataTimer.start(0); // Interval 0 means to refresh as fast as possible
}


Client::~Client()
{
}


bool Client::connectToHost(const QString& host, int port)
{
  qDebug() << qPrintable(QString(tr("Подключение к серверу %1:%2")).arg(host).arg(port));
  m_networkManager->connectToHost(host, port);

  return true;
}


void Client::logout()
{
  if (m_authDialog.isVisible())
    return;

  if (QDialog::Rejected == m_authDialog.exec())
  {
    // Выходим из приложения, если пользователь отказаться авторизоваться
    qApp->quit();
  }
}


void Client::authAccess(const QVariantMap& userData)
{
  qDebug() << userData;
  m_authDialog.setResult(QDialog::Accepted);
  m_authDialog.hide();
  emit authentication();
  //! TODO: получение результата по сокету
//  QByteArray request = Proto::encode("request", method, data);

//  ResponseReceiver receiver(method);
//  connect(this, SIGNAL(messageReceived(QVariantMap)), &receiver, SLOT(messageReceived(QVariantMap)));
//  m_socket->write("");
//  receiver.run();

  //if (receiver.responseData())
  //{}
}


void Client::readyRead()
{

}


void Client::disconnected()
{

}


void Client::realtimeDataSlot()
{
  static QTime time(QTime::currentTime());
  // calculate two new data points:
  double key = time.elapsed()/1000.0; // time elapsed since start of demo, in seconds
  static double lastPointKey = 0;
  if (key-lastPointKey > 0.002) // at most add point every 2 ms
  {
    // add data to lines:
    emit data(key, qSin(key)+qrand()/(double)RAND_MAX*1*qSin(key/0.3843));
    //ui->customPlot->graph(0)->addData(key, qSin(key)+qrand()/(double)RAND_MAX*1*qSin(key/0.3843));
    //ui->customPlot->graph(1)->addData(key, qCos(key)+qrand()/(double)RAND_MAX*0.5*qSin(key/0.4364));
    // rescale value (vertical) axis to fit the current data:
    //ui->customPlot->graph(0)->rescaleValueAxis();
    //ui->customPlot->graph(1)->rescaleValueAxis(true);
    lastPointKey = key;
  }
  // make key axis range scroll with the data (at a constant range size of 8):
  //ui->customPlot->xAxis->setRange(key, 8, Qt::AlignRight);
  //ui->customPlot->replot();

  // calculate frames per second:
  static double lastFpsKey;
  static int frameCount;
  ++frameCount;
  if (key-lastFpsKey > 2) // average fps over 2 seconds
  {
//    ui->statusBar->showMessage(
//          QString("%1 FPS, Total Data points: %2")
//          .arg(frameCount/(key-lastFpsKey), 0, 'f', 0)
//          .arg(ui->customPlot->graph(0)->data()->size()+ui->customPlot->graph(1)->data()->size())
//        , 0);
    lastFpsKey = key;
    frameCount = 0;
  }
}

