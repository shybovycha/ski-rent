#include "rent.h"

Rent::Rent() : BaseEntity()
{
    this->set("amount", 0);
    // this->set("rent_from", QDateTime::g)
}

Rent::~Rent()
{

}

int Rent::getUserId() {
    return this->get("user_id").toInt();
}

int Rent::getEquipmentId() {
    return this->get("equipment_id").toInt();
}

int Rent::getAmount() {
    return this->get("amount").toInt();
}

QDateTime Rent::getRentFrom() {
    return this->get("rentf_rom").toDateTime();
}


void Rent::setUserId(int val) {
    this->set("user_id", val);
}

void Rent::setEquipmentId(int val) {
    this->set("equipment_id", val);
}

void Rent::setAmount(int val) {
    this->set("amount", val);
}

void Rent::setRentFrom(QDateTime val) {
    this->set("rent_from", val);
}


