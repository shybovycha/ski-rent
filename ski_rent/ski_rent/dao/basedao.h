#ifndef BASEDAO_H
#define BASEDAO_H

#include "db/databaseadapter.h"
#include "db/databaseconnector.h"
#include "entity_converters/entityconverter.h"
#include "query_builders/querybuilder.h"

#include <QList>
#include <QString>
#include <QStringList>

template<typename T>
class BaseDAO
{
public:
    BaseDAO();
    ~BaseDAO();

    QList<T*> all();
    T* findById(int id);
    QList<T*> find(QString query);
    void create(T* entity);
    void update(T* entity);
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
DatabaseAdapter* BaseDAO<T>::getDb() {
    return DatabaseConnectorSingleton::instance()->getDatabase();
}

template<typename T>
QList<T*> BaseDAO<T>::all() {
    QString sql = this->queryBuilder->getListAllQuery();
    return EntityConverter<T>::convert(this->getDb()->select(sql));
}

template<typename T>
T* BaseDAO<T>::findById(int id) {
    QString sql = this->queryBuilder->getReadQuery(id);
    QList<T*> res = EntityConverter<T>::convert(this->getDb()->select(sql));

    if (res.size() > 0) {
        return res[0];
    } else {
        throw QString("Could not find entity with id = %1").arg(id).toStdString().c_str();
    }
}

template<typename T>
QList<T*> BaseDAO<T>::find(QString query) {
    QString sql = this->queryBuilder->getSearchQuery(query);
    return EntityConverter<T>::convert(this->getDb()->select(sql));
}

template<typename T>
void BaseDAO<T>::create(T* entity) {
    QString sql = this->queryBuilder->getCreateQuery(entity);
    this->getDb()->update(sql);
}

template<typename T>
void BaseDAO<T>::update(T* entity) {
    QString sql = this->queryBuilder->getUpdateQuery(entity);
    this->getDb()->update(sql);
}

template<typename T>
void BaseDAO<T>::remove(int id) {
    QString sql = this->queryBuilder->getDeleteQuery(id);
    this->getDb()->update(sql);
}

#endif // BASEDAO_H
