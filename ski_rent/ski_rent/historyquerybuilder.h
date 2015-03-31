#ifndef HISTORYQUERYBUILDER_H
#define HISTORYQUERYBUILDER_H

#include <QString>

#include "history.h"

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
