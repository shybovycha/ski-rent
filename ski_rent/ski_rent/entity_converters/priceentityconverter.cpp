#include "entity_converters/entityconverter.h"
#include "entities/price.h"

template<>
Price EntityConverter<Price>::convert(DBRow row) {
    Price result;

    result.setType(row["type"].toString());
    result.setCondition(row["condition"].toChar().unicode());
    result.setTime(row["time"].toInt());
    result.setPrice(row["price"].toFloat());

    return result;
}