#include "entities/equipment.h"

Equipment::Equipment()
{
    this->set("condition", QChar('a'));
    this->set("amount", 0);
}

Equipment::~Equipment()
{

}

QString Equipment::getType() {
    return this->get("type").toString();
}

int Equipment::getAmount() {
    return this->get("amount").toInt();
}

char Equipment::getCondition() {
    return this->get("condition").toChar().unicode();
}

void Equipment::setType(QString val) {
    this->set("type", val);
}

void Equipment::setAmount(int val) {
    this->set("amount", val);
}

void Equipment::setCondition(char val) {
    this->set("condition", QChar(val));
}
