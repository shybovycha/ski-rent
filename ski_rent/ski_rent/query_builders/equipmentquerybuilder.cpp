#include "query_builders/equipmentquerybuilder.h"
#include "entities/equipment.h"

#include <QString>
#include <QStringList>

EquipmentQueryBuilder::EquipmentQueryBuilder() {
    this->tableName = "equipment";

    this->updateColumns.append("type");
    this->updateColumns.append("amount");
    this->updateColumns.append("condition");

    this->searchColumns.append("type");
}

EquipmentQueryBuilder::~EquipmentQueryBuilder() {
}

QString EquipmentQueryBuilder::getSearchQuery(QString query) {
    QString likeCondition = QString("'%%1%'").arg(QString(query).split("\\s+").join("%"));
    QString sql = QString("CALL quickSearchEquipment(%1, @err)").arg(likeCondition);

    return sql;
}

QString EquipmentQueryBuilder::getListAllQuery() {
    return QString("SELECT * FROM `available_equipment`");
}

QString EquipmentQueryBuilder::getCreateQuery(Equipment* newEntity) {
    if (this->updateColumns.size() < 1) {
        throw QString("Can not generate create query - no updateColumns set").toStdString().c_str();
    }

    QStringList columnList;
    QStringList valueList;

    for (int i = 0; i < this->updateColumns.size(); i++) {
        columnList.append(QString("`%1`").arg(this->updateColumns[i]));
        valueList.append(QString("'%1'").arg(newEntity->get(this->updateColumns[i]).toString()));
    }

    QString res =
            QString("INSERT INTO `%1` (%2) VALUES (%3)")
            .arg(this->tableName)
            .arg(columnList.join(", "))
            .arg(valueList.join(", "));

    return res;
}

QString EquipmentQueryBuilder::getReadQuery(int id) {
    QString res = QString("SELECT * FROM `%1` WHERE id = %2").arg(this->tableName).arg(id);

    return res;
}

QString EquipmentQueryBuilder::getUpdateQuery(Equipment* newEntity) {
    if (this->updateColumns.size() < 1) {
        throw QString("Can not generate update query - no updateColumns set").toStdString().c_str();
    }

    QStringList updates;

    for (int i = 0; i < this->updateColumns.size(); i++) {
        updates.append(QString("`%1` = '%2'")
                       .arg(this->updateColumns[i])
                       .arg(newEntity->get(this->updateColumns[i]).toString()));
    }

    QString res =
            QString("UPDATE `%1` SET %2 WHERE id = %3")
            .arg(this->tableName)
            .arg(updates.join(", "))
            .arg(newEntity->getId());

    return res;
}

QString EquipmentQueryBuilder::getDeleteQuery(int id) {
    QString res = QString("DELETE FROM `%1` WHERE id = %2").arg(this->tableName).arg(id);

    return res;
}

QString EquipmentQueryBuilder::getListUsableQuery() {
    return QString("SELECT * FROM `usable_equipment`;");
}
