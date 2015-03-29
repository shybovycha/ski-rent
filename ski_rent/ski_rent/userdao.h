#ifndef USERDAO_H
#define USERDAO_H

#include "user.h"
#include "QList"
#include "QString"
#include "databaseadapter.h"
#include "databaseconnector.h"
#include "entityconverter.h"

class UserDAO
{
public:
    UserDAO();
    ~UserDAO();

    QList<User> getAllUsers();
    QList<User> findUsers(QString query);
    User* getUser(unsigned int id);
    void updateUser(User newUserData);
    void deleteUser(unsigned int id);

protected:
    DatabaseAdapter* getDb();
};

#endif // USERDAO_H
