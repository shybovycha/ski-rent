#ifndef QUERYBUILDER_H
#define QUERYBUILDER_H

#include <QString>
#include <QStringList>

template<typename T>
class QueryBuilder
{
public:
    QString getCreateQuery(T entity);
    QString getReadQuery(int id);
    QString getUpdateQuery(T newEntity);
    QString getDeleteQuery(int id);
    QString getSearchQuery(QString query);
    QString getListAllQuery();

protected:
    QueryBuilder();
    ~QueryBuilder();

protected:
    QStringList searchColumns;
    QStringList updateColumns;
    QString tableName;
};

template<typename T>
QueryBuilder<T>::QueryBuilder() {
}

template<typename T>
QueryBuilder<T>::~QueryBuilder() {
}

template<typename T>
QString QueryBuilder<T>::getCreateQuery(T entity) {
    QStringList valueList;

    for (int i = 0; i < this->updateColumns.size(); i++) {
        valueList.append(QString("'%1'").arg(entity.get(this->updateColumns[i]).toString()));
    }

    QString res =
            QString("INSERT INTO %1 (%2) VALUES (%3)")
            .arg(this->tableName)
            .arg(this->updateColumns.join(", "))
            .arg(valueList.join(", "));

    return res;
}

template<typename T>
QString QueryBuilder<T>::getReadQuery(int id) {
    QString res = QString("SELECT * FROM %1 WHERE id = %2").arg(this->tableName).arg(id);

    return res;
}

template<typename T>
QString QueryBuilder<T>::getSearchQuery(QString query) {
    QString likeCondition = QString("'%%1%'").arg(QString(query).split("\\s+").join("%"));
    QStringList likes;

    for (int i = 0; i < this->searchColumns.size(); i++) {
        likes.append(QString("`%1` LIKE %2").arg(this->searchColumns[i]).arg(likeCondition));
    }

    QString sql = QString("SELECT * FROM users WHERE %1").arg(likes.join(" OR "));

    return sql;
}

template<typename T>
QString QueryBuilder<T>::getUpdateQuery(T newEntity) {
    QStringList updates;

    for (int i = 0; i < this->updateColumns.size(); i++) {
        updates.append(QString("'%1'").arg(newEntity.get(this->updateColumns[i]).toString()));
    }

    QString res =
            QString("UPDATE %1 SET %2 WHERE id = %3")
            .arg(this->tableName)
            .arg(updates.join(", "))
            .arg(newEntity.getId());

    return res;
}

template<typename T>
QString QueryBuilder<T>::getDeleteQuery(int id) {
    QString res = QString("DELETE FROM %1 WHERE id = %2").arg(this->tableName).arg(id);

    return res;
}

template<typename T>
QString QueryBuilder<T>::getListAllQuery() {
    QString res = QString("SELECT * FROM %1").arg(this->tableName);

    return res;
}


#endif // QUERYBUILDER_H
