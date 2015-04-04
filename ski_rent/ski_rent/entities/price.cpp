#include "entities/price.h"

Price::Price() {
}

Price::~Price() {
}

QVariant Price::get(QString field) {
    return this->fields[field];
}

void Price::set(QString field, QVariant value) {
    this->fields[field] = value;
}

int Price::getTime() {
    return this->get("time").toInt();
}

char Price::getCondition() {
    return this->get("condition").toChar().unicode();
}

QString Price::getType() {
    return this->get("type").toString();
}

float Price::getPrice() {
    return this->get("price").toFloat();
}


void Price::setTime(int val) {
    this->set("time", val);
}

void Price::setCondition(char val) {
    this->set("condition", val);
}

void Price::setType(QString val) {
    this->set("type", val);
}

void Price::setPrice(float val) {
    this->set("price", val);
}

