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

  ui->graphicWidget->setIndicatorType(AbstractGraphic::ShP);

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
  ui->graphicWidget->setLightMode(mode);
}


//! update - если true, то обновляем картинку данных
void ShPIndicatorWidget::newData(bool update)
{
  if (m_buttonGroup->checkedId() == -1)
  {
    ui->graphicWidget->setData(QList<QVariantMap>());
    return;
  }

  // Берем данные в зависимости от режима (текущие данные или выбранные для определённой даты)
  const auto pgasData = isNowData() ? Client::instance().pgasData() : m_selectedData;
  const auto data = pgasData[m_pgasNumber][static_cast<CommandType::Command>(m_buttonGroup->checkedId())];

  if (update)
    ui->graphicWidget->setData(data, m_checkDateTime);
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
  ui->graphicWidget->setNowData(nowData);
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
    CommandType::Command buttonType = static_cast<CommandType::Command>(m_buttonGroup->id(button));
    ui->graphicWidget->setDataType(button->text(), buttonType);
  }

  newData(true);
}


void ShPIndicatorWidget::dataRepaint()
{
  newData(true);
}
