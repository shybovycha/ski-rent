#ifndef HISTORYDAO_H
#define HISTORYDAO_H

#include <QList>

#include "entities/history.h"
#include "db/databaseadapter.h"
#include "db/databaseconnector.h"
#include "query_builders/historyquerybuilder.h"
#include "entity_converters/entityconverter.h"
#include "util/singleton.h"

class HistoryDAO
{
public:
    HistoryDAO();
    ~HistoryDAO();

    QList<History> all();
    History find(int id);
    void create(History newEntity);

protected:
    HistoryQueryBuilder* queryBuilder;

    DatabaseAdapter* getDb();
};

typedef Singleton<HistoryDAO> HistoryDAOSingleton;

#endif // HISTORYDAO_H
