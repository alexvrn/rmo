#ifndef AUTHDIALOG_H
#define AUTHDIALOG_H

// Qt
#include <QDialog>

// UI
namespace Ui
{
class AuthDialog;
}

class AuthDialog : public QDialog
{
  Q_OBJECT

  public:
    explicit AuthDialog(QWidget *parent = Q_NULLPTR);
    ~AuthDialog();

  signals:
    void authentication(const QVariantMap& userData);

  public slots:
    void accept() Q_DECL_OVERRIDE;
    int exec() Q_DECL_OVERRIDE;

  private:
    Ui::AuthDialog *ui;
};

#endif // AUTHDIALOG_H
