#ifndef GLIndicator_H
#define GLIndicator_H

// Qt
#include <QWidget>

// Local
#include "Indicator.h"
class GLIndicatorWidget;

// UI
namespace Ui
{
  class GLIndicator;
}

class GLIndicator : public Indicator
{
  Q_OBJECT

  public:
    explicit GLIndicator(QWidget *parent = Q_NULLPTR);
    ~GLIndicator();

    QString name() const override;

  private Q_SLOTS:
    void deleteDownWidget();
    void countWidget();
    void insertDownWidget();

    void newData(cmd_e cmd, const QVariant& value = QVariant()) override;

  private:
    Ui::GLIndicator *ui;

    GLIndicatorWidget* m_upWidget;
    GLIndicatorWidget* m_downWidget;
};

#endif // GLIndicator_H
