#ifndef QUERYBUILDER_H
#define QUERYBUILDER_H

#include <QString>

class QueryBuilder
{
public:
    template<typename T> static QString getCreateQuery(T entity);
    template<typename T> static QString getReadQuery(int id);
    template<typename T> static QString getUpdateQuery(T newEntity);
    template<typename T> static QString getDeleteQuery(int id);
    template<typename T> static QString getSearchQuery(QString query);
    template<typename T> static QString getListAllQuery();

protected:
    QueryBuilder();
    ~QueryBuilder();
};

#endif // QUERYBUILDER_H
