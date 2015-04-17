#ifndef DELETEEQUIPMENTCOMMAND_H
#define DELETEEQUIPMENTCOMMAND_H

#include "commands/basecommand.h"
#include "dao/equipmentdao.h"

class DeleteEquipmentCommand : public BaseCommand
{
public:
    DeleteEquipmentCommand(int id);
    ~DeleteEquipmentCommand();

protected:
    void routine();

    int equipmentId;
};

#endif // DELETEEQUIPMENTCOMMAND_H
