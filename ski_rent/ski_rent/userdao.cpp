#include "userdao.h"

UserDAO::UserDAO()
{

}

UserDAO::~UserDAO()
{

}

DatabaseAdapter* UserDAO::getDb() {
    // TODO: write handler for a situation when no database is returned
    return DatabaseConnector::getSingletonPtr()->getDatabase();
}

QList<User> UserDAO::getAllUsers() {
    DatabaseAdapter* db = this->getDb();
    QList<DBRow> rows = db->select("SELECT * FROM users");
    QList<User> users = EntityConverter::convert<User>(rows);

    return users;
}

QList<User> UserDAO::findUsers(QString query) {
    QList<User> res;

    // TODO: implement

    return res;
}

User* UserDAO::getUser(unsigned int id) {
    // TODO: implement

    return 0;
}

void UserDAO::updateUser(User newUserData) {
    // TODO: implement
}

void UserDAO::deleteUser(unsigned int id) {
    // TODO: implement
}
