#include "user.h"

User::User()
{

}

User::~User()
{

}

QString User::getName() {
    return this->name;
}

QString User::getSurname() {
    return this->surname;
}

QString User::getDocumentType() {
    return this->documentType;
}

QString User::getDocumentNumber() {
    return this->documentNumber;
}

QString User::getCountry() {
    return this->country;
}

QString User::getCity() {
    return this->city;
}

QString User::getAddress() {
    return this->address;
}

QString User::getPhone() {
    return this->phone;
}


void User::setName(QString val) {
    this->name = val;
}

void User::setSurname(QString val) {
    this->surname = val;
}

void User::setDocumentType(QString val) {
    this->documentType = val;
}

void User::setDocumentNumber(QString val) {
    this->documentNumber = val;
}

void User::setCountry(QString val) {
    this->country = val;
}

void User::setCity(QString val) {
    this->city = val;
}

void User::setAddress(QString val) {
    this->address = val;
}

void User::setPhone(QString val) {
    this->phone = val;
}

