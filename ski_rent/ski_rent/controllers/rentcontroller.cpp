#include "rentcontroller.h"

RentController::RentController() {
}

RentController::~RentController() {
}

void RentController::createRent(Rent* e) {
    RentDAOSingleton::instance()->create(e);
}

void RentController::updateRent(int userId, int equipmentId, Rent* e) {
    RentDAOSingleton::instance()->update(userId, equipmentId, e);
}

void RentController::deleteRent(int userId, int equipmentId) {
    RentDAOSingleton::instance()->remove(userId, equipmentId);
}
