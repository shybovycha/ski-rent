#include "updateequipmentcommand.h"

UpdateEquipmentCommand::UpdateEquipmentCommand(Equipment e) : BaseCommand()
{
    this->equipment = e;
}

UpdateEquipmentCommand::~UpdateEquipmentCommand()
{

}

void UpdateEquipmentCommand::routine() {
    EquipmentDAO::getSingletonPtr()->update(this->equipment);
}
