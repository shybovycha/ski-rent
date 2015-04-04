#include "dao/pricedao.h"

PriceDAO::PriceDAO() {
    this->queryBuilder = new PriceQueryBuilder();
}

PriceDAO::~PriceDAO() {
    delete this->queryBuilder;
}

DatabaseAdapter* PriceDAO::getDb() {
    return DatabaseConnector::getSingletonPtr()->getDatabase();
}

void PriceDAO::create(Price newEntity) {
    QString sql = this->queryBuilder->getCreateQuery(newEntity);
    this->getDb()->update(sql);
}

void PriceDAO::update(QString type, char condition, int time, Price newEntity) {
    QString sql = this->queryBuilder->getUpdateQuery(type, condition, time, newEntity);
    this->getDb()->update(sql);
}

void PriceDAO::remove(QString type, char condition, int time) {
    QString sql = this->queryBuilder->getRemoveQuery(type, condition, time);
    this->getDb()->update(sql);
}

QList<Price> PriceDAO::find(QString type, char condition, int time) {
    QString sql = this->queryBuilder->getFindQuery(type, condition, time);
    QList<DBRow> rows = this->getDb()->select(sql);
    QList<Price> prices = EntityConverter<Price>::convert(rows);

    return prices;
}
