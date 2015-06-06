#include "query_builders/reservationquerybuilder.h"

ReservationQueryBuilder::ReservationQueryBuilder() {
    this->tableName = "reservations";
}

ReservationQueryBuilder::~ReservationQueryBuilder() {
}

QString ReservationQueryBuilder::getListAllQuery() {
    return QString("SELECT * FROM %1").arg(this->tableName);
}

QString ReservationQueryBuilder::getToRentQuery(Reservation* oldEntity) {
    QStringList columns;
    QStringList values;

    columns.append("user_id");
    columns.append("equipment_id");
    columns.append("amount");
    columns.append("rent_from");
    // columns.append("rent_to");

    values.append(QString::number(oldEntity->getUserId()));
    values.append(QString::number(oldEntity->getEquipmentId()));
    values.append(QString::number(oldEntity->getAmount()));
    values.append(oldEntity->getRentFrom().toString("yyyy-MM-dd hh:mm"));
    // values.append(newEntity->getRentTo().toString("yyyy-MM-dd hh:mm"));

    for (int i = 0; i < columns.size(); i++) {
        columns[i] = QString("`%1`").arg(columns[i]);
        values[i] = QString("'%1'").arg(values[i]);
    }

    QString res = QString("INSERT INTO `rent` (%1) VALUES (%2);")
            .arg(columns.join(", "))
            .arg(values.join(", "));

    return res;
}

QString ReservationQueryBuilder::getCreateQuery(Reservation* newEntity) {
    QStringList columns;
    QStringList values;

    columns.append("user_id");
    columns.append("equipment_id");
    columns.append("amount");
    columns.append("rent_from");
    columns.append("rent_to");

    values.append(QString::number(newEntity->getUserId()));
    values.append(QString::number(newEntity->getEquipmentId()));
    values.append(QString::number(newEntity->getAmount()));
    values.append(newEntity->getRentFrom().toString("yyyy-MM-dd hh:mm"));
    values.append(newEntity->getRentTo().toString("yyyy-MM-dd hh:mm"));

    for (int i = 0; i < columns.size(); i++) {
        columns[i] = QString("`%1`").arg(columns[i]);
        values[i] = QString("'%1'").arg(values[i]);
    }

    QString res = QString("INSERT INTO %1 (%2) VALUES (%3);")
            .arg(this->tableName)
            .arg(columns.join(", "))
            .arg(values.join(", "));

    return res;
}

QString ReservationQueryBuilder::getUpdateQuery(Reservation* oldEntity, Reservation* newEntity) {
    QStringList values;

    values.append(QString("`amount` = %1").arg(newEntity->getAmount()));
    values.append(QString("`rent_from` = '%1'").arg(newEntity->getRentFrom().toString("yyyy-MM-dd hh:mm")));
    values.append(QString("`rent_to` = '%1'").arg(newEntity->getRentTo().toString("yyyy-MM-dd hh:mm")));

    QString res = QString("UPDATE %1 SET %2 WHERE `user_id` = %3 AND `equipment_id` = %4 AND `rent_from` = '%5'")
            .arg(this->tableName)
            .arg(values.join(", "))
            .arg(oldEntity->getUserId())
            .arg(oldEntity->getEquipmentId())
            .arg(oldEntity->getRentFrom().toString("yyyy-MM-dd hh:mm"));

    return res;
}

QString ReservationQueryBuilder::getRemoveQuery(Reservation* oldEntity) {
    return QString("DELETE FROM %1 WHERE user_id = %2 AND equipment_id = %3 AND rent_from = '%4'")
            .arg(this->tableName)
            .arg(oldEntity->getUserId())
            .arg(oldEntity->getEquipmentId())
            .arg(oldEntity->getRentFrom().toString("yyyy-MM-dd hh:mm"));
}

QString ReservationQueryBuilder::getSearchQuery(QString query) {
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

    return QString("SELECT A.amount as amount, A.user_id as user_id, A.equipment_id as equipment_id, A.rent_from as rent_from, A.rent_to as rent_to, B.name as name, B.surname as surname, B.country as country, B.city as city, B.address as address, B.phone as phone, B.document_type as document_type, B.document_number as document_number, C.type as type, C.condition as `condition` FROM `reservations` AS A JOIN `users` AS B ON A.user_id = B.id JOIN `equipment` AS C ON A.equipment_id = C.id WHERE %1").arg(likes.join(" OR "));
}

QString ReservationQueryBuilder::getFindByUserQuery(int userId) {
    return QString("SELECT * FROM %1 WHERE user_id = %2").arg(this->tableName).arg(userId);
}

QString ReservationQueryBuilder::getFindByEquipmentQuery(int equipmentId) {
    return QString("SELECT * FROM %1 WHERE equipment_id = %2").arg(this->tableName).arg(equipmentId);
}

QString ReservationQueryBuilder::getFindByRentDateQuery(QDateTime dateFrom, QDateTime dateTo) {
    return QString("SELECT * FROM %1 WHERE (rent_from BETWEEN '%2' AND '%3') OR (rent_to BETWEEN '%2' AND '%3')").arg(this->tableName).arg(dateFrom.toString("yyyy-MM-dd hh:mm")).arg(dateTo.toString("yyyy-MM-dd hh:mm"));
}
