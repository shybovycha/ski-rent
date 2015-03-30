#ifndef QUERYBUILDER_H
#define QUERYBUILDER_H

#include <QString>

template<typename T>
class QueryBuilder
{
public:
    static QString getCreateQuery(T entity);
    static QString getReadQuery(int id);
    static QString getUpdateQuery(T newEntity);
    static QString getDeleteQuery(int id);
    static QString getSearchQuery(QString query);
    static QString getListAllQuery();
};

#endif // QUERYBUILDER_H
