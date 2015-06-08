#ifndef USERROWMODEL_H
#define USERROWMODEL_H

#include "entities/user.h"
#include "row_models/abstractrowmodel.h"

template<>
void AbstractRowModel<User>::setColumns() {
    columns.clear();

    registerColumn("name", tr("Name"));
    registerColumn("surname", tr("Surname"));
    registerColumn("document_type", tr("Document type"));
    registerColumn("document_number", tr("Document number"));
    registerColumn("country", tr("Country"));
    registerColumn("city", tr("City"));
    registerColumn("address", tr("Address"));
    registerColumn("phone", tr("Phone"));
}

#endif // USERROWMODEL_H
