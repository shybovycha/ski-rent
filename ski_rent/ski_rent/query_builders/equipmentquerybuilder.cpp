#include "query_builders/querybuilder.h"
#include "entities/equipment.h"

#include <QString>
#include <QStringList>

template<>
QueryBuilder<Equipment>::QueryBuilder() {
    this->tableName = "equipment";

    this->updateColumns.append("type");
    this->updateColumns.append("amount");
    this->updateColumns.append("condition");

    this->searchColumns.append("type");
}

template<>
QString QueryBuilder<Equipment>::getSearchQuery(QString query) {
    QString likeCondition = QString("'%%1%'").arg(QString(query).split("\\s+").join("%"));
    QString sql = QString("CALL quickSearchEquipment(%1, @err)").arg(likeCondition);

    return sql;
}

template<>
QString QueryBuilder<Equipment>::getListAllQuery() {
    return QString("SELECT * FROM `available_equipment`");
}
