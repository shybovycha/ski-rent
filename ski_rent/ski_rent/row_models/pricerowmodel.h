#ifndef PRICEROWMODEL_H
#define PRICEROWMODEL_H

#include "entities/price.h"

#include <QObject>
#include <QList>
#include <QStringList>
#include <QVariant>
#include <QMap>
#include <QAbstractTableModel>

class PriceRowModel : public QAbstractTableModel
{
public:
    PriceRowModel(QObject *parent = 0);
    PriceRowModel(const QList<Price*> &entities, QObject *parent = 0);
    ~PriceRowModel();

    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;

    virtual QVariant data(const QModelIndex &index, int role) const;
    virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

    Qt::ItemFlags flags(const QModelIndex &index) const;

    bool insertRows(int position, int rows, const QModelIndex &index = QModelIndex());
    bool removeRows(int position, int rows, const QModelIndex &index = QModelIndex());

    void add(Price* e);
    void add(const QList<Price*> &e);
    void clear();
    Price* at(int index) const;

protected:
    virtual void setColumns();

    QList<Price*> entities;
    QMap<QString, QString> columns;
};

#endif // PRICEROWMODEL_H

