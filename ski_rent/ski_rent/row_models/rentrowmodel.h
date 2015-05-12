#ifndef RENTROWMODEL_H
#define RENTROWMODEL_H

#include "dao/userdao.h"
#include "dao/equipmentdao.h"

#include "entities/rent.h"
#include "row_models/abstractrowmodel.h"

#include <QObject>
#include <QList>
#include <QStringList>
#include <QVariant>
#include <QMap>
#include <QAbstractTableModel>

class RentRowModel : public QAbstractTableModel
{
public:
    RentRowModel(QObject *parent = 0);
    RentRowModel(const QList<Rent*> &entities, QObject *parent = 0);
    ~RentRowModel();

    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;

    virtual QVariant data(const QModelIndex &index, int role) const;
    virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

    Qt::ItemFlags flags(const QModelIndex &index) const;

    bool insertRows(int position, int rows, const QModelIndex &index = QModelIndex());
    bool removeRows(int position, int rows, const QModelIndex &index = QModelIndex());

    void add(Rent* e);
    void add(const QList<Rent*> &e);
    void clear();
    Rent* at(int index) const;

protected:
    virtual void setColumns();

    QList<Rent*> entities;
    QMap<QString, QString> columns;
};

#endif // RENTROWMODEL_H
