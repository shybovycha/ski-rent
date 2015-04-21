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

    QString getCreateQuery(int userId, int equipmentId, Rent* newEntity);
    QString getUpdateQuery(int userId, int equipmentId, Rent* newEntity);
    QString getRemoveQuery(int userId, int equipmentId);
    QString getFindByUserIdQuery(int userId);
    QString getFindByEquipmentIdQuery(int equipmentId);
    QString getFindByRentFrom(QDateTime rentFrom);
    QString getFindByRentFrom(QDateTime rentFrom, QDateTime rentTo);

protected:
    QString tableName;
};

#endif // RENTQUERYBUILDER_H
