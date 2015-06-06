#ifndef EQUIPMENTQUERYBUILDER_H
#define EQUIPMENTQUERYBUILDER_H

#include "entities/equipment.h"
#include "entities/price.h"

#include <QString>
#include <QDateTime>

class EquipmentQueryBuilder
{
public:
    EquipmentQueryBuilder();
    ~EquipmentQueryBuilder();

    QString getCreateQuery(Equipment* entity);
    QString getReadQuery(int id);
    QString getUpdateQuery(Equipment* newEntity);
    QString getDeleteQuery(int id);
    QString getSearchQuery(QString query);
    QString getListAllQuery();
    QString getListUsableQuery();

protected:
    QString tableName;
    QStringList searchColumns;
    QStringList updateColumns;
};

#endif // EQUIPMENTQUERYBUILDER_H
