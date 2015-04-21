#include "dao/equipmentdao.h"

EquipmentDAO::EquipmentDAO() : BaseDAO<Equipment>() {
}

EquipmentDAO::~EquipmentDAO() {
}

QList<Equipment*> EquipmentDAO::available() {
    QString sql = this->queryBuilder->getListAllQuery();
    QList<DBRow> rows = DatabaseConnectorSingleton::instance()->getDatabase()->select(sql);
    QList<Equipment*> users = EntityConverter<Equipment>::convert(rows);

    return users;
}
