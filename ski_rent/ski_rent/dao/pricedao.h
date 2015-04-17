#ifndef PRICESDAO_H
#define PRICESDAO_H

#include <QList>
#include <QString>
#include <QDateTime>

#include "entities/price.h"
#include "dao/basedao.h"
#include "db/databaseadapter.h"
#include "db/databaseconnector.h"
#include "entity_converters/entityconverter.h"
#include "query_builders/querybuilder.h"
#include "query_builders/pricequerybuilder.h"

class PriceDAO
{
public:
    static PriceDAO* getSingletonPtr();

    void create(Price newEntity);
    void update(QString type, char condition, int time, Price newEntity);
    void remove(QString type, char condition, int time);
    QList<Price> find(QString type, char condition, int time);

protected:
    PriceDAO();
    ~PriceDAO();

    PriceQueryBuilder* queryBuilder;

    DatabaseAdapter* getDb();
};

#endif // PRICESDAO_H

