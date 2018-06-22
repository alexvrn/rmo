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

    enum SideType
    {
      Left,
      Right
    };

    explicit ButtonGroup(SideType sideType, QWidget *parent = Q_NULLPTR);
    ~ButtonGroup();

  public Q_SLOTS:
    QString setConfiguration(const QString& type, const QStringList& filter = QStringList());
    QString fromOtherIndicatorChecked(const QString& type);

  signals:
    void indicatorChecked(const QString& type);
    void currentIndicators(const QString& leftType, const QString& rightType);

  private Q_SLOTS:
    void clicked(const QString& type);
    QString currentType() const;
    void clear();

  private:
    Ui::ButtonGroup *ui;

    QSignalMapper *m_mapper;
    QHash<QString, QToolButton*> m_map;

    SideType m_sideType;
};

#endif // BUTTONGROUP_H
