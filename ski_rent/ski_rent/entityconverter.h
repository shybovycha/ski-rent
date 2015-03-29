#ifndef ENTITYCONVERTER_H
#define ENTITYCONVERTER_H

#include <QList>
#include <dbrow.h>

class EntityConverter
{
public:
    template<typename T> static T convert(DBRow row);
    template<typename T> static QList<T> convert(QList<DBRow> rows);

protected:
    EntityConverter();
    ~EntityConverter();
};

#endif // ENTITYCONVERTER_H
