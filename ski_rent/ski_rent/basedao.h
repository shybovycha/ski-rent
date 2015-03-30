#ifndef BASEDAO_H
#define BASEDAO_H

#include "databaseadapter.h"
#include "databaseconnector.h"
#include "entityconverter.h"
#include "querybuilder.h"

#include <QList>
#include <QString>
#include <QStringList>

template<typename T>
class BaseDAO
{
public:
    BaseDAO();
    ~BaseDAO();

    QList<T> all();
    T find(int id);
    QList<T> find(QString query);
    void create(T entity);
    void update(T entity);
    void remove(int id);

protected:
    QueryBuilder<T>* queryBuilder;
    DatabaseAdapter* getDb();
};

template<typename T>
BaseDAO<T>::BaseDAO() {
    this->queryBuilder = new QueryBuilder<T>();
}

template<typename T>
BaseDAO<T>::~BaseDAO() {
    delete this->queryBuilder;
}

template<typename T>
QList<T> BaseDAO<T>::all() {
    QString sql = this->queryBuilder->getListAllQuery();
    return EntityConverter<T>::convert(DatabaseConnector::getSingletonPtr()->getDatabase()->select(sql));
}

template<typename T>
T BaseDAO<T>::find(int id) {
    QString sql = this->queryBuilder->getReadQuery(id);
    return EntityConverter<T>::convert(DatabaseConnector::getSingletonPtr()->getDatabase()->select(sql));
}

template<typename T>
QList<T> BaseDAO<T>::find(QString query) {
    QString sql = this->queryBuilder->getSearchQuery(query);
    return EntityConverter<T>::convert(DatabaseConnector::getSingletonPtr()->getDatabase()->select(sql));
}

template<typename T>
void BaseDAO<T>::create(T entity) {
    QString sql = this->queryBuilder->getCreateQuery(entity);
    DatabaseConnector::getSingletonPtr()->getDatabase()->update(sql);
}

template<typename T>
void BaseDAO<T>::update(T entity) {
    QString sql = this->queryBuilder->getUpdateQuery(entity);
    DatabaseConnector::getSingletonPtr()->getDatabase()->update(sql);
}

template<typename T>
void BaseDAO<T>::remove(int id) {
    QString sql = this->queryBuilder->getDeleteQuery(id);
    DatabaseConnector::getSingletonPtr()->getDatabase()->update(sql);
}

#endif // BASEDAO_H
