#include "dao/reservationdao.h"
#include <QDebug>

ReservationDAO::ReservationDAO() {
    this->queryBuilder = new ReservationQueryBuilder();
}

ReservationDAO::~ReservationDAO() {
    delete this->queryBuilder;
}

DatabaseAdapter* ReservationDAO::getDb() {
    return DatabaseConnectorSingleton::instance()->getDatabase();
}

void ReservationDAO::toRent(Reservation *oldEntity) {
    QString sql = this->queryBuilder->getToRentQuery(oldEntity);
    this->getDb()->update(sql);

    sql = this->queryBuilder->getRemoveQuery(oldEntity->getUserId(), oldEntity->getEquipmentId());
    this->getDb()->update(sql);
}

QList<Reservation*> ReservationDAO::all() {
    QString sql = this->queryBuilder->getListAllQuery();
    QList<DBRow> rows = this->getDb()->select(sql);

    return EntityConverter<Reservation>::convert(rows);
}

QList<Reservation*> ReservationDAO::find(QString query) {
    QString sql = this->queryBuilder->getSearchQuery(query);
    QList<DBRow> rows = this->getDb()->select(sql);
    qDebug() << sql;

    return EntityConverter<Reservation>::convert(rows);
}

QList<Reservation*> ReservationDAO::findByUser(int userId) {
    QString sql = this->queryBuilder->getFindByUserQuery(userId);
    QList<DBRow> rows = this->getDb()->select(sql);

    return EntityConverter<Reservation>::convert(rows);
}

QList<Reservation*> ReservationDAO::findByEquipment(int equipmentId) {
    QString sql = this->queryBuilder->getFindByEquipmentQuery(equipmentId);
    QList<DBRow> rows = this->getDb()->select(sql);

    return EntityConverter<Reservation>::convert(rows);
}

QList<Reservation*> ReservationDAO::findByRentDate(QDateTime dateFrom, QDateTime dateTo) {
    QString sql = this->queryBuilder->getFindByRentDateQuery(dateFrom, dateTo);
    QList<DBRow> rows = this->getDb()->select(sql);

    return EntityConverter<Reservation>::convert(rows);
}

void ReservationDAO::create(Reservation* newEntity) {
    QString sql = this->queryBuilder->getCreateQuery(newEntity);
    this->getDb()->update(sql);
}

void ReservationDAO::remove(int userId, int equipmentId) {
    QString sql = this->queryBuilder->getRemoveQuery(userId, equipmentId);
    this->getDb()->update(sql);
}

void ReservationDAO::update(int userId, int equipmentId, Reservation* newEntity) {
    QString sql = this->queryBuilder->getUpdateQuery(userId, equipmentId, newEntity);
    this->getDb()->update(sql);
}

