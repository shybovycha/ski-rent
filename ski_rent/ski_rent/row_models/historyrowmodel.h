#ifndef HISTORYROWMODEL_H
#define HISTORYROWMODEL_H

#include "entities/history.h"
#include "row_models/abstractrowmodel.h"

template<>
void AbstractRowModel<History>::setColumns() {
    columns.clear();
    registerColumn("name", tr("Name"));
    registerColumn("surname", tr("Surname"));
    registerColumn("document_type", tr("Document type"));
    registerColumn("document_number", tr("Document number"));
    registerColumn("country", tr("Country"));
    registerColumn("city", tr("City"));
    registerColumn("address", tr("Address"));
    registerColumn("phone", tr("Phone"));
    registerColumn("type", tr("Type"));
    registerColumn("amount", tr("Amount"));
    registerColumn("condition", tr("Condition"));
    registerColumn("rent_from", tr("Rented from"));
    registerColumn("rent_to", tr("Rented to"));
    registerColumn("price", tr("Price"));
}

template<>
QVariant AbstractRowModel<History>::data(const QModelIndex &index, int role) const {
    if (index.isValid() && index.row() < this->entities.size() && role == Qt::DisplayRole) {
        QString key = this->columns.at(index.column()).first;
        History* e = this->entities.at(index.row());

        if (key == "condition") {
            return QString("").sprintf("%c", e->getCondition());
        }

        if (key == "rent_from") {
            return e->getRentFrom().toString("yyyy-MM-dd hh:mm");
        }

        if (key == "rent_to") {
            return e->getRentTo().toString("yyyy-MM-dd hh:mm");
        }

        if (key == "price") {
            return QString("").sprintf("%0.2f", e->getPrice());
        }

        return e->get(key);
    } else {
        return QVariant();
    }
}

#endif // HISTORYROWMODEL_H
