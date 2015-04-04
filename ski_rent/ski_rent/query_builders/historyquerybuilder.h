#ifndef HISTORYQUERYBUILDER_H
#define HISTORYQUERYBUILDER_H

#include "entities/history.h"

#include <QString>

class HistoryQueryBuilder
{
public:
    HistoryQueryBuilder();
    ~HistoryQueryBuilder();

    QString getListAllQuery();
    QString getCreateQuery(History newEntity);
    QString getFindQuery(int id);

protected:
    QString tableName;
};

#endif // HISTORYQUERYBUILDER_H
