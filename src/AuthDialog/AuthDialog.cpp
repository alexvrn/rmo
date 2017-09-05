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
  ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);

  QVariantMap userData;
  userData["login"] = ui->loginLineEdit->text();
  userData["password"] = ui->passwordLineEdit->text();
  emit authentication(userData);
}


int AuthDialog::exec()
{
  ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
  ui->loginLineEdit->clear();
  ui->passwordLineEdit->clear();

  return QDialog::exec();
}
