// Local
#include "GraphicPChSS.h"

GraphicPChSS::GraphicPChSS(QWidget *parent)
  : AbstractGraphic(parent)
  , m_thread(new QThread(this))
  , m_worker(new GraphicPChSSWorker())
{
  m_thread->start();
  m_worker->moveToThread(m_thread);

  connect(m_worker, &GraphicPChSSWorker::calculatedData, this, &GraphicPChSS::calculatedData, Qt::QueuedConnection);

  // http://www.qcustomplot.com/index.php/demos/colormapdemo
  // configure axis rect:
  setInteractions(QCP::iSelectAxes|QCP::iRangeDrag); // this will also allow rescaling the color scale by dragging/zooming
  axisRect()->setupFullAxesBox(true);
  xAxis->setLabel("");

  // Обработка перемещения мыши
  connect(this, SIGNAL(mouseMove(QMouseEvent*)), this, SLOT(mouseMove(QMouseEvent*)));
  connect(this, SIGNAL(mousePress(QMouseEvent*)), this, SLOT(mousePress(QMouseEvent*)));

  // Шкала
  m_colorScale = new QCPColorScale(this);
  plotLayout()->addElement(0, 1, m_colorScale); // add it to the right of the main axis rect
  m_colorScale->setType(QCPAxis::atRight); // scale shall be vertical bar with tick/axis labels right (actually atRight is already the default)

  yAxis->setRangeReversed(true);

  m_colorMap = new CPColorMap(xAxis, yAxis);
  m_colorMap->setColorScale(m_colorScale); // associate the color map with the color scale

  QCPColorGradient gradien;
  QMap<double, QColor> colorStops;
  colorStops[0] = QColor(0, 50, 0);
  colorStops[+1] = QColor(0, 255, 0);
  gradien.setColorStops(colorStops);

  // set the color gradient of the color map to one of the presets:
  m_colorMap->setGradient(gradien);//QCPColorGradient::gpJet);

  m_colorMap->setInterpolate(true);

  xAxis->setLabel("");
  yAxis->setLabel("Т");

  // make sure the axis rect and color scale synchronize their bottom and top margins (so they line up):
  //QCPMarginGroup *marginGroup = new QCPMarginGroup(ui->graphic);
  //ui->graphic->axisRect()->setMarginGroup(QCP::msBottom | QCP::msTop, marginGroup);
  //colorScale->setMarginGroup(QCP::msBottom|QCP::msTop, marginGroup);
}


GraphicPChSS::~GraphicPChSS()
{
  m_thread->quit();
  if (!m_thread->wait(5000))
    m_thread->terminate();

  delete m_worker;
}


void GraphicPChSS::calculateData(const QList<QVariantMap>& data, bool isNowData, int seconds, int shiftData,
                   int verticalScrollBarMaximum, int verticalScrollBarValue, const QDateTime& checkDateTime, bool reverse)
{
  QMetaObject::invokeMethod(m_worker, "calculateData", Qt::QueuedConnection,
                            Q_ARG(QList<QVariantMap>, data),
                            Q_ARG(bool, isNowData),
                            Q_ARG(int, seconds),
                            Q_ARG(int, shiftData),
                            Q_ARG(int, verticalScrollBarMaximum),
                            Q_ARG(int, verticalScrollBarValue),
                            Q_ARG(QDateTime, checkDateTime),
                            Q_ARG(bool, reverse));
}


void GraphicPChSS::calculatedData(const QHash<QPair<int, int>, double>& result, int keySize, int valueSize, int yRange,
                                const QDateTime& bottomRange, int verticalScrollBarValue)
{
  m_colorMap->data()->clear();
  m_colorMap->data()->setSize(keySize, valueSize);
  const int secs = bottomRange.time().msecsSinceStartOfDay() / 1000.0;
  m_colorMap->data()->setRange(QCPRange(0, keySize), QCPRange(secs + verticalScrollBarValue,
                                                              secs + valueSize + verticalScrollBarValue));
  QHashIterator<QPair<int, int>, double> iter(result);
  while (iter.hasNext())
  {
    iter.next();
    m_colorMap->data()->setCell(iter.key().first, iter.key().second, iter.value());
  }

  // rescale the data dimension (color) such that all data points lie in the span visualized by the color gradient:
  //m_colorMap->rescaleDataRange();

  // rescale the key (x) and value (y) axes so the whole color map is visible:
  rescaleAxes();

  yAxis->rescale();
  replot();
}


void GraphicPChSS::clearData()
{
  m_colorMap->data()->clear();
  m_colorMap->data()->setSize(128, 60);
  m_colorMap->data()->setRange(QCPRange(0, 128), QCPRange(0, 60));
  // rescale the data dimension (color) such that all data points lie in the span visualized by the color gradient:
  //m_colorMap->rescaleDataRange();

  // rescale the key (x) and value (y) axes so the whole color map is visible:
  rescaleAxes();

  yAxis->rescale();
  replot();
}


void GraphicPChSS::setGradient(const QCPColorGradient& gradient)
{
  m_colorMap->setGradient(gradient);
}


void GraphicPChSS::mouseMove(QMouseEvent* event)
{

}


void GraphicPChSS::mousePress(QMouseEvent* event)
{
  const int x = xAxis->pixelToCoord(event->pos().x());
  const int y = yAxis->pixelToCoord(event->pos().y());

  // Проверяем чтобы клик был только по обрасти графика
  if (!m_colorMap->data()->keyRange().contains(x) || m_colorMap->data()->keyRange().contains(y))
    return;

  m_colorMap->setPoint(QPoint(x, y));
  replot();
}
