#ifndef EQUIPMENTDAO_H
#define EQUIPMENTDAO_H

#include "QList"
#include "QString"

#include "equipment.h"
#include "basedao.h"
#include "databaseadapter.h"
#include "databaseconnector.h"
#include "entityconverter.h"
#include "querybuilder.h"
#include "querybuilder.h"

class EquipmentDAO : public BaseDAO<Equipment>
{
public:
    EquipmentDAO();
    ~EquipmentDAO();

    QList<Equipment> available();
};

#endif // EQUIPMENTDAO_H
