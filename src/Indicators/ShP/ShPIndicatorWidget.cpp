// Local
#include "ShPIndicatorWidget.h"
#include "ui_ShPIndicatorWidget.h"
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
  , m_graphic(nullptr)
{
  ui->setupUi(this);

  // Количество секунд для отображения
  QSettings settings("SAMI_DVO_RAN", "rmo");
  m_seconds = settings.value("SHP/seconds", 60).toInt();

  // Индикаторная картина ШП
  m_buttonGroup->addButton(ui->pchToolButton);
  m_buttonGroup->addButton(ui->ps1t1ToolButton, CMD_STREAM3);
  m_buttonGroup->addButton(ui->ps2t1ToolButton, CMD_STREAM4);
  m_buttonGroup->addButton(ui->ps1t2ToolButton);
  m_buttonGroup->addButton(ui->ps2t2ToolButton);
  connect(m_buttonGroup, SIGNAL(buttonToggled(QAbstractButton*,bool)), SLOT(shpIndicatorView(QAbstractButton*,bool)));

  // Иконки
  ui->countToolButton->setIcon(QIcon(":/icons/arrow-double-up-down-32.png"));

  setHasSwitch(false);
  connect(ui->countToolButton, SIGNAL(clicked(bool)), this, SIGNAL(countWidget()));

  // Подцветка
  setLightMode(settings.value("mode", "sun").toString());

  ui->pchToolButton->setChecked(true);

  m_graphics = QList<AbstractGraphic*>() << ui->graphic_shp1 << ui->graphic_shp2 << ui->graphic_pchss;
  //for (auto graphic : m_graphics)
  //  connect(graphic, SIGNAL(info(QString)), this, SIGNAL(info(QString)));
  connect(ui->graphic_shp1, SIGNAL(info(QString)), this, SIGNAL(info(QString)));
  connect(ui->graphic_shp2, SIGNAL(info(QString)), this, SIGNAL(info(QString)));
  connect(ui->graphic_pchss, SIGNAL(info(QString)), this, SIGNAL(info(QString)));
  setIndicatorType(AbstractGraphic::ShP);

  connect(&m_replotTimer, SIGNAL(timeout()), SLOT(dataRepaint()));
  m_replotTimer.start(10000);
  dataRepaint();
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


void ShPIndicatorWidget::setLightMode(const QString& mode)
{
  //ui->graphicWidget->setLightMode(mode);
}


//! update - если true, то обновляем картинку данных
void ShPIndicatorWidget::newData(bool update)
{
  if (m_buttonGroup->checkedId() == -1)
  {
    setData(QList<QVariantMap>());
    return;
  }

  if (update)
  {
    // Берем данные в зависимости от режима (текущие данные или выбранные для определённой даты)
    const auto pgasData = isNowData() ? Client::instance().pgasData() : m_selectedData;
    const auto data = pgasData[m_pgasNumber][static_cast<cmd_e>(m_buttonGroup->checkedId())];

    setData(data, m_checkDateTime);
  }
}


void ShPIndicatorWidget::setCurrentPgasNumber(int pgasNumber)
{
  m_pgasNumber = pgasNumber;
  newData(true);
}


int ShPIndicatorWidget::currentPgasNumber() const
{
  return m_pgasNumber;
}


void ShPIndicatorWidget::setNowData(bool nowData)
{
  m_nowData = nowData;

  m_graphic->setNowData(nowData);
  //colorScaleLayout();
  dataGraphicRepaint();

  newData(true);
}


bool ShPIndicatorWidget::isNowData() const
{
  return m_nowData;
}


void ShPIndicatorWidget::setSelectedData(const PgasData& selectedData, const QDateTime& checkDateTime)
{
  m_selectedData = selectedData;
  m_checkDateTime = checkDateTime;

  newData(true);
}


void ShPIndicatorWidget::shpIndicatorView(QAbstractButton* button, bool checked)
{
  if (checked)
  {
    cmd_e buttonType = static_cast<cmd_e>(m_buttonGroup->id(button));
    setDataType(button->text(), buttonType);
  }

  newData(true);
}


void ShPIndicatorWidget::dataRepaint()
{
  newData(true);
}


void ShPIndicatorWidget::setIndicatorType(AbstractGraphic::IndicatorType indicatorType)
{
  for (auto graphic : m_graphics)
    graphic->setIndicatorType(indicatorType);
}


void ShPIndicatorWidget::setData(const QList<QVariantMap> &data, const QDateTime& dateTime)
{
  m_data = data;
  m_checkDateTime = dateTime;

  // Обновляем данные не сразу, а по таймеру через каждые 10 секунд
  dataGraphicRepaint();
}


void ShPIndicatorWidget::dataGraphicRepaint()
{
  if (m_data.isEmpty())
  {
    clearData();
    return;
  }

  m_graphic->replot(m_data, m_checkDateTime);
}


void ShPIndicatorWidget::clearData()
{
  if (!m_graphic)
    return;

  m_graphic->clearData();
}


void ShPIndicatorWidget::setDataType(const QString& text, cmd_e type)
{
  m_type = type;
  if (type == CMD_STREAM3)
  {
    ui->graphicWidget->setCurrentIndex(1);
    m_graphic = ui->graphic_shp1;
  }
  else if (type == CMD_STREAM4)
  {
    ui->graphicWidget->setCurrentIndex(2);
    m_graphic = ui->graphic_shp2;
  }
  else
  {
    ui->graphicWidget->setCurrentIndex(0);
    m_graphic = ui->graphic_pchss;
  }

  m_graphic->setLabel(text);

  dataGraphicRepaint();
}
