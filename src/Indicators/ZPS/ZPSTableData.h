#ifndef ZPSTABLEDATA_H
#define ZPSTABLEDATA_H

// Qt
#include <QAbstractTableModel>

class ZPSTableData : public QAbstractTableModel
{
  Q_OBJECT

  public:
    ZPSTableData(QObject *parent = Q_NULLPTR);

    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

  private:
    QList<int> m_data;
};

#endif // ZPSTABLEDATA_H
