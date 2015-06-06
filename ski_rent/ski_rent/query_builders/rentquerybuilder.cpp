#include "query_builders/rentquerybuilder.h"

RentQueryBuilder::RentQueryBuilder()
{
    this->tableName = "rent";
}

RentQueryBuilder::~RentQueryBuilder() {
}

QString RentQueryBuilder::getSelectAllQuery() {
    return QString("SELECT * FROM %1").arg(this->tableName);
}

QString RentQueryBuilder::getSearchQuery(QString query) {
    QString likeCondition = QString("'%%1%'").arg(QString(query).split("\\s+").join("%"));
    QStringList likes;
    QStringList searchColumns;

    searchColumns.append("B.name");
    searchColumns.append("B.surname");
    searchColumns.append("B.document_number");
    searchColumns.append("B.country");
    searchColumns.append("B.city");
    searchColumns.append("B.address");
    searchColumns.append("B.phone");
    searchColumns.append("C.type");

    if (query.isEmpty()) {
        likes.append("TRUE");
    } else {
        for (int i = 0; i < searchColumns.size(); i++) {
            likes.append(QString("`%1` LIKE %2").arg(searchColumns[i]).arg(likeCondition));
        }
    }

    return QString("SELECT * FROM `rent` AS A JOIN `users` AS B ON A.user_id = B.id JOIN `equipment` AS C ON A.equipment_id = C.id WHERE %1").arg(likes.join(" OR "));
}

QString RentQueryBuilder::getCreateQuery(Rent* newEntity) {
    QStringList columns;
    QStringList values;

    columns.append("user_id");
    columns.append("equipment_id");
    columns.append("amount");
    columns.append("rent_from");

    values.append(QString::number(newEntity->getUserId()));
    values.append(QString::number(newEntity->getEquipmentId()));
    values.append(QString::number(newEntity->getAmount()));
    values.append(newEntity->getRentFrom().toString("yyyy-MM-dd hh:mm"));

    for (int i = 0; i < columns.size(); i++) {
        columns[i] = QString("`%1`").arg(columns[i]);
    }

    for (int i = 0; i < values.size(); i++) {
        values[i] = QString("'%1'").arg(values[i]);
    }

    return QString("INSERT INTO %1 (%2) VALUES (%3)").arg(this->tableName).arg(columns.join(", ")).arg(values.join(", "));
}

QString RentQueryBuilder::getUpdateQuery(int userId, int equipmentId, Rent* newEntity) {
    QStringList values;

    values.append(QString("`amount` = '%1'").arg(newEntity->getAmount()));
    values.append(QString("`rent_from` = '%1'").arg(newEntity->getRentFrom().toString("yyyy-MM-dd hh:mm")));

    return QString("UPDATE %1 SET %2 WHERE `user_id` = %3 AND `equipment_id` = %4").arg(this->tableName).arg(values.join(", ")).arg(userId).arg(equipmentId);
}

QString RentQueryBuilder::getRemoveQuery(int userId, int equipmentId) {
    return QString("DELETE FROM %1 WHERE `user_id` = %2 AND `equipment_id` = %3").arg(this->tableName).arg(userId).arg(equipmentId);
}

QString RentQueryBuilder::getFindByUserIdQuery(int userId) {
    return QString("SELECT * FROM %1 WHERE user_id = %2").arg(this->tableName).arg(userId);
}

QString RentQueryBuilder::getFindByEquipmentIdQuery(int equipmentId) {
    return QString("SELECT * FROM %1 WHERE equipment_id = %2").arg(this->tableName).arg(equipmentId);
}

QString RentQueryBuilder::getFindByRentFrom(QDateTime rentFrom) {
    return QString("SELECT * FROM %1 WHERE rent_from = '%2'").arg(this->tableName).arg(rentFrom.toString("yyyy-MM-dd hh:mm"));
}

QString RentQueryBuilder::getFindByRentFrom(QDateTime rentFrom, QDateTime rentTo) {
    return QString("SELECT * FROM %1 WHERE rent_from BETWEEN '%2' AND '%3'").arg(this->tableName).arg(rentFrom.toString("yyyy-MM-dd hh:mm")).arg(rentTo.toString("yyyy-MM-dd hh:mm"));
}
