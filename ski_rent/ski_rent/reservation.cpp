#include "reservation.h"

Reservation::Reservation() : BaseEntity()
{

}

Reservation::~Reservation()
{

}

int Reservation::getUserId() {
    return this->get("user_id").toInt();
}

int Reservation::getEquipmentId() {
    return this->get("equipment_id").toInt();
}

int Reservation::getAmount() {
    return this->get("amount").toInt();
}

QDateTime Reservation::getRentFrom() {
    return this->get("rent_from").toDateTime();
}

QDateTime Reservation::getRentTo() {
    return this->get("rent_to").toDateTime();
}

void Reservation::setUserId(int val) {
    this->set("user_id", val);
}

void Reservation::setEquipmentId(int val) {
    this->set("equipment_id", val);
}

void Reservation::setAmount(int val) {
    this->set("amount", val);
}

void Reservation::setRentFrom(QDateTime val) {
    this->set("rent_from", val);
}

void Reservation::setRentTo(QDateTime val) {
    this->set("rent_to", val);
}

