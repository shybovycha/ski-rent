#ifndef USERDAO_H
#define USERDAO_H

#include "QList"
#include "QString"

#include "user.h"
#include "basedao.h"
#include "databaseadapter.h"
#include "databaseconnector.h"
#include "entityconverter.h"
#include "querybuilder.h"

class UserDAO : public BaseDAO
{
public:
    UserDAO();
    ~UserDAO();

    QList<User> getAllUsers();
    QList<User> findUsers(QString query);
    User getUser(unsigned int id);
    void updateUser(User newUserData);
    void deleteUser(unsigned int id);
};

#endif // USERDAO_H
