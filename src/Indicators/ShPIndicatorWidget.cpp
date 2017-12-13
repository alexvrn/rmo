// Local
#include "ShPIndicatorWidget.h"
#include "ui_ShPIndicatorWidget.h"
#include "PaletteWidget.h"
#include "Graphic.h"

// Qt
#include <QToolButton>
#include <QButtonGroup>
#include <QAbstractButton>

// QCustomPlot
#include "qcustomplot.h"

ShPIndicatorWidget::ShPIndicatorWidget(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::ShPIndicatorWidget)
  , m_graphColor(QColor(0,255,0))
{
  ui->setupUi(this);

  connect(ui->paletteComboBox, SIGNAL(activated(int)), ui->paletteWidget, SLOT(setPalette(int)));
  //connect(ui->paletteWidget, SIGNAL(colorValue(QColor)), SLOT(colorValue(QColor)));

  // Индикаторная картина ШП
  QButtonGroup* buttonGroup = new QButtonGroup(this);
  buttonGroup->addButton(ui->pchToolButton);
  buttonGroup->addButton(ui->ps1t1ToolButton);
  buttonGroup->addButton(ui->ps2t1ToolButton);
  buttonGroup->addButton(ui->ps1t2ToolButton);
  buttonGroup->addButton(ui->ps2t2ToolButton);
  connect(buttonGroup, SIGNAL(buttonToggled(QAbstractButton*,bool)), SLOT(shpIndicatorView(QAbstractButton*,bool)));
  ui->pchToolButton->setChecked(true);

  // Иконки
  ui->contrastLabel->setPixmap(QIcon(":/icons/contrast.png").pixmap(25, 25));
  ui->brightnessLabel->setPixmap(QIcon(":/icons/sun.png").pixmap(32, 32));
  ui->toolButtonGrid->setIcon(QIcon::fromTheme(":/icons/arrow_close_minimize-20.png"));
  ui->orientationToolButton->setIcon(QIcon(":/icons/inout-32.png"));
  ui->countToolButton->setIcon(QIcon(":/icons/arrow-double-up-down-32.png"));

  connect(ui->brightnessSlider, SIGNAL(valueChanged(int)), SLOT(brightness(int)));

//  ui->customPlot->addGraph();

//  ui->customPlot->setBackground(QBrush(QColor(0, 200, 0)));
//  ui->customPlot->graph(0)->setPen(QPen(Qt::blue)); // line color blue for first graph
//  ui->customPlot->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20))); // first graph will be filled with translucent blue
//  ui->customPlot->addGraph();
//  ui->customPlot->graph(1)->setPen(QPen(Qt::red)); // line color red for second graph
//  // generate some points of data (y0 for first, y1 for second graph):
//  QVector<double> x(251), y0(251), y1(251);
//  for (int i=0; i<251; ++i)
//  {
//    x[i] = i;
//    y0[i] = qExp(-i/150.0)*qCos(i/10.0); // exponentially decaying cosine
//    y1[i] = qExp(-i/150.0);              // exponential envelope
//  }
//  // configure right and top axis to show ticks but no labels:
//  // (see QCPAxisRect::setupFullAxesBox for a quicker method to do this)
//  ui->customPlot->xAxis2->setVisible(true);
//  ui->customPlot->xAxis2->setTickLabels(false);
//  ui->customPlot->yAxis2->setVisible(true);
//  ui->customPlot->yAxis2->setTickLabels(false);
//  // make left and bottom axes always transfer their ranges to right and top axes:
//  connect(ui->customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot->xAxis2, SLOT(setRange(QCPRange)));
//  connect(ui->customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot->yAxis2, SLOT(setRange(QCPRange)));
//  // pass data points to graphs:
//  ui->customPlot->graph(0)->setData(x, y0);
//  ui->customPlot->graph(1)->setData(x, y1);
//  // let the ranges scale themselves so graph 0 fits perfectly in the visible area:
//  ui->customPlot->graph(0)->rescaleAxes();
//  // same thing for graph 1, but only enlarge ranges (in case graph 1 is smaller than graph 0):
//  ui->customPlot->graph(1)->rescaleAxes(true);
//  // Note: we could have also just called customPlot->rescaleAxes(); instead
//  // Allow user to drag axis ranges with mouse, zoom with mouse wheel and select graphs by clicking:
//  ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);



  /*ui->customPlot->addGraph(); // blue line
  ui->customPlot->graph(0)->setPen(QPen(m_graphColor));
  ui->customPlot->addGraph(); // red line
  ui->customPlot->graph(1)->setPen(QPen(m_graphColor));

  // X
  QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
  timeTicker->setTimeFormat("%h:%m:%s");
  ui->customPlot->xAxis->setTicker(timeTicker);
  ui->customPlot->axisRect()->setupFullAxesBox();
  QFont xFont = ui->customPlot->xAxis->labelFont();
  xFont.setBold(true);
  ui->customPlot->xAxis->setLabelFont(xFont);

  // Y
  ui->customPlot->yAxis->setRange(-1.2, 1.2);
  ui->customPlot->yAxis->setLabel("Гц");
  QFont yFont = ui->customPlot->yAxis->labelFont();
  yFont.setBold(true);
  ui->customPlot->yAxis->setLabelFont(yFont);
  ui->customPlot->yAxis->setLabelPadding(-15);

  // make left and bottom axes transfer their ranges to right and top axes:
  connect(ui->customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot->xAxis2, SLOT(setRange(QCPRange)));
  connect(ui->customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot->yAxis2, SLOT(setRange(QCPRange)));
  */

  ui->paletteWidget->setPalette(0);

  setHasSwitch(false);
  connect(ui->countToolButton, SIGNAL(clicked(bool)), this, SIGNAL(countWidget()));
}


ShPIndicatorWidget::~ShPIndicatorWidget()
{
  delete ui;
}


void ShPIndicatorWidget::setHasSwitch(bool hasSwitch)
{
  ui->countToolButton->setVisible(hasSwitch);
}


bool ShPIndicatorWidget::hasSwitch() const
{
  return ui->countToolButton->isVisible();
}


void ShPIndicatorWidget::colorValue(const QColor &color)
{
  m_graphColor = color;
  brightness(ui->brightnessSlider->value());
}


void ShPIndicatorWidget::brightness(int value)
{
  const QColor graphColorLighter = m_graphColor.lighter(value);
  //ui->customPlot->graph(0)->setPen(QPen(graphColorLighter));
  //ui->customPlot->graph(1)->setPen(QPen(graphColorLighter));
}


void ShPIndicatorWidget::setLightMode(const QString& mode)
{
  if (mode == "sun")
    ui->customPlot->setBackgroundColor(QColor(180, 180, 180));
  else if (mode == "night")
    ui->customPlot->setBackgroundColor(QColor(130, 130, 130));
}


void ShPIndicatorWidget::data(int cmd, const QByteArray& value)
{
  ui->customPlot->addData(QList<int>());
  //qDebug() << "111111";
  // add data to lines:
  //ui->customPlot->graph(0)->addData(key, value);
  //ui->customPlot->graph(1)->addData(key, value);

  // make key axis range scroll with the data (at a constant range size of 8):
  //ui->customPlot->xAxis->setRange(key, 8, Qt::AlignRight);
  //ui->customPlot->replot();
}


void ShPIndicatorWidget::shpIndicatorView(QAbstractButton* button, bool checked)
{
  if (checked)
    ui->typeLabel->setText(button->text());
}


void ShPIndicatorWidget::on_orientationToolButton_clicked()
{
  ui->customPlot->setOrientation(!ui->customPlot->orientation());
}
