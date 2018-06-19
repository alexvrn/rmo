// Local
#include "TonalModel.h"

TonalModel::TonalModel(QObject *parent)
  : QAbstractTableModel(parent)
{
}


QVariant TonalModel::headerData(int section, Qt::Orientation orientation, int role) const
{
  if (role != Qt::DisplayRole)
    return QAbstractTableModel::headerData(section, orientation, role);

  if (orientation == Qt::Horizontal)
  {
    switch (section)
    {
      case 0:
        return tr("Код");
      case 1:
        return tr("Дальность");
      default:
        return QAbstractTableModel::headerData(section, orientation, role);;
    }
  }

  return QAbstractTableModel::headerData(section, orientation, role);
}


int TonalModel::rowCount(const QModelIndex &parent) const
{
  if (parent.isValid())
    return 0;

  return m_data.count();
}


int TonalModel::columnCount(const QModelIndex &parent) const
{
   return 2;
}


QVariant TonalModel::data(const QModelIndex &index, int role) const
{
  if (!index.isValid())
    return QVariant();

  // FIXME: Implement me!
  return QVariant();
}
