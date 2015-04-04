#include "equipmentrowmodel.h"

EquipmentRowModel::EquipmentRowModel(QObject *parent)  : QAbstractTableModel(parent)
{
    this->setColumns();
}

EquipmentRowModel::EquipmentRowModel(const QList<Equipment> &equipment, QObject *parent)  : QAbstractTableModel(parent), equipment(equipment)
{
    this->setColumns();
}

EquipmentRowModel::~EquipmentRowModel() {
}

void EquipmentRowModel::add(const Equipment &e) {
    this->equipment.append(e);
}

void EquipmentRowModel::add(const QList<Equipment> &e) {
    this->equipment.append(e);
}

void EquipmentRowModel::clear() {
    this->equipment.clear();
}

void EquipmentRowModel::setColumns() {
    columns.clear();
    columns.append(tr("Type"));
    columns.append(tr("Amount"));
    columns.append(tr("Condition"));
}

int EquipmentRowModel::columnCount(const QModelIndex &parent) const {
    return this->columns.size();
}

int EquipmentRowModel::rowCount(const QModelIndex &parent) const {
    return this->equipment.size();
}

QVariant EquipmentRowModel::data(const QModelIndex &index, int role) const {
    if (index.isValid() && index.row() < this->equipment.size() && role == Qt::DisplayRole)
        return this->equipment.at(index.row()).getId();
    else
        return QVariant();
}

QVariant EquipmentRowModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal)
        return this->columns[section];
    else
        return QString::number(section);
}

bool EquipmentRowModel::insertRows(int position, int rows, const QModelIndex &index) {
    beginInsertRows(QModelIndex(), position, position + rows - 1);

    for (int row = 0; row < rows; row++) {
        this->equipment.insert(position, Equipment());
    }

    endInsertRows();

    return true;
}

bool EquipmentRowModel::removeRows(int position, int rows, const QModelIndex &index) {
    beginRemoveRows(QModelIndex(), position, position + rows - 1);

    for (int row = 0; row < rows; row++) {
        this->equipment.removeAt(position);
    }

    endRemoveRows();

    return true;
}
