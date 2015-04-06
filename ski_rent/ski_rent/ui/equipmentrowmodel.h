#ifndef EQUIPMENTROWMODEL_H
#define EQUIPMENTROWMODEL_H

#include "entities/equipment.h"

#include <QObject>
#include <QList>
#include <QStringList>
#include <QVariant>
#include <QMap>
#include <QAbstractTableModel>

class EquipmentRowModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    EquipmentRowModel(QObject *parent = 0);
    EquipmentRowModel(const QList<Equipment> &eqipment, QObject *parent = 0);
    ~EquipmentRowModel();

    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &parent, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;

    bool insertRows(int position, int rows, const QModelIndex &index = QModelIndex());
    bool removeRows(int position, int rows, const QModelIndex &index = QModelIndex());

    void add(const Equipment &e);
    void add(const QList<Equipment> &e);
    void clear();
    Equipment at(int index) const;

protected:
    void setColumns();

    QList<Equipment> equipment;
    QMap<QString, QString> columns;
};

#endif // EQUIPMENTROWMODEL_H
