#ifndef EQUIPMENTDAO_H
#define EQUIPMENTDAO_H

#include "QList"
#include "QString"

#include "dao/basedao.h"
#include "entities/equipment.h"
#include "db/databaseadapter.h"
#include "db/databaseconnector.h"
#include "entity_converters/entityconverter.h"
#include "query_builders/querybuilder.h"

class EquipmentDAO : public BaseDAO<Equipment>
{
public:
    EquipmentDAO();
    ~EquipmentDAO();

    QList<Equipment> available();
};

#endif // EQUIPMENTDAO_H
