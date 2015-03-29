#ifndef MYSQLADAPTER_H
#define MYSQLADAPTER_H

#include "dbrow.h"
#include "databaseadapter.h"
#include "QtSql/QSqlError"

class MySQLAdapter : public DatabaseAdapter
{
public:
    MySQLAdapter(QString host, int port, QString user, QString password, QString database);
    ~MySQLAdapter();

    virtual QList< DBRow > select(QString query);
    virtual void update(QString query);
};

#endif // MYSQLADAPTER_H
