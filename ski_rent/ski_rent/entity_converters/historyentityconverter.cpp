#include "entity_converters/entityconverter.h"
#include "entities/history.h"

template<>
History EntityConverter<History>::convert(DBRow row) {
    History result;

    result.setId(row["id"].toInt());
    result.setName(row["name"].toString());
    result.setSurname(row["surname"].toString());
    result.setDocumentType(row["document_type"].toString());
    result.setDocumentNumber(row["document_number"].toString());
    result.setCountry(row["country"].toString());
    result.setCity(row["city"].toString());
    result.setAddress(row["address"].toString());
    result.setPhone(row["phone"].toString());
    result.setType(row["type"].toString());
    result.setAmount(row["amount"].toInt());
    result.setCondition(row["condition"].toChar().unicode());
    result.setRentFrom(row["rentFrom"].toDateTime());
    result.setRentTo(row["rentTo"].toDateTime());
    result.setPrice(row["price"].toFloat());

    return result;
}
