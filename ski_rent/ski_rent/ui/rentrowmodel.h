#ifndef RENTROWMODEL_H
#define RENTROWMODEL_H

#include "dao/userdao.h"
#include "dao/equipmentdao.h"

#include "entities/rent.h"
#include "ui/abstractrowmodel.h"

template<>
void AbstractRowModel<Rent>::setColumns() {
    columns.clear();
    columns["user"] = tr("User");
    columns["equipment"] = tr("Equipment");
    columns["amount"] = tr("Amount");
    columns["rent_from"] = tr("Rent from");
}

template<>
QVariant AbstractRowModel<Rent>::data(const QModelIndex &index, int role) const {
    if (index.isValid() && index.row() < this->entities.size() && role == Qt::DisplayRole) {
        QString key = this->columns.keys().at(index.column());
        Rent* e = this->entities.at(index.row());

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

#endif // RENTROWMODEL_H
