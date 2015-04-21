#include "entities/equipment.h"
#include "entity_converters/entityconverter.h"

template<>
Equipment* EntityConverter<Equipment>::convert(DBRow row) {
    Equipment* result = new Equipment();

    result->setId(row["id"].toInt());
    result->setType(row["type"].toString());
    result->setAmount(row["amount"].toInt());

    char conditionKey = row["condition"].toString().at(0).unicode();
    result->setCondition(conditionKey);

    return result;
}

