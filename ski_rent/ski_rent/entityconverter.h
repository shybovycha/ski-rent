#ifndef ENTITYCONVERTER_H
#define ENTITYCONVERTER_H

#include <QList>
#include <dbrow.h>

template<typename T>
class EntityConverter
{
public:
    static T convert(DBRow row);
    static QList<T> convert(QList<DBRow> rows);
};

#endif // ENTITYCONVERTER_H
