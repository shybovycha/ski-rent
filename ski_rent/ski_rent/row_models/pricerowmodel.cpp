#include "row_models/pricerowmodel.h"

PriceRowModel::PriceRowModel(const QList<Price*> &entities, QObject *parent)  : QAbstractTableModel(parent), entities(entities)
{
    this->setColumns();
}

void PriceRowModel::add(Price* e) {
    int n = this->entities.size();
    this->entities.append(e);
    this->insertRow(n);
}

void PriceRowModel::add(const QList<Price*> &e) {
    int n = this->entities.size();
    this->entities.append(e);
    this->insertRows(n, e.size());
}

bool PriceRowModel::insertRows(int position, int rows, const QModelIndex &index) {
    beginInsertRows(QModelIndex(), position, position + rows - 1);

    for (int row = 0; row < rows; row++) {
        if ((position + row) > this->entities.size())
            this->entities.insert(position, new Price());
    }

    endInsertRows();

    return true;
}

Price* PriceRowModel::at(int index) const {
    return this->entities.at(index);
}

PriceRowModel::PriceRowModel(QObject *parent)  : QAbstractTableModel(parent)
{
    this->setColumns();
}

PriceRowModel::~PriceRowModel() {
}

void PriceRowModel::clear() {
    int n = this->entities.size();
    this->entities.clear();
    this->removeRows(0, n);
}

int PriceRowModel::columnCount(const QModelIndex &parent) const {
    return this->columns.size();
}

int PriceRowModel::rowCount(const QModelIndex &parent) const {
    return this->entities.size();
}

QVariant PriceRowModel::data(const QModelIndex &index, int role) const {
    if (index.isValid() && index.row() < this->entities.size() && role == Qt::DisplayRole) {
        QString key = this->columns.keys().at(index.column());
        Price* e = (Price*) this->entities.at(index.row());

        if (key == "type")
            return e->getType();
        else if (key == "price")
            return e->getPrice();
        else if (key == "condition")
            return e->getCondition();
        else if (key == "time")
            return e->getTime();

        return QVariant();
    } else {
        return QVariant();
    }
}

QVariant PriceRowModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal)
        return this->columns.values()[section];
    else
        return QString::number(section + 1);
}

Qt::ItemFlags PriceRowModel::flags(const QModelIndex &index) const {
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

bool PriceRowModel::removeRows(int position, int rows, const QModelIndex &index) {
    beginRemoveRows(QModelIndex(), position, position + rows - 1);

    for (int row = 0; row < rows; row++) {
        if (position < this->entities.size())
            this->entities.removeAt(position);
    }

    endRemoveRows();

    return true;
}

void PriceRowModel::setColumns() {
    columns.clear();
    columns["type"] = tr("Equipment");
    columns["condition"] = tr("Condition");
    columns["time"] = tr("Rent time");
    columns["price"] = tr("Price");
}
