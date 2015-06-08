#include "entity_converters/entityconverter.h"
#include "entities/history.h"

template<>
History* EntityConverter<History>::convert(DBRow row) {
    History* result = new History();

    result->setId(row["id"].toInt());
    result->setName(row["name"].toString());
    result->setSurname(row["surname"].toString());
    result->setDocumentType(row["document_type"].toString());
    result->setDocumentNumber(row["document_number"].toString());
    result->setCountry(row["country"].toString());
    result->setCity(row["city"].toString());
    result->setAddress(row["address"].toString());
    result->setPhone(row["phone"].toString());
    result->setType(row["type"].toString());
    result->setAmount(row["amount"].toInt());
    result->setCondition(row["condition"].toString().at(0).unicode());
    result->setRentFrom(row["rent_from"].toDateTime());
    result->setRentTo(row["rent_to"].toDateTime());
    result->setPrice(row["price"].toFloat());

    return result;
}
