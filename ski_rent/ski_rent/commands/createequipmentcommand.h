#ifndef CREATEEQUIPMENTCOMMAND_H
#define CREATEEQUIPMENTCOMMAND_H

#include "commands/basecommand.h"
#include "dao/equipmentdao.h"

class CreateEquipmentCommand : public BaseCommand
{
public:
    CreateEquipmentCommand(Equipment e);
    ~CreateEquipmentCommand();

protected:
    void routine();

    Equipment equipment;
};

#endif // CREATEEQUIPMENTCOMMAND_H
