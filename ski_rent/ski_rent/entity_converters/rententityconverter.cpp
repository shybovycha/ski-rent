#include "entity_converters/entityconverter.h"
#include "entities/rent.h"

template<>
Rent EntityConverter<Rent>::convert(DBRow row) {
    Rent result;

    result.setId(row["id"].toInt());
    result.setUserId(row["user_id"].toInt());
    result.setEquipmentId(row["equipment_id"].toInt());
    result.setAmount(row["amount"].toInt());
    result.setRentFrom(row["rent_from"].toDateTime());

    return result;
}
