#ifndef BUTTONGROUP_H
#define BUTTONGROUP_H

// Qt
#include <QWidget>
#include <QMap>
class QToolButton;
class QSignalMapper;

// UI
namespace Ui
{
  class ButtonGroup;
}


// Костыльный класс. Хотел использовать QButtonGroup, но там не смог сделать,
// чтобы все кнопки были отключены
class ButtonGroup : public QWidget
{
  Q_OBJECT

  public:
    explicit ButtonGroup(QWidget *parent = Q_NULLPTR);
    ~ButtonGroup();

  public Q_SLOTS:
    QString indicatorCheck(const QString& type, bool checked);
    void setConfiguration(const QString& type);
    QString fromOtherIndicatorChecked(const QString& type);

  signals:
    void indicatorChecked(const QString& type);
    void otherIndicatorChecked(const QString& type, bool visible = true);

  private Q_SLOTS:
    void clicked(const QString& type);
    QString currentType() const;
    void clear();

  private:
    Ui::ButtonGroup *ui;

    QSignalMapper *m_mapper;
    QHash<QString, QToolButton*> m_map;
};

#endif // BUTTONGROUP_H
