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
    int n = this->equipment.size();
    this->equipment.append(e);
    this->insertRow(n);
}

void EquipmentRowModel::add(const QList<Equipment> &e) {
    int n = this->equipment.size();
    this->equipment.append(e);
    this->insertRows(n, e.size());
}

void EquipmentRowModel::clear() {
    int n = this->equipment.size();
    this->equipment.clear();
    this->removeRows(0, n);
}

void EquipmentRowModel::setColumns() {
    columns.clear();
    columns["amount"] = tr("Amount");
    columns["type"] = tr("Type");
    columns["condition"] = tr("Condition");
}

int EquipmentRowModel::columnCount(const QModelIndex &parent) const {
    return this->columns.size();
}

int EquipmentRowModel::rowCount(const QModelIndex &parent) const {
    return this->equipment.size();
}

QVariant EquipmentRowModel::data(const QModelIndex &index, int role) const {
    if (index.isValid() && index.row() < this->equipment.size() && role == Qt::DisplayRole) {
        QString key = this->columns.keys().at(index.column());
        Equipment e = this->equipment.at(index.row());

        if (key == "condition") {
            return QString("%1").arg((char) e.getCondition());
        }

        return e.get(key);
    } else {
        return QVariant();
    }
}

QVariant EquipmentRowModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal)
        return this->columns.values()[section];
    else
        return QString::number(section + 1);
}

Qt::ItemFlags EquipmentRowModel::flags(const QModelIndex &index) const {
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

bool EquipmentRowModel::insertRows(int position, int rows, const QModelIndex &index) {
    beginInsertRows(QModelIndex(), position, position + rows - 1);

    for (int row = 0; row < rows; row++) {
        if ((position + row) > this->equipment.size())
            this->equipment.insert(position, Equipment());
    }

    endInsertRows();

    return true;
}

bool EquipmentRowModel::removeRows(int position, int rows, const QModelIndex &index) {
    beginRemoveRows(QModelIndex(), position, position + rows - 1);

    for (int row = 0; row < rows; row++) {
        if (position < this->equipment.size())
            this->equipment.removeAt(position);
    }

    endRemoveRows();

    return true;
}

Equipment EquipmentRowModel::at(int index) const {
    return this->equipment.at(index);
}
