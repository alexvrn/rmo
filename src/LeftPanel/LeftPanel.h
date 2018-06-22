#ifndef LEFTPANEL_H
#define LEFTPANEL_H

// Qt
#include <QFrame>
class QAbstractButton;

// Local
class ButtonGroup;

// UI
namespace Ui {
  class LeftPanel;
}

class LeftPanel : public QFrame
{
  Q_OBJECT

  public:
    explicit LeftPanel(QWidget *parent = Q_NULLPTR);
    ~LeftPanel();

  public slots:
    void setConfiguration(const QString& type);
    void fromOtherIndicatorChecked(const QString& type);

  signals:
    void indicatorChecked(const QString& type);
    void currentIndicators(const QString& leftType, const QString& rightType);

  private slots:
    // Сохранение настроек окна
    void settingsSave(const QString& type);

  private:
    Ui::LeftPanel *ui;

    ButtonGroup *m_group;
};

#endif // LEFTPANEL_H
