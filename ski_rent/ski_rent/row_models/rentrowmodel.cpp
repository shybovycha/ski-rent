#include "row_models/rentrowmodel.h"

RentRowModel::RentRowModel(const QList<Rent*> &entities, QObject *parent)  : QAbstractTableModel(parent), entities(entities)
{
    this->setColumns();
}

void RentRowModel::add(Rent* e) {
    int n = this->entities.size();
    this->entities.append(e);
    this->insertRow(n);
}

void RentRowModel::add(const QList<Rent*> &e) {
    int n = this->entities.size();
    this->entities.append(e);
    this->insertRows(n, e.size());
}

bool RentRowModel::insertRows(int position, int rows, const QModelIndex &index) {
    beginInsertRows(QModelIndex(), position, position + rows - 1);

    for (int row = 0; row < rows; row++) {
        if ((position + row) > this->entities.size())
            this->entities.insert(position, new Rent());
    }

    endInsertRows();

    return true;
}

Rent* RentRowModel::at(int index) const {
    return this->entities.at(index);
}

RentRowModel::RentRowModel(QObject *parent)  : QAbstractTableModel(parent)
{
    this->setColumns();
}

RentRowModel::~RentRowModel() {
}

void RentRowModel::clear() {
    int n = this->entities.size();
    this->entities.clear();
    this->removeRows(0, n);
}

int RentRowModel::columnCount(const QModelIndex &parent) const {
    return this->columns.size();
}

int RentRowModel::rowCount(const QModelIndex &parent) const {
    return this->entities.size();
}

QVariant RentRowModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal)
        return this->columns.values()[section];
    else
        return QString::number(section + 1);
}

Qt::ItemFlags RentRowModel::flags(const QModelIndex &index) const {
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

bool RentRowModel::removeRows(int position, int rows, const QModelIndex &index) {
    beginRemoveRows(QModelIndex(), position, position + rows - 1);

    for (int row = 0; row < rows; row++) {
        if (position < this->entities.size())
            this->entities.removeAt(position);
    }

    endRemoveRows();

    return true;
}

void RentRowModel::setColumns() {
    columns.clear();
    columns["user"] = tr("User");
    columns["equipment"] = tr("Equipment");
    columns["condition"] = tr("Condition");
    columns["amount"] = tr("Amount");
    columns["rent_from"] = tr("Rent from");
}

QVariant RentRowModel::data(const QModelIndex &index, int role) const {
    if (index.isValid() && index.row() < this->entities.size() && role == Qt::DisplayRole) {
        QString key = this->columns.keys().at(index.column());
        Rent* e = this->entities.at(index.row());

        if (key == "user") {
            User* u = UserDAOSingleton::instance()->findById(e->getUserId());
            return u->getName();
        } else if (key == "equipment") {
            Equipment* u = EquipmentDAOSingleton::instance()->findById(e->getEquipmentId());
            return u->getType();
        } else if (key == "condition") {
            Equipment* u = EquipmentDAOSingleton::instance()->findById(e->getEquipmentId());
            return QString("").sprintf("%c", u->getCondition());
        }

        return e->get(key);
    } else {
        return QVariant();
    }
}
