#include "entities/baseentity.h"

BaseEntity::BaseEntity()
{

}

BaseEntity::~BaseEntity()
{

}

unsigned int BaseEntity::getId() {
    return this->id;
}

void BaseEntity::setId(unsigned int val) {
    this->id = val;
}

QVariant BaseEntity::get(QString field) {
    return this->fields[field];
}

void BaseEntity::set(QString field, QVariant value) {
    this->fields[field] = value;
}
