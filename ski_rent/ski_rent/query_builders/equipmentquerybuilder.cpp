#include "query_builders/querybuilder.h"
#include "entities/equipment.h"

#include <QString>
#include <QStringList>

template<>
QueryBuilder<Equipment>::QueryBuilder()
{
    this->tableName = "equipment";

    this->searchColumns.append("type");
    this->searchColumns.append("amount");
    this->searchColumns.append("condition");

    this->updateColumns.append("type");
    this->updateColumns.append("amount");
    this->updateColumns.append("condition");
}

template<>
QString QueryBuilder<Equipment>::getSearchQuery(QString query) {
    QString likeCondition = QString("'%%1%'").arg(QString(query).split("\\s+").join("%"));
    QStringList likes;

    for (int i = 0; i < this->searchColumns.size(); i++) {
        likes.append(QString("`%1` LIKE %2").arg(this->searchColumns[i]).arg(likeCondition));
    }

    QString sql = QString("SELECT * FROM `available_equipment` WHERE %1").arg(likes.join(" OR "));

    return sql;
}

template<>
QString QueryBuilder<Equipment>::getListAllQuery() {
    return QString("SELECT * FROM `available_equipment`");
}
