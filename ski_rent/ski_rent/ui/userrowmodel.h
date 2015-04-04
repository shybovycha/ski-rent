#ifndef USERROWMODEL_H
#define USERROWMODEL_H

#include "entities/user.h"

#include <QObject>
#include <QVariant>
#include <QList>
#include <QAbstractTableModel>

class UserRowModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    UserRowModel(QObject *parent = 0);
    UserRowModel(const QList<User> &users, QObject *parent = 0);
    ~UserRowModel();

    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &parent, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

    bool insertRows(int position, int rows, const QModelIndex &index = QModelIndex());
    bool removeRows(int position, int rows, const QModelIndex &index = QModelIndex());

    void add(const User &u);
    void add(const QList<User> &u);
    void clear();

private:
    void setColumns();

    QList<User> users;
    QMap<QString, QString> columns;
};

#endif // USERROWMODEL_H
