#include "userquerybuilder.h"
#include "user.h"
#include <QString>
#include <QStringList>

UserQueryBuilder::UserQueryBuilder() : QueryBuilder()
{
    this->tableName = "users";

    this->updateColumns.append("name");
    this->updateColumns.append("surname");
    this->updateColumns.append("document_number");
    this->updateColumns.append("country");
    this->updateColumns.append("city");
    this->updateColumns.append("address");
    this->updateColumns.append("phone");

    this->searchColumns.append("name");
    this->searchColumns.append("surname");
    this->searchColumns.append("document_number");
    this->searchColumns.append("country");
    this->searchColumns.append("city");
    this->searchColumns.append("address");
    this->searchColumns.append("phone");
}

UserQueryBuilder::~UserQueryBuilder() {
}
