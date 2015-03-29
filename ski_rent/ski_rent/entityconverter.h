#ifndef ENTITYCONVERTER_H
#define ENTITYCONVERTER_H

#include <QList>
#include <dbrow.h>

class EntityConverter
{
public:
    EntityConverter();
    ~EntityConverter();

    template<typename T> static T convert(DBRow row);
    template<typename T> static QList<T> convert(QList<DBRow> rows);
};

#endif // ENTITYCONVERTER_H
