// Local
#include "AuthDialog.h"
#include "ui_AuthDialog.h"

#include <QPushButton>

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


void AuthDialog::accept()
{
  //ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
  QDialog::accept();
}
