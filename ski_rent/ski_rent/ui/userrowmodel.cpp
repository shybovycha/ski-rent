#include "userrowmodel.h"

UserRowModel::UserRowModel(QObject *parent) : QAbstractTableModel(parent)
{
    this->setColumns();
}

UserRowModel::UserRowModel(const QList<User> &users, QObject *parent) : QAbstractTableModel(parent), users(users)
{
    this->setColumns();
}

UserRowModel::~UserRowModel() {
}

void UserRowModel::clear() {
    this->users.clear();
}

void UserRowModel::add(const QList<User> &e) {
    this->users.append(e);
    this->insertRows(this->users.size(), e.size());
}

void UserRowModel::add(const User &user) {
    this->users.append(user);
    this->insertRow(this->users.size());
}

void UserRowModel::setColumns() {
    columns.clear();
    columns["name"] = tr("Name");
    columns["surname"] = tr("Surname");
    columns["document_type"] = tr("Document type");
    columns["document_number"] = tr("Document number");
    columns["country"] = tr("Country");
    columns["city"] = tr("City");
    columns["address"] = tr("Address");
    columns["phone"] = tr("Phone");
}

int UserRowModel::columnCount(const QModelIndex &parent) const {
    return this->columns.size();
}

int UserRowModel::rowCount(const QModelIndex &parent) const {
    return this->users.size();
}

QVariant UserRowModel::data(const QModelIndex &index, int role) const {
    if (index.isValid() && index.row() < this->users.size() && role == Qt::DisplayRole) {
        return this->users.at(index.row()).get(this->columns.keys().at(index.column()));
    } else {
        return QVariant();
    }
}

QVariant UserRowModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal)
        return this->columns.values().at(section);
    else
        return QString::number(section + 1);
}

bool UserRowModel::insertRows(int position, int rows, const QModelIndex &index) {
    beginInsertRows(QModelIndex(), position, position + rows - 1);

    for (int row = 0; row < rows; row++) {
        if ((position + row) >= this->users.size())
            this->users.insert(position, User());
    }

    endInsertRows();

    return true;
}

bool UserRowModel::removeRows(int position, int rows, const QModelIndex &index) {
    beginRemoveRows(QModelIndex(), position, position + rows - 1);

    for (int row = 0; row < rows; row++) {
        this->users.removeAt(position);
    }

    endRemoveRows();

    return true;
}
