#include "baseentity.h"

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
