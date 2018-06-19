#ifndef VIEWERMODEL_H
#define VIEWERMODEL_H

// Qt
#include <QAbstractTableModel>


class ViewerModel : public QAbstractTableModel
{
  Q_OBJECT

  public:
    explicit ViewerModel(QObject *parent = nullptr);

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

  private:
    QList<int> m_data;
};

#endif // VIEWERMODEL_H
