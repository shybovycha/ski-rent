#include "history.h"

History::History() {

}

History::~History() {

}

QString History::getName() {
    return this->get("name").toString();
}

QString History::getSurname() {
    return this->get("surname").toString();
}

QString History::getDocumentType() {
    return this->get("document_type").toString();
}

QString History::getDocumentNumber() {
    return this->get("document_number").toString();
}

QString History::getCountry() {
    return this->get("country").toString();
}

QString History::getCity() {
    return this->get("city").toString();
}

QString History::getAddress() {
    return this->get("address").toString();
}

QString History::getPhone() {
    return this->get("phone").toString();
}


QString History::getType() {
    return this->get("type").toString();
}

int History::getAmount() {
    return this->get("amount").toInt();
}

char History::getCondition() {
    return this->get("condition").toChar().unicode();
}


QDateTime History::getRentFrom() {
    return this->get("rent_from").toDateTime();
}

QDateTime History::getRentTo() {
    return this->get("rent_to").toDateTime();
}

float History::getPrice() {
    return this->get("price").toFloat();
}

void History::setPrice(float val) {
    this->set("price", val);
}

void History::setRentFrom(QDateTime val) {
    this->set("rent_from", val);
}

void History::setRentTo(QDateTime val) {
    this->set("rent_to", val);
}


void History::setType(QString val) {
    this->set("type", val);
}

void History::setAmount(int val) {
    this->set("amount", val);
}

void History::setCondition(char val) {
    this->set("condition", val);
}


void History::setName(QString val) {
    this->set("name", val);
}

void History::setSurname(QString val) {
    this->set("surname", val);
}

void History::setDocumentType(QString val) {
    this->set("document_type", val);
}

void History::setDocumentNumber(QString val) {
    this->set("document_number", val);
}

void History::setCountry(QString val) {
    this->set("country", val);
}

void History::setCity(QString val) {
    this->set("city", val);
}

void History::setAddress(QString val) {
    this->set("address", val);
}

void History::setPhone(QString val) {
    this->set("phone", val);
}

