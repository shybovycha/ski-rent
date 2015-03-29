#ifndef DATABASECONNECTOR_H
#define DATABASECONNECTOR_H

#include "databaseadapter.h"
#include "mysqladapter.h"

class DatabaseConnector
{
public:
    static DatabaseConnector* getSingletonPtr();

    DatabaseAdapter* getDatabase();

protected:
    DatabaseConnector();
    ~DatabaseConnector();

    DatabaseAdapter* dbAdapter;
};

#endif // DATABASECONNECTOR_H
