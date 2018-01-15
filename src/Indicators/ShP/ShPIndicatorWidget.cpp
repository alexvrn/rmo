// Local
#include "ShPIndicatorWidget.h"
#include "ui_ShPIndicatorWidget.h"
#include "Graphic.h"
#include "Client.h"
#include "GraphicWidget.h"

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

  // Индикаторная картина ШП
  m_buttonGroup->addButton(ui->pchToolButton);
  m_buttonGroup->addButton(ui->ps1t1ToolButton, CommandType::Stream_3);
  m_buttonGroup->addButton(ui->ps2t1ToolButton, CommandType::Stream_4);
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
  ui->graphicWidget->setLightMode(mode);
}


void ShPIndicatorWidget::newData()
{
  // Берем данные в зависимости от режима (текущие данные или выбранные для определённой даты)
  const auto pgasData = isNowData() ? Client::instance().pgasData() : m_selectedData;
  const auto data = pgasData[m_pgasNumber][static_cast<CommandType::Command>(m_buttonGroup->checkedId())];

  ui->graphicWidget->setData(data);
}


void ShPIndicatorWidget::setCurrentPgasNumber(int pgasNumber)
{
  m_pgasNumber = pgasNumber;
  newData();
}


int ShPIndicatorWidget::currentPgasNumber() const
{
  return m_pgasNumber;
}


void ShPIndicatorWidget::setNowData(bool nowData)
{
  m_nowData = nowData;
  newData();
}


bool ShPIndicatorWidget::isNowData() const
{
  return m_nowData;
}


void ShPIndicatorWidget::setSelectedData(const PgasData& selectedData, const QDateTime& checkDateTime)
{
  m_selectedData = selectedData;
  m_checkDateTime = checkDateTime;
  newData();
}


void ShPIndicatorWidget::shpIndicatorView(QAbstractButton* button, bool checked)
{
  if (checked)
  {
    //ui->widget_2->xAxis->setLabel(button->text());
    //ui->widget_2->replot();
  }

  newData();
}


void ShPIndicatorWidget::on_predIndicatorComboBox_activated(int index)
{
  Q_UNUSED(index);
  //ui->widget_2->replot();
}
