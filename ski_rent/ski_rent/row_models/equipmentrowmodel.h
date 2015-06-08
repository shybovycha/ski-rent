#ifndef EQUIPMENTROWMODEL_H
#define EQUIPMENTROWMODEL_H

#include "entities/equipment.h"
#include "row_models/abstractrowmodel.h"

template<>
void AbstractRowModel<Equipment>::setColumns() {
    columns.clear();
    registerColumn("amount", tr("Amount"));
    registerColumn("type", tr("Type"));
    registerColumn("condition", tr("Condition"));
}

template<>
QVariant AbstractRowModel<Equipment>::data(const QModelIndex &index, int role) const {
    if (index.isValid() && index.row() < this->entities.size() && role == Qt::DisplayRole) {
        QString key = this->columns.at(index.column()).first;
        Equipment* e = this->entities.at(index.row());

        if (key == "condition") {
            return QString("%1").arg((char) e->getCondition());
        }

        return e->get(key);
    } else {
        return QVariant();
    }
}

#endif // EQUIPMENTROWMODEL_H
