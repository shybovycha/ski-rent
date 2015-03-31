#include "querybuilder.h"
#include "rent.h"

#include <QString>
#include <QStringList>

template<>
QueryBuilder<Rent>::QueryBuilder()
{
    this->tableName = "rent";

    this->updateColumns.append("user_id");
    this->updateColumns.append("equipment_id");
    this->updateColumns.append("amount");
    this->updateColumns.append("rent_from");

    this->searchColumns.append("amount");
    this->searchColumns.append("rent_from");
}

