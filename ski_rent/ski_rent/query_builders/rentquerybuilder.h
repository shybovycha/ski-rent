#ifndef RENTQUERYBUILDER_H
#define RENTQUERYBUILDER_H

#include "entities/rent.h"
#include "query_builders/querybuilder.h"

#include <QList>
#include <QString>
#include <QDateTime>

class RentQueryBuilder
{
public:
    RentQueryBuilder();
    ~RentQueryBuilder();

    QString getSelectAllQuery();
    QString getSearchQuery(QString query);
    QString getCreateQuery(Rent* newEntity);
    QString getUpdateQuery(Rent* oldEntity, Rent* newEntity);
    QString getRemoveQuery(Rent* oldEntity);
    QString getFindByUserIdQuery(int userId);
    QString getFindByEquipmentIdQuery(int equipmentId);
    QString getFindByRentFrom(QDateTime rentFrom);
    QString getFindByRentFrom(QDateTime rentFrom, QDateTime rentTo);

protected:
    QString tableName;
};

#endif // RENTQUERYBUILDER_H
