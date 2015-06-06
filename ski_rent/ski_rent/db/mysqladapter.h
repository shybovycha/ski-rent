#ifndef MYSQLADAPTER_H
#define MYSQLADAPTER_H

#include "db/dbrow.h"
#include "db/databaseadapter.h"

#include <QtSql/QSqlError>

class MySQLAdapter : public DatabaseAdapter
{
public:
    MySQLAdapter(QString host, int port, QString user, QString password, QString database);
    ~MySQLAdapter();

    virtual QList< DBRow > select(QString query);
    virtual bool update(QString query);
};

#endif // MYSQLADAPTER_H
