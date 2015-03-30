#include "entityconverter.h"
#include "user.h"

template<>
User EntityConverter<User>::convert(DBRow row) {
    User result;

    result.setId(row["id"].toInt());
    result.setName(row["name"].toString());
    result.setSurname(row["surname"].toString());
    result.setDocumentType(row["document_type"].toString());
    result.setDocumentNumber(row["document_number"].toString());
    result.setCountry(row["country"].toString());
    result.setCity(row["city"].toString());
    result.setAddress(row["address"].toString());
    result.setPhone(row["phone"].toString());

    return result;
}

template<>
QList<User> EntityConverter<User>::convert(QList<DBRow> rows) {
    QList<User> res;

    for (int i = 0; i < rows.size(); i++) {
        res.append(convert(rows[i]));
    }

    return res;
}
