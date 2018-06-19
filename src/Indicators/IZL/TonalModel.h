#ifndef TONALMODEL_H
#define TONALMODEL_H

// Qt
#include <QAbstractTableModel>

class TonalModel : public QAbstractTableModel
{
  Q_OBJECT

  public:
    explicit TonalModel(QObject *parent = nullptr);

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

  private:
    QList<int> m_data;
};

#endif // TONALMODEL_H
