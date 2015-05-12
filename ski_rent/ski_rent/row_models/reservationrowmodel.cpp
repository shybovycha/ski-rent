#include "row_models/reservationrowmodel.h"

ReservationRowModel::ReservationRowModel(const QList<Reservation*> &entities, QObject *parent)  : QAbstractTableModel(parent), entities(entities)
{
    this->setColumns();
}

void ReservationRowModel::add(Reservation* e) {
    int n = this->entities.size();
    this->entities.append(e);
    this->insertRow(n);
}

void ReservationRowModel::add(const QList<Reservation*> &e) {
    int n = this->entities.size();
    this->entities.append(e);
    this->insertRows(n, e.size());
}

bool ReservationRowModel::insertRows(int position, int rows, const QModelIndex &index) {
    beginInsertRows(QModelIndex(), position, position + rows - 1);

    for (int row = 0; row < rows; row++) {
        if ((position + row) > this->entities.size())
            this->entities.insert(position, new Reservation());
    }

    endInsertRows();

    return true;
}

Reservation* ReservationRowModel::at(int index) const {
    return this->entities.at(index);
}

ReservationRowModel::ReservationRowModel(QObject *parent)  : QAbstractTableModel(parent)
{
    this->setColumns();
}

ReservationRowModel::~ReservationRowModel() {
}

void ReservationRowModel::clear() {
    int n = this->entities.size();
    this->entities.clear();
    this->removeRows(0, n);
}

int ReservationRowModel::columnCount(const QModelIndex &parent) const {
    return this->columns.size();
}

int ReservationRowModel::rowCount(const QModelIndex &parent) const {
    return this->entities.size();
}

QVariant ReservationRowModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal)
        return this->columns.values()[section];
    else
        return QString::number(section + 1);
}

Qt::ItemFlags ReservationRowModel::flags(const QModelIndex &index) const {
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

bool ReservationRowModel::removeRows(int position, int rows, const QModelIndex &index) {
    beginRemoveRows(QModelIndex(), position, position + rows - 1);

    for (int row = 0; row < rows; row++) {
        if (position < this->entities.size())
            this->entities.removeAt(position);
    }

    endRemoveRows();

    return true;
}

void ReservationRowModel::setColumns() {
    columns.clear();
    columns["user"] = tr("User");
    columns["equipment"] = tr("Equipment");
    columns["amount"] = tr("Amount");
    columns["rent_from"] = tr("Rent from");
    columns["rent_to"] = tr("Rent to");
}

QVariant ReservationRowModel::data(const QModelIndex &index, int role) const {
    if (index.isValid() && index.row() < this->entities.size() && role == Qt::DisplayRole) {
        QString key = this->columns.keys().at(index.column());
        Reservation* e = this->entities.at(index.row());

        if (key == "user") {
            User* u = UserDAOSingleton::instance()->findById(e->getUserId());
            return u->getName();
        } else if (key == "equipment") {
            Equipment* u = EquipmentDAOSingleton::instance()->findById(e->getEquipmentId());
            return u->getType();
        }

        return e->get(key);
    } else {
        return QVariant();
    }
}
