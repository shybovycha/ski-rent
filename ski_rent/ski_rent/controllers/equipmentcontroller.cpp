#include "controllers/equipmentcontroller.h"

EquipmentController::EquipmentController() {
}

EquipmentController::~EquipmentController() {
}

void EquipmentController::createEquipment(Equipment* e) {
    EquipmentDAOSingleton::instance()->create(e);
}

void EquipmentController::updateEquipment(Equipment* e) {
    EquipmentDAOSingleton::instance()->update(e);
}

void EquipmentController::deleteEquipment(int id) {
    EquipmentDAOSingleton::instance()->remove(id);
}
