#include "dao/userdao.h"

UserDAO::UserDAO() : BaseDAO<User>() {
}

UserDAO::~UserDAO() {
}

QList<User> UserDAO::find(QString query) {
    QString sql = this->queryBuilder->getSearchQuery(query);
    QList<DBRow> rows = DatabaseConnectorSingleton::instance()->getDatabase()->select(sql);
    QList<User> users = EntityConverter<User>::convert(rows);

    return users;
}
