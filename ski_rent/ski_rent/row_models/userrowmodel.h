#ifndef USERROWMODEL_H
#define USERROWMODEL_H

#include "entities/user.h"
#include "row_models/abstractrowmodel.h"

template<>
void AbstractRowModel<User>::setColumns() {
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

#endif // USERROWMODEL_H
