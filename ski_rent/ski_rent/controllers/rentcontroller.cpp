#include "rentcontroller.h"

RentController::RentController() {
}

RentController::~RentController() {
}

void RentController::createRent(Rent* e) {
    RentDAOSingleton::instance()->create(e);
}

void RentController::updateRent(Rent* oldRent, Rent* newRent) {
    RentDAOSingleton::instance()->update(oldRent, newRent);
}

void RentController::deleteRent(Rent* oldRent) {
    RentDAOSingleton::instance()->remove(oldRent);
}

void RentController::returnFromRent(Rent *e) {
    QDateTime now = QDateTime::currentDateTime();
    int time = e->getRentFrom().msecsTo(now) / (1000 * 60 * 60); // hours
    User *user = UserDAOSingleton::instance()->findById(e->getUserId());
    Equipment *equipment = EquipmentDAOSingleton::instance()->findById(e->getEquipmentId());
    Price *price = PriceDAOSingleton::instance()->find(equipment->getType(), equipment->getCondition(), time)[0];

    HistoryDAOSingleton::instance()->create(user, equipment, e, now, price);
    RentDAOSingleton::instance()->remove(e);
}

QList<History*> RentController::returnFromRent(QList<Rent*> entries) {
    QDateTime now = QDateTime::currentDateTime();
    QList<History*> results;

    for (int i = 0; i < entries.size(); i++) {
        Rent* e = entries.at(i);
        int time = abs(e->getRentFrom().msecsTo(now));
        time /= (1000 * 60 * 60); // hours
        User *user = UserDAOSingleton::instance()->findById(e->getUserId());
        Equipment *equipment = EquipmentDAOSingleton::instance()->findById(e->getEquipmentId());
        Price *price = PriceDAOSingleton::instance()->find(equipment->getType(), equipment->getCondition(), time)[0];

        HistoryDAOSingleton::instance()->create(user, equipment, e, now, price);
        RentDAOSingleton::instance()->remove(e);

        History* resultRow = new History();
        resultRow->setAmount(e->getAmount());
        resultRow->setType(equipment->getType());
        resultRow->setCondition(equipment->getCondition());
        resultRow->setPrice(price->getPrice());
        resultRow->setRentFrom(e->getRentFrom());
        resultRow->setRentTo(now);

        results.append(resultRow);
    }

    return results;
}
