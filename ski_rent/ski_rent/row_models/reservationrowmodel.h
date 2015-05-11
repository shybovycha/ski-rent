#ifndef RESERVATIONROWMODEL_H
#define RESERVATIONROWMODEL_H

#include "row_models/abstractrowmodel.h"
#include "entities/reservation.h"
#include "dao/userdao.h"
#include "dao/equipmentdao.h"

template<>
void AbstractRowModel<Reservation>::setColumns() {
    columns.clear();
    columns["user"] = tr("User");
    columns["equipment"] = tr("Equipment");
    columns["amount"] = tr("Amount");
    columns["rent_from"] = tr("Rent from");
    columns["rent_to"] = tr("Rent to");
}

template<>
QVariant AbstractRowModel<Reservation>::data(const QModelIndex &index, int role) const {
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

#endif // RESERVATIONROWMODEL_H
