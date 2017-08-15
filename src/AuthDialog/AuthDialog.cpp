// Local
#include "AuthDialog.h"
#include "ui_AuthDialog.h"

AuthDialog::AuthDialog(QWidget *parent)
  : QDialog(parent)
  , ui(new Ui::AuthDialog)
{
  ui->setupUi(this);
}


AuthDialog::~AuthDialog()
{
  delete ui;
}
