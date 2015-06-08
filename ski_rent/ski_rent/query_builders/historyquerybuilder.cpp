#include "query_builders/historyquerybuilder.h"

HistoryQueryBuilder::HistoryQueryBuilder() {
    this->tableName = "history";
}

HistoryQueryBuilder::~HistoryQueryBuilder() {
}

QString HistoryQueryBuilder::getListAllQuery() {
    return QString("SELECT * FROM %1").arg(this->tableName);
}

QString HistoryQueryBuilder::getCreateQuery(History* newEntity) {
    QStringList columns;
    QStringList values;

    columns.append("name");
    columns.append("surname");
    columns.append("document_type");
    columns.append("document_number");
    columns.append("country");
    columns.append("city");
    columns.append("address");
    columns.append("phone");
    columns.append("type");
    columns.append("amount");
    columns.append("condition");
    columns.append("rent_from");
    columns.append("rent_to");
    columns.append("price");

    values.append(newEntity->getName());
    values.append(newEntity->getSurname());
    values.append(newEntity->getDocumentType());
    values.append(newEntity->getDocumentNumber());
    values.append(newEntity->getCountry());
    values.append(newEntity->getCity());
    values.append(newEntity->getAddress());
    values.append(newEntity->getPhone());
    values.append(newEntity->getType());
    values.append(QString::number(newEntity->getAmount()));
    values.append(QString::number(newEntity->getCondition()));
    values.append(newEntity->getRentFrom().toString("yyyy-MM-dd hh:mm"));
    values.append(newEntity->getRentTo().toString("yyyy-MM-dd hh:mm"));
    values.append(QString::number(newEntity->getPrice()));

    for (int i = 0; i < columns.size(); i++) {
        columns[i] = QString("`%1`").arg(columns[i]);
        values[i] = QString("'%1'").arg(values[i]);
    }

    QString res = QString("INSERT INTO %1 (%2) VALUES (%3);")
            .arg(this->tableName)
            .arg(columns.join(", "))
            .arg(values.join(", "));

    return res;
}

QString HistoryQueryBuilder::getCreateQuery(User *user, Equipment *equipment, Rent *rent, QDateTime rentTo, Price *price) {
    QStringList columns;
    QStringList values;

    columns.append("name");
    columns.append("surname");
    columns.append("document_type");
    columns.append("document_number");
    columns.append("country");
    columns.append("city");
    columns.append("address");
    columns.append("phone");
    columns.append("type");
    columns.append("amount");
    columns.append("condition");
    columns.append("rent_from");
    columns.append("rent_to");
    columns.append("price");

    values.append(user->getName());
    values.append(user->getSurname());
    values.append(user->getDocumentType());
    values.append(user->getDocumentNumber());
    values.append(user->getCountry());
    values.append(user->getCity());
    values.append(user->getAddress());
    values.append(user->getPhone());

    values.append(equipment->getType());

    values.append(QString::number(rent->getAmount()));
    values.append(QString::number(equipment->getCondition()));
    values.append(rent->getRentFrom().toString("yyyy-MM-dd hh:mm"));
    values.append(rentTo.toString("yyyy-MM-dd hh:mm"));
    values.append(QString::number(price->getPrice()));

    for (int i = 0; i < columns.size(); i++) {
        columns[i] = QString("`%1`").arg(columns[i]);
        values[i] = QString("'%1'").arg(values[i]);
    }

    QString res = QString("INSERT INTO %1 (%2) VALUES (%3);")
            .arg(this->tableName)
            .arg(columns.join(", "))
            .arg(values.join(", "));

    return res;
}

QString HistoryQueryBuilder::getFindQuery(int id) {
    return QString("SELECT * FROM %1 WHERE id = %2").arg(this->tableName).arg(id);
}

QString HistoryQueryBuilder::getSearchQuery(QString query) {
    QString likeCondition = QString("'%%1%'").arg(QString(query).split("\\s+").join("%"));
    QStringList likes;
    QStringList searchColumns;

    searchColumns.append("name");
    searchColumns.append("surname");
    searchColumns.append("country");
    searchColumns.append("city");
    searchColumns.append("address");
    searchColumns.append("phone");
    searchColumns.append("type");
    searchColumns.append("amount");
    searchColumns.append("condition");
    searchColumns.append("rent_from");
    searchColumns.append("rent_to");
    searchColumns.append("price");
    searchColumns.append("document_type");
    searchColumns.append("document_number");

    if (query.isEmpty()) {
        likes.append("TRUE");
    } else {
        for (int i = 0; i < searchColumns.size(); i++) {
            likes.append(QString("`%1` LIKE %2").arg(searchColumns[i]).arg(likeCondition));
        }
    }

    return QString("SELECT * FROM `%1` WHERE %2").arg(this->tableName).arg(likes.join(" OR "));
}
