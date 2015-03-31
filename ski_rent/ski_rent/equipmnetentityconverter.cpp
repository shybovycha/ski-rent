#include "entityconverter.h"
#include "equipment.h"

template<>
Equipment EntityConverter<Equipment>::convert(DBRow row) {
    Equipment result;

    result.setId(row["id"].toInt());
    result.setType(row["type"].toString());
    result.setAmount(row["amount"].toInt());

    return result;
}

