// Local
#include "ViewerModel.h"

ViewerModel::ViewerModel(QObject *parent)
  : QAbstractTableModel(parent)
{
}

QVariant ViewerModel::headerData(int section, Qt::Orientation orientation, int role) const
{
  if (role != Qt::DisplayRole)
    return QAbstractTableModel::headerData(section, orientation, role);

  if (orientation == Qt::Horizontal)
  {
    switch (section)
    {
      case 0:
        return tr("Дата задания");
      case 1:
        return tr("№");
      case 2:
        return tr("Тип");
      case 3:
        return tr("Начало излучения");
      case 4:
        return tr("Т изл, с");
      case 5:
        return tr("Т пауз, с");
      case 6:
        return tr("Р");
      case 7:
        return tr("Состояние");
      default:
        return QAbstractTableModel::headerData(section, orientation, role);;
    }
  }

  return QAbstractTableModel::headerData(section, orientation, role);
}


int ViewerModel::rowCount(const QModelIndex &parent) const
{
  if (parent.isValid())
    return 0;

  return m_data.count();
}


int ViewerModel::columnCount(const QModelIndex &parent) const
{
  if (parent.isValid())
    return 0;

  return 8;
}


QVariant ViewerModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
