#include "dao/equipmentdao.h"

EquipmentDAO::EquipmentDAO() {
    this->queryBuilder = new EquipmentQueryBuilder();
}

EquipmentDAO::~EquipmentDAO() {
    delete this->queryBuilder;
}

DatabaseAdapter* EquipmentDAO::getDb() {
    return DatabaseConnectorSingleton::instance()->getDatabase();
}

QList<Equipment*> EquipmentDAO::all() {
    QString sql = this->queryBuilder->getListAllQuery();
    return EntityConverter<Equipment>::convert(this->getDb()->select(sql));
}

Equipment* EquipmentDAO::findById(int id) {
    QString sql = this->queryBuilder->getReadQuery(id);
    QList<Equipment*> res = EntityConverter<Equipment>::convert(this->getDb()->select(sql));

    if (res.size() > 0) {
        return res[0];
    } else {
        throw QString("Could not find entity with id = %1").arg(id).toStdString().c_str();
    }
}

QList<Equipment*> EquipmentDAO::find(QString query) {
    QString sql = this->queryBuilder->getSearchQuery(query);
    return EntityConverter<Equipment>::convert(this->getDb()->select(sql));
}

void EquipmentDAO::create(Equipment* entity) {
    QString sql = this->queryBuilder->getCreateQuery(entity);
    this->getDb()->update(sql);
}

void EquipmentDAO::update(Equipment* entity) {
    QString sql = this->queryBuilder->getUpdateQuery(entity);
    this->getDb()->update(sql);
}

void EquipmentDAO::remove(int id) {
    QString sql = this->queryBuilder->getDeleteQuery(id);
    this->getDb()->update(sql);
}

QList<Equipment*> EquipmentDAO::available() {
    QString sql = this->queryBuilder->getListAllQuery();
    QList<DBRow> rows = DatabaseConnectorSingleton::instance()->getDatabase()->select(sql);
    QList<Equipment*> users = EntityConverter<Equipment>::convert(rows);

    return users;
}

QList<Equipment*> EquipmentDAO::availableForUsage() {
    QString sql = this->queryBuilder->getListUsableQuery();
    QList<DBRow> rows = DatabaseConnectorSingleton::instance()->getDatabase()->select(sql);
    QList<Equipment*> users = EntityConverter<Equipment>::convert(rows);

    return users;
}
