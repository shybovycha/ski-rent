#include "querybuilder.h"
#include "user.h"
#include <QString>
#include <QStringList>

template<>
QString QueryBuilder::getCreateQuery<User>(User entity) {
    QString res =
            QString("INSERT INTO users (name, surname, document_type, document_number, country, city, address, phone) VALUES ('%1', '%2', '%3', '%4', '%5', '%6', '%7', '%8')")
            .arg(entity.getName())
            .arg(entity.getSurname())
            .arg(entity.getDocumentType())
            .arg(entity.getDocumentNumber())
            .arg(entity.getCountry())
            .arg(entity.getCity())
            .arg(entity.getAddress())
            .arg(entity.getPhone())
            ;

    return res;
}

template<>
QString QueryBuilder::getReadQuery<User>(int id) {
    QString res = QString("SELECT * FROM users WHERE id = %1").arg(id);

    return res;
}

template<>
QString QueryBuilder::getSearchQuery<User>(QString query) {
    QString likeCondition = QString("'%%1%'").arg(QString(query).split("\\s+").join("%"));
    QString whereCondition = QString("name LIKE %1 OR surname LIKE %1 OR document_number LIKE %1 OR country LIKE %1 OR city LIKE %1 OR address LIKE %1 OR phone LIKE %1").arg(likeCondition);
    QString sql = QString("SELECT * FROM users WHERE %1").arg(whereCondition);

    return sql;
}

template<>
QString QueryBuilder::getUpdateQuery<User>(User newEntity) {
    QString res =
            QString("UPDATE users SET name = '%2', surname = '%3', document_type = '%4', document_number = '%5', country = '%6', city = '%7', address = '%8', phone = '%9' WHERE id = %1")
            .arg(newEntity.getId())
            .arg(newEntity.getName())
            .arg(newEntity.getSurname())
            .arg(newEntity.getDocumentType())
            .arg(newEntity.getDocumentNumber())
            .arg(newEntity.getCountry())
            .arg(newEntity.getCity())
            .arg(newEntity.getAddress())
            .arg(newEntity.getPhone())
            ;

    return res;
}

template<>
QString QueryBuilder::getDeleteQuery<User>(int id) {
    QString res = QString("DELETE FROM users WHERE id = %1").arg(id);

    return res;
}

template<>
QString QueryBuilder::getListAllQuery<User>() {
    QString res = QString("SELECT * FROM users");

    return res;
}
