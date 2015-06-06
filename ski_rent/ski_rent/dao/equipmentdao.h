#ifndef EQUIPMENTDAO_H
#define EQUIPMENTDAO_H

#include "QList"
#include "QString"

#include "entities/equipment.h"
#include "db/databaseadapter.h"
#include "db/databaseconnector.h"
#include "entity_converters/entityconverter.h"
#include "query_builders/equipmentquerybuilder.h"
#include "util/singleton.h"

class EquipmentDAO
{
public:
    EquipmentDAO();
    ~EquipmentDAO();

    QList<Equipment*> all();
    Equipment* findById(int id);
    QList<Equipment*> find(QString query);
    void create(Equipment* entity);
    void update(Equipment* entity);
    void remove(int id);

    QList<Equipment*> available();
    QList<Equipment*> availableForUsage();

protected:
    EquipmentQueryBuilder *queryBuilder;
    DatabaseAdapter* getDb();
};

typedef Singleton<EquipmentDAO> EquipmentDAOSingleton;

#endif // EQUIPMENTDAO_H
