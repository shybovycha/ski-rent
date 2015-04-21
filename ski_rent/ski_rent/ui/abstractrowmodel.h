#ifndef ABSTRACTROWMODEL_H
#define ABSTRACTROWMODEL_H

#include "entities/baseentity.h"

#include <QObject>
#include <QList>
#include <QStringList>
#include <QVariant>
#include <QMap>
#include <QAbstractTableModel>

template<typename T>
class AbstractRowModel : public QAbstractTableModel
{
public:
    AbstractRowModel(QObject *parent = 0);
    AbstractRowModel(const QList<T*> &entities, QObject *parent = 0);
    ~AbstractRowModel();

    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;

    virtual QVariant data(const QModelIndex &index, int role) const;
    virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

    Qt::ItemFlags flags(const QModelIndex &index) const;

    bool insertRows(int position, int rows, const QModelIndex &index = QModelIndex());
    bool removeRows(int position, int rows, const QModelIndex &index = QModelIndex());

    void add(T* e);
    void add(const QList<T*> &e);
    void clear();
    T* at(int index) const;

protected:
    virtual void setColumns() = 0;

    QList<T*> entities;
    QMap<QString, QString> columns;
};

template<typename T>
AbstractRowModel<T>::AbstractRowModel(const QList<T*> &entities, QObject *parent)  : QAbstractTableModel(parent), entities(entities)
{
    this->setColumns();
}

template<typename T>
void AbstractRowModel<T>::add(T* e) {
    int n = this->entities.size();
    this->entities.append(e);
    this->insertRow(n);
}

template<typename T>
void AbstractRowModel<T>::add(const QList<T*> &e) {
    int n = this->entities.size();
    this->entities.append(e);
    this->insertRows(n, e.size());
}

template<typename T>
bool AbstractRowModel<T>::insertRows(int position, int rows, const QModelIndex &index) {
    beginInsertRows(QModelIndex(), position, position + rows - 1);

    for (int row = 0; row < rows; row++) {
        if ((position + row) > this->entities.size())
            this->entities.insert(position, new T());
    }

    endInsertRows();

    return true;
}

template<typename T>
T* AbstractRowModel<T>::at(int index) const {
    return this->entities.at(index);
}

template<typename T>
AbstractRowModel<T>::AbstractRowModel(QObject *parent)  : QAbstractTableModel(parent)
{
    this->setColumns();
}

template<typename T>
AbstractRowModel<T>::~AbstractRowModel() {
}

template<typename T>
void AbstractRowModel<T>::clear() {
    int n = this->entities.size();
    this->entities.clear();
    this->removeRows(0, n);
}

template<typename T>
int AbstractRowModel<T>::columnCount(const QModelIndex &parent) const {
    return this->columns.size();
}

template<typename T>
int AbstractRowModel<T>::rowCount(const QModelIndex &parent) const {
    return this->entities.size();
}

template<typename T>
QVariant AbstractRowModel<T>::data(const QModelIndex &index, int role) const {
    if (index.isValid() && index.row() < this->entities.size() && role == Qt::DisplayRole) {
        QString key = this->columns.keys().at(index.column());
        BaseEntity* e = (BaseEntity*) this->entities.at(index.row());

        return e->get(key);
    } else {
        return QVariant();
    }
}

template<typename T>
QVariant AbstractRowModel<T>::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal)
        return this->columns.values()[section];
    else
        return QString::number(section + 1);
}

template<typename T>
Qt::ItemFlags AbstractRowModel<T>::flags(const QModelIndex &index) const {
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

template<typename T>
bool AbstractRowModel<T>::removeRows(int position, int rows, const QModelIndex &index) {
    beginRemoveRows(QModelIndex(), position, position + rows - 1);

    for (int row = 0; row < rows; row++) {
        if (position < this->entities.size())
            this->entities.removeAt(position);
    }

    endRemoveRows();

    return true;
}

#endif // ABSTRACTROWMODEL_H
