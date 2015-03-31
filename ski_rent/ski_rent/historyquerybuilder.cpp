#include "historyquerybuilder.h"

HistoryQueryBuilder::HistoryQueryBuilder() {
    this->tableName = "history";
}

HistoryQueryBuilder::~HistoryQueryBuilder() {

}

QString HistoryQueryBuilder::getListAllQuery() {
    return QString("SELECT * FROM %1").arg(this->tableName);
}

QString HistoryQueryBuilder::getCreateQuery(History newEntity) {
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

    values.append(newEntity.getName());
    values.append(newEntity.getSurname());
    values.append(newEntity.getDocumentType());
    values.append(newEntity.getDocumentNumber());
    values.append(newEntity.getCountry());
    values.append(newEntity.getCity());
    values.append(newEntity.getAddress());
    values.append(newEntity.getPhone());
    values.append(newEntity.getType());
    values.append(QString::number(newEntity.getAmount()));
    values.append(QString::number(newEntity.getCondition()));
    values.append(newEntity.getRentFrom().toString("yyyy-MM-dd hh:mm"));
    values.append(newEntity.getRentTo().toString("yyyy-MM-dd hh:mm"));
    values.append(QString::number(newEntity.getPrice()));

    for (int i = 0; i < columns.size(); i++) {
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

