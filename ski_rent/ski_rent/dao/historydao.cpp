#include "dao/historydao.h"

HistoryDAO::HistoryDAO() {
    this->queryBuilder = new HistoryQueryBuilder();
}

HistoryDAO::~HistoryDAO() {

}

DatabaseAdapter* HistoryDAO::getDb() {
    return DatabaseConnector::getSingletonPtr()->getDatabase();
}

QList<History> HistoryDAO::all() {
    QString sql = this->queryBuilder->getListAllQuery();
    QList<DBRow> rows = this->getDb()->select(sql);
    QList<History> res = EntityConverter<History>::convert(rows);

    return res;
}

History HistoryDAO::find(int id) {
    QString sql = this->queryBuilder->getFindQuery(id);
    QList<DBRow> rows = this->getDb()->select(sql);
    QList<History> res = EntityConverter<History>::convert(rows);

    if (res.size() > 0) {
        return res[0];
    } else {
        throw QString("Could not find entity with id = %1").arg(id).toStdString().c_str();
    }
}

void HistoryDAO::create(History newEntity) {
    QString sql = this->queryBuilder->getCreateQuery(newEntity);
    this->getDb()->update(sql);
}
