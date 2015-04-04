#include "query_builders/pricequerybuilder.h"
#include "entities/price.h"

#include <QString>
#include <QStringList>

PriceQueryBuilder::PriceQueryBuilder() {
    this->tableName = "prices";
}

PriceQueryBuilder::~PriceQueryBuilder() {
}

QString PriceQueryBuilder::getListAllQuery() {
    return QString("SELECT * FROM %1").arg(this->tableName);
}

QString PriceQueryBuilder::getCreateQuery(Price newEntity) {
    QStringList columns, values;

    columns.append("`type`");
    columns.append("`condition`");
    columns.append("`time`");
    columns.append("`price`");

    values.append(QString("'%1'").arg(newEntity.getType()));
    values.append(QString("'%1'").arg(newEntity.getCondition()));
    values.append(QString("'%1'").arg(newEntity.getTime()));
    values.append(QString("'%1'").arg(newEntity.getPrice()));

    return QString("INSERT INTO `%1` (%2) VALUES (%3)")
        .arg(this->tableName)
        .arg(columns.join(", "))
        .arg(values.join(", "));
}

QString PriceQueryBuilder::getFindQuery(QString type, char condition, int time) {
    return QString("SELECT * FROM `%1` WHERE `type` = '%2' AND `condition` = '%3' AND `time` = '%4'")
        .arg(this->tableName)
        .arg(type)
        .arg(condition)
        .arg(time);
}

QString PriceQueryBuilder::getRemoveQuery(QString type, char condition, int time) {
    return QString("DELETE FROM %1 WHERE `type` = '%2' AND `condition` = '%3' AND `time` = '%4'")
        .arg(this->tableName)
        .arg(type)
        .arg(condition)
        .arg(time);
}

QString PriceQueryBuilder::getUpdateQuery(QString type, char condition, int time, Price newEntity) {
    QStringList values, conditions;

    values.append(QString("`type` = '%1'").arg(newEntity.getType()));
    values.append(QString("`condition` = '%1'").arg(newEntity.getCondition()));
    values.append(QString("`time` = '%1'").arg(newEntity.getTime()));
    values.append(QString("`price` = '%1'").arg(newEntity.getPrice()));

    conditions.append(QString("`type` = '%1'").arg(type));
    conditions.append(QString("`condition` = '%1'").arg(condition));
    conditions.append(QString("`time` = '%1'").arg(time));

    return QString("UPDATE `%1` SET %2 WHERE %3")
        .arg(this->tableName)
        .arg(values.join(", "))
        .arg(conditions.join(" AND "));
}
