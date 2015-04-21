#ifndef USERDAO_H
#define USERDAO_H

#include "QList"
#include "QString"

#include "entities/user.h"
#include "dao/basedao.h"
#include "db/databaseadapter.h"
#include "db/databaseconnector.h"
#include "entity_converters/entityconverter.h"
#include "query_builders/querybuilder.h"
#include "query_builders/querybuilder.h"
#include "util/singleton.h"

class UserDAO : public BaseDAO<User>
{
public:
    UserDAO();
    ~UserDAO();

    QList<User*> find(QString query);
};

typedef Singleton<UserDAO> UserDAOSingleton;

#endif // USERDAO_H
