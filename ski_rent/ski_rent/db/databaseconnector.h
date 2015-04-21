#ifndef DATABASECONNECTOR_H
#define DATABASECONNECTOR_H

#include "db/databaseadapter.h"
#include "db/mysqladapter.h"
#include "util/singleton.h"

class DatabaseConnector
{
public:
    DatabaseConnector();
    ~DatabaseConnector();

    DatabaseAdapter* getDatabase();

protected:
    DatabaseAdapter* dbAdapter;
};

typedef Singleton<DatabaseConnector> DatabaseConnectorSingleton;

#endif // DATABASECONNECTOR_H
