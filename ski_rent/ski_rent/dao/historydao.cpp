#include "dao/historydao.h"

HistoryDAO::HistoryDAO() {
    this->queryBuilder = new HistoryQueryBuilder();
}

HistoryDAO::~HistoryDAO() {
    delete this->queryBuilder;
}

DatabaseAdapter* HistoryDAO::getDb() {
    return DatabaseConnectorSingleton::instance()->getDatabase();
}

QList<History*> HistoryDAO::all() {
    QString sql = this->queryBuilder->getListAllQuery();
    QList<DBRow> rows = this->getDb()->select(sql);
    QList<History*> res = EntityConverter<History>::convert(rows);

    return res;
}

History* HistoryDAO::find(int id) {
    QString sql = this->queryBuilder->getFindQuery(id);
    QList<DBRow> rows = this->getDb()->select(sql);
    QList<History*> res = EntityConverter<History>::convert(rows);

    if (res.size() > 0) {
        return res[0];
    } else {
        throw QString("Could not find entity with id = %1").arg(id).toStdString().c_str();
    }
}

void HistoryDAO::create(History* newEntity) {
    QString sql = this->queryBuilder->getCreateQuery(newEntity);
    this->getDb()->update(sql);
}

void HistoryDAO::create(User* user, Equipment *equipment, Rent *rent, QDateTime rentTo, Price *price) {
    QString sql = this->queryBuilder->getCreateQuery(user, equipment, rent, rentTo, price);
    this->getDb()->update(sql);
}
