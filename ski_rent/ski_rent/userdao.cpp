#include "userdao.h"

UserDAO::UserDAO()
{

}

UserDAO::~UserDAO()
{

}

QList<User> UserDAO::getAllUsers() {
    QString sql = QueryBuilder<User>::getListAllQuery();
    QList<DBRow> rows = this->getDb()->select(sql);
    QList<User> users = EntityConverter<User>::convert(rows);

    return users;
}

QList<User> UserDAO::findUsers(QString query) {
    QString sql = QueryBuilder<User>::getSearchQuery(query);

    QList<DBRow> rows = this->getDb()->select(sql);
    QList<User> users = EntityConverter<User>::convert(rows);

    return users;
}

User UserDAO::getUser(unsigned int id) {
    QString sql = QueryBuilder<User>::getReadQuery(id);

    QList<DBRow> rows = this->getDb()->select(sql);

    if (rows.size() < 1) {
        throw QString("Could not find user with id = %1").arg(id).toStdString().c_str();
    }

    return EntityConverter<User>::convert(rows[0]);
}

void UserDAO::updateUser(User newUserData) {
    QString sql = QueryBuilder<User>::getCreateQuery(newUserData);

    this->getDb()->update(sql);
}

void UserDAO::deleteUser(unsigned int id) {
    QString sql = QueryBuilder<User>::getDeleteQuery(id);

    this->getDb()->update(sql);
}
