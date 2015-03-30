#include "user.h"

User::User()
{

}

User::~User()
{

}

QString User::getName() {
    return this->get("name").toString();
}

QString User::getSurname() {
    return this->get("surname").toString();
}

QString User::getDocumentType() {
    return this->get("document_type").toString();
}

QString User::getDocumentNumber() {
    return this->get("document_number").toString();
}

QString User::getCountry() {
    return this->get("country").toString();
}

QString User::getCity() {
    return this->get("city").toString();
}

QString User::getAddress() {
    return this->get("address").toString();
}

QString User::getPhone() {
    return this->get("phone").toString();
}

void User::setName(QString val) {
    this->set("name", val);
}

void User::setSurname(QString val) {
    this->set("surname", val);
}

void User::setDocumentType(QString val) {
    this->set("document_type", val);
}

void User::setDocumentNumber(QString val) {
    this->set("document_number", val);
}

void User::setCountry(QString val) {
    this->set("country", val);
}

void User::setCity(QString val) {
    this->set("city", val);
}

void User::setAddress(QString val) {
    this->set("address", val);
}

void User::setPhone(QString val) {
    this->set("phone", val);
}

