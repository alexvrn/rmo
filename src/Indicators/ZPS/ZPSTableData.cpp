// Local
#include "ZPSTableData.h"

// Qt
#include <QDebug>

ZPSTableData::ZPSTableData(QObject *parent)
  : QAbstractTableModel(parent)
{
  m_data.append(1);
  m_data.append(1);
}


int ZPSTableData::rowCount(const QModelIndex &parent) const
{
  return m_data.count();
}


int ZPSTableData::columnCount(const QModelIndex &parent) const
{
  return 7;
}


QVariant ZPSTableData::data(const QModelIndex &index, int role) const
{
  if (role == Qt::DisplayRole)
  {
    QString unswer;// = QString("row = ") + QString::number(index.row()) + "  col = " + QString::number(index.column());
    return QVariant(unswer);
  }

  return QVariant();
}


QVariant ZPSTableData::headerData(int section, Qt::Orientation orientation, int role) const
{
  if (role != Qt::DisplayRole)
    return QAbstractTableModel::headerData(section, orientation, role);

  if (orientation == Qt::Horizontal)
  {
    switch (section)
    {
      case 0:
        return tr("Время");
      case 1:
        return tr("Дистанция, км");
      case 2:
        return tr("Пеленг, ");
      case 3:
        return tr("Канал");
      case 4:
        return tr("ОСШ инф, дБ");
      case 5:
        return tr("Длина");
      case 6:
        return tr("Состояние");
      default:
        return QAbstractTableModel::headerData(section, orientation, role);;
    }
  }

  return QAbstractTableModel::headerData(section, orientation, role);
}
