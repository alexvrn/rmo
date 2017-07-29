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

    QString indicatorCheck(const QString& type, bool checked);
    void setConfiguration(const QString& type);

  signals:
    void indicatorChecked(const QString& type, bool checked);

  private slots:
    void clicked(const QString& type);
    QString currentType() const;

  private:
    Ui::ButtonGroup *ui;

    QSignalMapper *m_mapper;
    QMap<QString, QToolButton*> m_map;
};

#endif // BUTTONGROUP_H
