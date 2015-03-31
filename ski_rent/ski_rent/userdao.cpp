#include "userdao.h"

UserDAO::UserDAO() : BaseDAO<User>() {
}

UserDAO::~UserDAO() {
}

QList<User> UserDAO::findUsers(QString query) {
    QString sql = this->queryBuilder->getSearchQuery(query);
    QList<DBRow> rows = DatabaseConnector::getSingletonPtr()->getDatabase()->select(sql);
    QList<User> users = EntityConverter<User>::convert(rows);

    return users;
}
