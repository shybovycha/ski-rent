#ifndef ENTITYCONVERTER_H
#define ENTITYCONVERTER_H

#include "db/dbrow.h"

#include <QList>

template<typename T>
class EntityConverter
{
public:
    static T convert(DBRow row);
    static QList<T> convert(QList<DBRow> rows);
};

/*template<typename T>
T EntityConverter<T>::convert(DBRow row) {
    T res;

    for (int i = 0; i < rows.size(); i++) {
        res.append(convert(rows[i]));
    }

    return res;
}*/

template<typename T>
QList<T> EntityConverter<T>::convert(QList<DBRow> rows) {
    QList<T> res;

    for (int i = 0; i < rows.size(); i++) {
        res.append(convert(rows[i]));
    }

    return res;
}

#endif // ENTITYCONVERTER_H
