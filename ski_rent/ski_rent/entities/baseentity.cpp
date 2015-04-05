#include "entities/baseentity.h"

BaseEntity::BaseEntity()
{
    this->id = -1;
}

BaseEntity::~BaseEntity()
{
}

unsigned int BaseEntity::getId() const {
    return this->id;
}

void BaseEntity::setId(unsigned int val) {
    this->id = val;
}

QVariant BaseEntity::get(QString field) const {
    return this->fields[field];
}

void BaseEntity::set(QString field, QVariant value) {
    this->fields[field] = value;
}

bool BaseEntity::operator=(const BaseEntity &e) {
    this->fields.clear();

    for (QMap<QString, QVariant>::const_iterator it = e.fields.begin(); it != e.fields.end(); it++) {
        this->fields[it.key()] = it.value();
    }

    return true;
}
