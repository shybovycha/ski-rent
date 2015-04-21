#include "query_builders/reservationquerybuilder.h"

ReservationQueryBuilder::ReservationQueryBuilder() {
    this->tableName = "reservations";
}

ReservationQueryBuilder::~ReservationQueryBuilder() {
}

QString ReservationQueryBuilder::getListAllQuery() {
    return QString("SELECT * FROM %1").arg(this->tableName);
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

QString ReservationQueryBuilder::getUpdateQuery(int userId, int equipmentId, Reservation* newEntity) {
    QStringList values;

    values.append(QString("`amount` = %1").arg(newEntity->getAmount()));
    values.append(QString("`rent_from` = %1").arg(newEntity->getRentFrom().toString("yyyy-MM-dd hh:mm")));
    values.append(QString("`rent_to` = %1").arg(newEntity->getRentTo().toString("yyyy-MM-dd hh:mm")));

    QString res = QString("UPDATE %1 SET %2 WHERE `user_id` = %3 AND `equipment_id` = %4")
            .arg(this->tableName)
            .arg(values.join(", "))
            .arg(userId)
            .arg(equipmentId);

    return res;
}

QString ReservationQueryBuilder::getRemoveQuery(int userId, int equipmentId) {
    return QString("DELETE FROM %1 WHERE userId = %2 AND equipmentId = %3").arg(this->tableName).arg(userId).arg(equipmentId);
}

QString ReservationQueryBuilder::getFindByUserQuery(int userId) {
    return QString("SELECT * FROM %1 WHERE userId = %2").arg(this->tableName).arg(userId);
}

QString ReservationQueryBuilder::getFindByEquipmentQuery(int equipmentId) {
    return QString("SELECT * FROM %1 WHERE equipmentId = %2").arg(this->tableName).arg(equipmentId);
}

QString ReservationQueryBuilder::getFindByRentDateQuery(QDateTime dateFrom, QDateTime dateTo) {
    return QString("SELECT * FROM %1 WHERE (rent_from BETWEEN '%2' AND '%3') OR (rent_to BETWEEN '%2' AND '%3')").arg(this->tableName).arg(dateFrom.toString("yyyy-MM-dd hh:mm")).arg(dateTo.toString("yyyy-MM-dd hh:mm"));
}
