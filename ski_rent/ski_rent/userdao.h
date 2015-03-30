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
#include "querybuilder.h"
#include "userquerybuilder.h"

class UserDAO : public BaseDAO<User>
{
public:
    UserDAO();
    ~UserDAO();

    QList<User> findUsers(QString query);
};

#endif // USERDAO_H
