#include "deleteequipmentcommand.h"

DeleteEquipmentCommand::DeleteEquipmentCommand(int id) : BaseCommand()
{
    this->equipmentId = id;
}

DeleteEquipmentCommand::~DeleteEquipmentCommand()
{

}

void DeleteEquipmentCommand::routine() {
    EquipmentDAO::getSingletonPtr()->remove(this->equipmentId);
}
