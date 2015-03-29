#ifndef BASEDAO_H
#define BASEDAO_H

#include "databaseadapter.h"
#include "databaseconnector.h"
#include "entityconverter.h"

class BaseDAO
{
protected:
    BaseDAO();
    ~BaseDAO();

    DatabaseAdapter* getDb();
};

#endif // BASEDAO_H
