#ifndef ZPSTABLEDATA_H
#define ZPSTABLEDATA_H

// Qt
#include <QAbstractTableModel>

//! FIXME: другое название, например ZPSDataModel

class ZPSTableData : public QAbstractTableModel
{
  Q_OBJECT

  public:
    ZPSTableData(QObject *parent = Q_NULLPTR);

    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

  private:
    QList<int> m_data;
};

#endif // ZPSTABLEDATA_H
