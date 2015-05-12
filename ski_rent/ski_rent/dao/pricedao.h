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
#include "util/singleton.h"

class PriceDAO
{
public:
    PriceDAO();
    ~PriceDAO();

    void create(Price* newEntity);
    void update(QString type, char condition, int time, Price* newEntity);
    void remove(QString type, char condition, int time);
    QList<Price*> all();
    QList<Price*> find(QString query);
    QList<Price*> find(QString type, char condition, int time);

protected:
    PriceQueryBuilder* queryBuilder;

    DatabaseAdapter* getDb();
};

typedef Singleton<PriceDAO> PriceDAOSingleton;

#endif // PRICESDAO_H

