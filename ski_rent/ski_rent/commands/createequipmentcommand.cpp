#include "createequipmentcommand.h"

CreateEquipmentCommand::CreateEquipmentCommand(Equipment e) : BaseCommand()
{
    this->equipment = e;
}

CreateEquipmentCommand::~CreateEquipmentCommand()
{

}

void CreateEquipmentCommand::routine() {
    EquipmentDAO::getSingletonPtr()->create(this->equipment);
}
