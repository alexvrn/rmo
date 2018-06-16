#ifndef ZPSINDICATORDATA_H
#define ZPSINDICATORDATA_H

// Qt
#include <QWidget>

// UI
namespace Ui
{
  class ZPSIndicatorData;
}

class ZPSIndicatorData : public QWidget
{
  Q_OBJECT

  public:
    explicit ZPSIndicatorData(QWidget *parent = 0);
    ~ZPSIndicatorData();

  private slots:
    void on_inputPushButton_clicked();
    void on_outputPushButton_clicked();

private:
    Ui::ZPSIndicatorData *ui;
};

#endif // ZPSINDICATORDATA_H
