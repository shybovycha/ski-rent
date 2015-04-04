#include "db/databaseconnector.h"

DatabaseConnector::DatabaseConnector()
{
    this->dbAdapter = 0;
}

DatabaseConnector::~DatabaseConnector()
{

}

DatabaseConnector* DatabaseConnector::getSingletonPtr() {
    static DatabaseConnector* instance;

    if (!instance) {
        instance = new DatabaseConnector();
    }

    return instance;
}

DatabaseAdapter* DatabaseConnector::getDatabase() {
    // TODO: REWORK!
    if (!this->dbAdapter) {
        this->dbAdapter = new MySQLAdapter("localhost", 3306, "root", "abcABC123", "ski_rent");
    }

    return this->dbAdapter;
}
