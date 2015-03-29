#include "databaseadapter.h"

DatabaseAdapter::DatabaseAdapter()
{

}

DatabaseAdapter::~DatabaseAdapter()
{

}

QList<QString> DatabaseAdapter::columns(QString tableName) {
    if (!this->db.isOpen()) {
        throw "Database is not opened";
    }

    QSqlRecord record = this->db.record(tableName);
    QList<QString> result;

    for (int i = 0; i < record.count(); i++) {
        result.append(record.fieldName(i));
    }

    return result;
}
