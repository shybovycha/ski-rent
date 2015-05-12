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

void RentController::returnFromRent(Rent *e) {
    QDateTime now = QDateTime::currentDateTime();
    int time = e->getRentFrom().msecsTo(now) / (1000 * 60 * 60); // hours
    User *user = UserDAOSingleton::instance()->findById(e->getUserId());
    Equipment *equipment = EquipmentDAOSingleton::instance()->findById(e->getEquipmentId());
    Price *price = PriceDAOSingleton::instance()->find(equipment->getType(), equipment->getCondition(), time)[0]; // TODO: REWORK!!!

    HistoryDAOSingleton::instance()->create(user, equipment, e, now, price);
    RentDAOSingleton::instance()->remove(e->getUserId(), e->getEquipmentId());
}
