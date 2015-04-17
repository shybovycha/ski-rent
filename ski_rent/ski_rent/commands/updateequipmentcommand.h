#ifndef UPDATEEQUIPMENTCOMMAND_H
#define UPDATEEQUIPMENTCOMMAND_H

#include "commands/basecommand.h"
#include "dao/equipmentdao.h"

class UpdateEquipmentCommand : public BaseCommand
{
public:
    UpdateEquipmentCommand(Equipment e);
    ~UpdateEquipmentCommand();

protected:
    void routine();

    Equipment equipment;
};

#endif // UPDATEEQUIPMENTCOMMAND_H
