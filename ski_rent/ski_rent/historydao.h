#ifndef HISTORYDAO_H
#define HISTORYDAO_H

#include <QList>

#include "history.h"
#include "databaseadapter.h"
#include "databaseconnector.h"
#include "historyquerybuilder.h"
#include "entityconverter.h"

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

#endif // HISTORYDAO_H
