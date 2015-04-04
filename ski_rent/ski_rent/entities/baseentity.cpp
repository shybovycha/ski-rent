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
