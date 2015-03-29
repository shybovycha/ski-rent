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
    /*QString likeCondition = QString("'%%%1%%'").arg(QString(query).split("\\s+").join("%"));
    QString whereCondition = QString("name LIKE '%1' OR surname LIKE %1 OR document_number LIKE %1 OR country LIKE %1 OR city LIKE %1 OR address LIKE %1 OR phone LIKE %1").arg(likeCondition);
    QString sql = QString("SELECT * FROM users WHERE %1").arg(whereCondition);*/

    QString sql = QueryBuilder::getSearchQuery<User>(query);

    QList<DBRow> rows = this->getDb()->select(sql);
    QList<User> users = EntityConverter::convert<User>(rows);

    return users;
}

User UserDAO::getUser(unsigned int id) {
    //QString query = QString("SELECT * FROM users WHERE id = %1;").arg(id);

    QString sql = QueryBuilder::getReadQuery<User>(id);

    QList<DBRow> rows = this->getDb()->select(sql);

    if (rows.size() < 1) {
        throw QString("Could not find user with id = %1").arg(id).toStdString().c_str();
    }

    return EntityConverter::convert<User>(rows[0]);
}

void UserDAO::updateUser(User newUserData) {
    /*QString query = QString("UPDATE users SET name = '%2', surname = '%3', document_type = '%4', document_number = '%5', country = '%6', city = '%7', address = '%8', phone = '%9' WHERE id = %1")
            .arg(newUserData.getId())
            .arg(newUserData.getName(), newUserData.getSurname(), newUserData.getDocumentType(), newUserData.getDocumentNumber())
            .arg(newUserData.getCountry(), newUserData.getCity(), newUserData.getAddress(), newUserData.getPhone());*/

    QString sql = QueryBuilder::getCreateQuery<User>(newUserData);

    this->getDb()->update(sql);
}

void UserDAO::deleteUser(unsigned int id) {
    //QString query = QString("DELETE FROM users WHERE id = %1;").arg(id);
    QString sql = QueryBuilder::getDeleteQuery<User>(id);

    this->getDb()->update(sql);
}
