#ifndef DATABASEADAPTER_H
#define DATABASEADAPTER_H

#include "dbrow.h"
#include "querybuilder.h"

#include <QList>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>

class DatabaseAdapter
{
public:
    DatabaseAdapter();
    ~DatabaseAdapter();

    virtual QList< DBRow > select(QString query) = 0;
    virtual void update(QString query) = 0;

protected:
    QList<QString> columns(QString tableName);

protected:
    QSqlDatabase db;
};

#endif // DATABASEADAPTER_H
