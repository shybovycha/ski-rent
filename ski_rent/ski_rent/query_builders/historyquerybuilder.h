#ifndef HISTORYQUERYBUILDER_H
#define HISTORYQUERYBUILDER_H

#include "entities/history.h"
#include "entities/user.h"
#include "entities/equipment.h"
#include "entities/rent.h"
#include "entities/price.h"

#include <QString>
#include <QDateTime>

class HistoryQueryBuilder
{
public:
    HistoryQueryBuilder();
    ~HistoryQueryBuilder();

    QString getListAllQuery();
    QString getCreateQuery(History* newEntity);
    QString getCreateQuery(User*, Equipment*, Rent*, QDateTime rentTo, Price*);
    QString getFindQuery(int id);
    QString getSearchQuery(QString query);

protected:
    QString tableName;
};

#endif // HISTORYQUERYBUILDER_H
