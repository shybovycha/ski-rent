#include "entity_converters/entityconverter.h"
#include "entities/price.h"

template<>
Price* EntityConverter<Price>::convert(DBRow row) {
    Price* result = new Price();

    result->setType(row["type"].toString());
    result->setCondition(row["condition"].toString().at(0).unicode());
    result->setTime(row["time"].toInt());
    result->setPrice(row["price"].toFloat());

    return result;
}
