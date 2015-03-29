#include "userdao.h"

UserDAO::UserDAO()
{

}

UserDAO::~UserDAO()
{

}

QList<User> UserDAO::getAllUsers() {
    QString sql = QueryBuilder::getListAllQuery<User>();
    QList<DBRow> rows = this->getDb()->select(sql);
    QList<User> users = EntityConverter::convert<User>(rows);

    return users;
}

QList<User> UserDAO::findUsers(QString query) {
    QString sql = QueryBuilder::getSearchQuery<User>(query);

    QList<DBRow> rows = this->getDb()->select(sql);
    QList<User> users = EntityConverter::convert<User>(rows);

    return users;
}

User UserDAO::getUser(unsigned int id) {
    QString sql = QueryBuilder::getReadQuery<User>(id);

    QList<DBRow> rows = this->getDb()->select(sql);

    if (rows.size() < 1) {
        throw QString("Could not find user with id = %1").arg(id).toStdString().c_str();
    }

    return EntityConverter::convert<User>(rows[0]);
}

void UserDAO::updateUser(User newUserData) {
    QString sql = QueryBuilder::getCreateQuery<User>(newUserData);

    this->getDb()->update(sql);
}

void UserDAO::deleteUser(unsigned int id) {
    QString sql = QueryBuilder::getDeleteQuery<User>(id);

    this->getDb()->update(sql);
}
