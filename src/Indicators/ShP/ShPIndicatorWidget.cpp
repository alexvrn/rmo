// Local
#include "ShPIndicatorWidget.h"
#include "ui_ShPIndicatorWidget.h"
#include "PaletteWidget.h"
#include "Graphic.h"
#include "Client.h"

// Qt
#include <QToolButton>
#include <QButtonGroup>
#include <QAbstractButton>
#include <QPalette>
#include <QHash>
#include <QScrollBar>
#include <QSettings>

ShPIndicatorWidget::ShPIndicatorWidget(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::ShPIndicatorWidget)
  , m_graphColor(QColor(0,255,0))
  , m_pgasNumber(1)
  , m_buttonGroup(new QButtonGroup(this))
  , m_nowData(true)
  , m_seconds(0)
{
  ui->setupUi(this);

  // Количество секунд для отображения
  QSettings settings("SAMI_DVO_RAN", "rmo");
  m_seconds = settings.value("SHP/seconds", 60).toInt();

  connect(ui->paletteComboBox, SIGNAL(activated(int)), this, SLOT(setGradient(int)));
  //connect(ui->paletteWidget, SIGNAL(colorValue(QColor)), SLOT(colorValue(QColor)));

  // Индикаторная картина ШП
  m_buttonGroup->addButton(ui->pchToolButton);
  m_buttonGroup->addButton(ui->ps1t1ToolButton, CommandType::Stream_3);
  m_buttonGroup->addButton(ui->ps2t1ToolButton, CommandType::Stream_4);
  m_buttonGroup->addButton(ui->ps1t2ToolButton);
  m_buttonGroup->addButton(ui->ps2t2ToolButton);
  connect(m_buttonGroup, SIGNAL(buttonToggled(QAbstractButton*,bool)), SLOT(shpIndicatorView(QAbstractButton*,bool)));

  // Иконки
  ui->contrastLabel->setPixmap(QIcon(":/icons/contrast.png").pixmap(25, 25));
  ui->brightnessLabel->setPixmap(QIcon(":/icons/sun.png").pixmap(32, 32));
  ui->toolButtonGrid->setIcon(QIcon::fromTheme(":/icons/arrow_close_minimize-20.png"));
  ui->orientationToolButton->setIcon(QIcon(":/icons/inout-32.png"));
  ui->countToolButton->setIcon(QIcon(":/icons/arrow-double-up-down-32.png"));

  connect(ui->brightnessSlider, SIGNAL(valueChanged(int)), SLOT(brightness(int)));


  // http://www.qcustomplot.com/index.php/demos/colormapdemo
  // configure axis rect:
  ui->widget_2->setInteractions(QCP::iSelectAxes|QCP::iRangeDrag); // this will also allow rescaling the color scale by dragging/zooming
  ui->widget_2->axisRect()->setupFullAxesBox(true);
  ui->widget_2->xAxis->setLabel("");
  ui->widget_2->yAxis->setLabel("T");

  //ui->widget_2->setLocale(QLocale(QLocale::Russian, QLocale::RussianFederation));
  //QSharedPointer<QCPAxisTickerDateTime> dateTicker(new QCPAxisTickerDateTime);
  //dateTicker->setDateTimeFormat("h.m.s");
  //ui->widget_2->yAxis->setTicker(dateTicker);

  ui->widget_2->yAxis->setRangeUpper(50);

  // set up the QCPColorMap:
  m_colorMap = new QCPColorMap(ui->widget_2->xAxis, ui->widget_2->yAxis);
  // add a color scale:
  QCPColorScale *colorScale = new QCPColorScale(ui->widget_2);
  ui->widget_2->plotLayout()->addElement(0, 1, colorScale); // add it to the right of the main axis rect
  colorScale->setType(QCPAxis::atRight); // scale shall be vertical bar with tick/axis labels right (actually atRight is already the default)
  m_colorMap->setColorScale(colorScale); // associate the color map with the color scale
  //colorScale->axis()->setLabel("Magnetic Field Strength");
  QCPColorGradient gradien;
  QMap<double, QColor> colorStops;
  colorStops[0] = QColor(0, 50, 0);
  colorStops[+1] = QColor(0, 255, 0);
  gradien.setColorStops(colorStops);

  // set the color gradient of the color map to one of the presets:
  m_colorMap->setGradient(gradien);//QCPColorGradient::gpJet);
  // we could have also created a QCPColorGradient instance and added own colors to
  // the gradient, see the documentation of QCPColorGradient for what's possible.


  // make sure the axis rect and color scale synchronize their bottom and top margins (so they line up):
  QCPMarginGroup *marginGroup = new QCPMarginGroup(ui->widget_2);
  ui->widget_2->axisRect()->setMarginGroup(QCP::msBottom | QCP::msTop, marginGroup);
  colorScale->setMarginGroup(QCP::msBottom|QCP::msTop, marginGroup);

  ui->paletteWidget->setPalette(0);

  setHasSwitch(false);
  connect(ui->countToolButton, SIGNAL(clicked(bool)), this, SIGNAL(countWidget()));

  ui->verticalScrollBar->setRange(-500, 500);
  connect(ui->verticalScrollBar, SIGNAL(valueChanged(int)), this, SLOT(vertScrollBarChanged(int)));
  connect(ui->widget_2->yAxis, SIGNAL(rangeChanged(QCPRange)), this, SLOT(yAxisChanged(QCPRange)));

  QPalette pal(ui->panel->palette());

  // устанавливаем цвет фона
  pal.setColor(QPalette::Background, QColor(200, 200, 200));
  ui->panel->setAutoFillBackground(true);
  ui->panel->setPalette(pal);

  const QString style = "background-color: rgb(200,200,200, 20);";
  //ui->labelX->setStyleSheet(style);
  //ui->labelY->setStyleSheet(style);
  //ui->typeLabel->setStyleSheet(style);
  ui->contrastLabel->setStyleSheet(style);
  ui->brightnessLabel->setStyleSheet(style);

  // Подцветка
  setLightMode(settings.value("mode", "sun").toString());

  ui->customPlot->hide();
  ui->paletteWidget->hide();
  //ui->labelY->hide();
  //ui->labelX->hide();
  //ui->typeLabel->hide();

  ui->pchToolButton->setChecked(true);
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


void ShPIndicatorWidget::setGradient(int value)
{
  if (value == 0)
  {
    QCPColorGradient gradien;
    QMap<double, QColor> colorStops;
    colorStops[0] = QColor(0, 50, 0);
    colorStops[+1] = QColor(0, 255, 0);
    gradien.setColorStops(colorStops);

    m_colorMap->setGradient(gradien);
  }
  else
  {
    m_colorMap->setGradient(QCPColorGradient::gpSpectrum);
  }

  ui->widget_2->replot();
}


void ShPIndicatorWidget::dataRepaint()
{
  m_colorMap->data()->clear();

  if (m_buttonGroup->checkedId() == -1)
  {
    ui->widget_2->replot();
    return;
  }

  // Берем данные в зависимости от режима (текущие данные или выбранные для определённой даты)
  const auto pgasData = isNowData() ? Client::instance().pgasData() : m_selectedData;
  const auto data = pgasData[m_pgasNumber][static_cast<CommandType::Command>(m_buttonGroup->checkedId())];

  int nx = 128;
  int ny = isNowData() ? m_seconds : 60;//(data.length() - indexBegin) / 128;

  m_colorMap->data()->setSize(nx, ny); // we want the color map to have nx * ny data points
  m_colorMap->data()->setRange(QCPRange(0, nx), QCPRange(0, ny)); // and span the coordinate range -4..4 in both key (x) and value (y) dimensions

 // ui->widget_2->yAxis->setRange(QDateTime::currentDateTime().toTime_t(), QDateTime::currentDateTime().toTime_t() + m_seconds);

  // Прединдикаторная обработка
  //! TODO
  const int predIndicator = ui->predIndicatorComboBox->currentIndex();

  QHash<QDateTime, int> v;
  // Убираем миллисекунды
  QDateTime bottomRange = isNowData() ? QDateTime::currentDateTime().addSecs(-m_seconds) : m_checkDateTime;
  const QTime bottomTime = QTime(bottomRange.time().hour(),
                                 bottomRange.time().minute(),
                                 bottomRange.time().second());
  bottomRange.setTime(bottomTime);

  for (int i = 0; i < ny; ++i)
    v[bottomRange.addSecs(i + 1)] = i;

  for (int index = 0; index < data.length(); index++)
  {
    const uint timestamp = data[index]["timestamp"].toUInt();
    QDateTime dateTime = QDateTime::fromSecsSinceEpoch(timestamp);

    // Обнуляем секунды
    const QTime checkTime = dateTime.time();
    const QTime time(checkTime.hour(), checkTime.minute(), checkTime.second());
    dateTime.setTime(time);
    if (!v.contains(dateTime))
      continue;

    const int xIndex = data[index]["beamCount"].toInt();
    m_colorMap->data()->setCell(xIndex, v[dateTime], data[index]["data"].toDouble());
  }

//  int yIndex = 0;
//  //QVector<double> v(128, 0);
//  for (int index = 0; index < data.length(); index++)
//  {
//    const int xIndex = data[index]["beamCount"].toInt();
//    m_colorMap->data()->setCell(xIndex, yIndex, data[index]["data"].toDouble());
//    //v[xIndex] = data[index]["data"].toDouble();
//    //qDebug() << xIndex;
//    if (xIndex == 127)
//    {
//      //for (int i = 0; i < 128; i++)
//      //  colorMap->data()->setCell(i, yIndex, v[i]);
//      //qDebug() << v;
//      //v.fill(0);
//      yIndex++;
//      qDebug() << "New" << yIndex;
//      //qDebug() << "Строка" << yIndex << data.length() << index;
//      //for (int i = 0; i < 128; ++i)
//      //  m_colorMap->data()->setCell(i, yIndex, 0.7);
//    }
//  }

  // rescale the data dimension (color) such that all data points lie in the span visualized by the color gradient:
  //m_colorMap->rescaleDataRange();

  // rescale the key (x) and value (y) axes so the whole color map is visible:
  ui->widget_2->rescaleAxes();

  ui->widget_2->replot();
}


void ShPIndicatorWidget::newData()
{
  dataRepaint();
}


void ShPIndicatorWidget::setCurrentPgasNumber(int pgasNumber)
{
  m_pgasNumber = pgasNumber;
  dataRepaint();
}


int ShPIndicatorWidget::currentPgasNumber() const
{
  return m_pgasNumber;
}


void ShPIndicatorWidget::setNowData(bool nowData)
{
  m_nowData = nowData;
  dataRepaint();
}


bool ShPIndicatorWidget::isNowData() const
{
  return m_nowData;
}


void ShPIndicatorWidget::setSelectedData(const PgasData& selectedData, const QDateTime& checkDateTime)
{
  m_selectedData = selectedData;
  m_checkDateTime = checkDateTime;
  dataRepaint();
}


void ShPIndicatorWidget::shpIndicatorView(QAbstractButton* button, bool checked)
{
  if (checked)
  {
    //ui->typeLabel->setText(button->text());
    ui->widget_2->xAxis->setLabel(button->text());
    ui->widget_2->replot();
  }

  dataRepaint();
}


void ShPIndicatorWidget::on_orientationToolButton_clicked()
{
  ui->customPlot->setOrientation(!ui->customPlot->orientation());
}


void ShPIndicatorWidget::vertScrollBarChanged(int value)
{
  if (qAbs(ui->widget_2->yAxis->range().center()+value/100.0) > 0.01) // if user is dragging plot, we don't want to replot twice
  {
    ui->widget_2->yAxis->setRange(-value/100.0, ui->widget_2->yAxis->range().size(), Qt::AlignCenter);
    ui->widget_2->replot();
  }
}


void ShPIndicatorWidget::yAxisChanged(QCPRange range)
{
  ui->verticalScrollBar->setValue(qRound(-range.center()*100.0)); // adjust position of scroll bar slider
  ui->verticalScrollBar->setPageStep(qRound(range.size()*100.0)); // adjust size of scroll bar slider
}


void ShPIndicatorWidget::on_toolButtonGrid_toggled(bool checked)
{
  ui->widget_2->xAxis->grid()->setVisible(checked);
  ui->widget_2->yAxis->grid()->setVisible(checked);
}


void ShPIndicatorWidget::on_predIndicatorComboBox_activated(int index)
{
  Q_UNUSED(index);
  ui->widget_2->replot();
}
