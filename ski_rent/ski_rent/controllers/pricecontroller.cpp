#include "pricecontroller.h"

PriceController::PriceController() {
}


PriceController::~PriceController() {
}

void PriceController::createPrice(Price* newEntity) {
    PriceDAOSingleton::instance()->create(newEntity);
}

void PriceController::updatePrice(QString type, char condition, int time, Price* newEntity) {
    PriceDAOSingleton::instance()->update(type, condition, time, newEntity);
}

void PriceController::deletePrice(QString type, char condition, int time) {
    PriceDAOSingleton::instance()->remove(type, condition, time);
}
