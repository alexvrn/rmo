#ifndef GLINDICATORWIDGET_H
#define GLINDICATORWIDGET_H

// Qt
#include <QWidget>

// UI
namespace Ui
{
  class GLIndicatorWidget;
}

class GLIndicatorWidget : public QWidget
{
  Q_OBJECT

  public:
    explicit GLIndicatorWidget(QWidget *parent = nullptr);
    ~GLIndicatorWidget();

    void setHasSwitch(bool hasSwitch);
    bool hasSwitch() const;

  signals:
    void countWidget();
    void info(const QString& text);

  private:
    Ui::GLIndicatorWidget *ui;
};

#endif // GLINDICATORWIDGET_H
