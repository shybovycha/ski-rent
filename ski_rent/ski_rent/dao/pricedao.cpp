#include "dao/pricedao.h"

PriceDAO::PriceDAO() {
    this->queryBuilder = new PriceQueryBuilder();
}

PriceDAO::~PriceDAO() {
    delete this->queryBuilder;
}

DatabaseAdapter* PriceDAO::getDb() {
    return DatabaseConnectorSingleton::instance()->getDatabase();
}

void PriceDAO::create(Price* newEntity) {
    QString sql = this->queryBuilder->getCreateQuery(newEntity);
    this->getDb()->update(sql);
}

void PriceDAO::update(QString type, char condition, int time, Price* newEntity) {
    QString sql = this->queryBuilder->getUpdateQuery(type, condition, time, newEntity);
    this->getDb()->update(sql);
}

void PriceDAO::remove(QString type, char condition, int time) {
    QString sql = this->queryBuilder->getRemoveQuery(type, condition, time);
    this->getDb()->update(sql);
}

QList<Price*> PriceDAO::all() {
    QString sql = this->queryBuilder->getListAllQuery();
    QList<DBRow> rows = this->getDb()->select(sql);
    QList<Price*> prices = EntityConverter<Price>::convert(rows);

    return prices;
}

QList<Price*> PriceDAO::find(QString query) {
    QString sql = this->queryBuilder->getSearchQuery(query);
    QList<DBRow> rows = this->getDb()->select(sql);
    QList<Price*> prices = EntityConverter<Price>::convert(rows);

    return prices;
}

QList<Price*> PriceDAO::find(QString type, char condition, int time) {
    if (time < 1) {
        time = 1;
    }

    QString sql = this->queryBuilder->getFindQuery(type, condition, time);
    QList<DBRow> rows = this->getDb()->select(sql);
    QList<Price*> prices = EntityConverter<Price>::convert(rows);

    return prices;
}

float PriceDAO::getPricePerHour(QString type, char condition, int time) {
    if (time < 1) {
        time = 1;
    }

    QList<Price*> prices = this->find(type, condition, time);

    if (prices.isEmpty()) {
        qDebug() << QString("Could not find matching price entry for `%1` (%2) for %3 hrs")
                    .arg(type)
                    .arg(condition)
                    .arg(time);

        return 0.0;
    }

    Price* fitPrice = prices[0];
    int hoursPriced = fitPrice->getTime();
    float perHoursPriced = fitPrice->getPrice();

    return ceil(time / hoursPriced) * perHoursPriced;
}

float PriceDAO::getPriceTotal(QString type, char condition, int time, int amount) {
    return this->getPricePerHour(type, condition, time) * amount;
}
