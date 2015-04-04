#include "entity_converters/entityconverter.h"
#include "entities/reservation.h"

template<>
Reservation EntityConverter<Reservation>::convert(DBRow row) {
    Reservation result;

    result.setUserId(row["user_id"].toInt());
    result.setEquipmentId(row["equipment_id"].toInt());
    result.setAmount(row["amount"].toInt());
    result.setRentFrom(row["rent_from"].toDateTime());
    result.setRentTo(row["rent_to"].toDateTime());

    return result;
}
