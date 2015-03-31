#include "querybuilder.h"
#include "equipment.h"

#include <QString>
#include <QStringList>

template<>
QueryBuilder<Equipment>::QueryBuilder()
{
    this->tableName = "available_equipment";

    this->searchColumns.append("type");
    this->searchColumns.append("amount");
    this->searchColumns.append("condition");
}
