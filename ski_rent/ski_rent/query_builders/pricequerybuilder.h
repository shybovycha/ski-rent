#ifndef PRICEQUERYBUILDER_H
#define PRICEQUERYBUILDER_H

#include "entities/price.h"

#include <QString>

class PriceQueryBuilder
{
public:
    PriceQueryBuilder();
    ~PriceQueryBuilder();

    QString getListAllQuery();
    QString getCreateQuery(Price* newEntity);
    QString getSearchQuery(QString query);
    QString getFindQuery(QString type, char condition, int time);
    QString getRemoveQuery(QString type, char condition, int time);
    QString getUpdateQuery(QString type, char condition, int time, Price* newEntity);

protected:
    QString tableName;
};

#endif // PRICEQUERYBUILDER_H

