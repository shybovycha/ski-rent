#include "controllers/equipmentcontroller.h"

EquipmentController::EquipmentController() //QObject *parent) : QObject(parent)
{
    this->equipmentDao = new EquipmentDAO();
}

EquipmentController::~EquipmentController()
{
    delete this->equipmentDao;
}

void EquipmentController::createEquipment(Equipment e) {
    this->equipmentDao->create(e);
}

void EquipmentController::updateEquipment(Equipment e) {
    this->equipmentDao->update(e);
}

void EquipmentController::deleteEquipment(int id) {
    this->equipmentDao->remove(id);
}

EquipmentController* EquipmentController::getSingletonPtr() {
    static EquipmentController* instance;

    if (!instance) {
        instance = new EquipmentController();
    }

    return instance;
}
