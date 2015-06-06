#include "dao/rentdao.h"
#include <QDebug>

RentDAO::RentDAO() {
    this->queryBuilder = new RentQueryBuilder();
}

RentDAO::~RentDAO() {
    delete this->queryBuilder;
}

DatabaseAdapter* RentDAO::getDb() {
    return DatabaseConnectorSingleton::instance()->getDatabase();
}

void RentDAO::create(Rent* newEntity) {
    QString sql = this->queryBuilder->getCreateQuery(newEntity);
    this->getDb()->update(sql);
}

void RentDAO::update(Rent* oldEntity, Rent* newEntity) {
    QString sql = this->queryBuilder->getUpdateQuery(oldEntity, newEntity);
    this->getDb()->update(sql);
}

void RentDAO::remove(Rent* oldEntity) {
    QString sql = this->queryBuilder->getRemoveQuery(oldEntity);
    this->getDb()->update(sql);
}

QList<Rent*> RentDAO::all() {
    QString sql = this->queryBuilder->getSelectAllQuery();
    QList<DBRow> rows = this->getDb()->select(sql);
    QList<Rent*> res = EntityConverter<Rent>::convert(rows);

    return res;
}

QList<Rent*> RentDAO::find(QString query) {
    QString sql = this->queryBuilder->getSearchQuery(query);
    qDebug() << sql;
    QList<DBRow> rows = this->getDb()->select(sql);
    QList<Rent*> res = EntityConverter<Rent>::convert(rows);

    return res;
}

QList<Rent*> RentDAO::findByUser(int userId) {
    QString sql = this->queryBuilder->getFindByUserIdQuery(userId);
    QList<DBRow> rows = this->getDb()->select(sql);
    QList<Rent*> res = EntityConverter<Rent>::convert(rows);

    return res;
}

QList<Rent*> RentDAO::findByEquipment(int equipmentId) {
    QString sql = this->queryBuilder->getFindByEquipmentIdQuery(equipmentId);
    QList<DBRow> rows = this->getDb()->select(sql);
    QList<Rent*> res = EntityConverter<Rent>::convert(rows);

    return res;
}

QList<Rent*> RentDAO::findByRentFrom(QDateTime rentFrom) {
    QString sql = this->queryBuilder->getFindByRentFrom(rentFrom);
    QList<DBRow> rows = this->getDb()->select(sql);
    QList<Rent*> res = EntityConverter<Rent>::convert(rows);

    return res;
}

QList<Rent*> RentDAO::findByRentFrom(QDateTime rentFromStart, QDateTime rentFromEnd) {
    QString sql = this->queryBuilder->getFindByRentFrom(rentFromStart, rentFromEnd);
    QList<DBRow> rows = this->getDb()->select(sql);
    QList<Rent*> res = EntityConverter<Rent>::convert(rows);

    return res;
}
