#include "basedao.h"

BaseDAO::BaseDAO()
{

}

BaseDAO::~BaseDAO()
{

}

DatabaseAdapter* BaseDAO::getDb() {
    // TODO: write handler for a situation when no database is returned
    return DatabaseConnector::getSingletonPtr()->getDatabase();
}

