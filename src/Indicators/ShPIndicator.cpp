// Local
#include "ShPIndicator.h"
#include "ui_ShPIndicator.h"
#include "PaletteWidget.h"

// Qt
#include <QDebug>


ShPIndicator::ShPIndicator(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::ShPIndicator)
{
  ui->setupUi(this);

  connect(ui->paletteComboBox, SIGNAL(activated(int)), ui->paletteLabel, SLOT(setPalette(int)));
  ui->paletteLabel->setPalette(0);
}


ShPIndicator::~ShPIndicator()
{
  delete ui;
}

