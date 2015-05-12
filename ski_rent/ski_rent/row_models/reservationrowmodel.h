#ifndef RESERVATIONROWMODEL_H
#define RESERVATIONROWMODEL_H

#include <QAbstractTableModel>

#include "entities/reservation.h"
#include "dao/userdao.h"
#include "dao/equipmentdao.h"

class ReservationRowModel : public QAbstractTableModel
{
public:
    ReservationRowModel(QObject *parent = 0);
    ReservationRowModel(const QList<Reservation*> &entities, QObject *parent = 0);
    ~ReservationRowModel();

    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;

    virtual QVariant data(const QModelIndex &index, int role) const;
    virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

    Qt::ItemFlags flags(const QModelIndex &index) const;

    bool insertRows(int position, int rows, const QModelIndex &index = QModelIndex());
    bool removeRows(int position, int rows, const QModelIndex &index = QModelIndex());

    void add(Reservation* e);
    void add(const QList<Reservation*> &e);
    void clear();
    Reservation* at(int index) const;

protected:
    virtual void setColumns();

    QList<Reservation*> entities;
    QMap<QString, QString> columns;
};

#endif // RESERVATIONROWMODEL_H
