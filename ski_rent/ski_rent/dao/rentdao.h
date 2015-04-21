#ifndef RENTDAO_H
#define RENTDAO_H

#include <QList>
#include <QString>
#include <QDateTime>

#include "entities/rent.h"
#include "dao/basedao.h"
#include "db/databaseadapter.h"
#include "db/databaseconnector.h"
#include "entity_converters/entityconverter.h"
#include "query_builders/querybuilder.h"
#include "query_builders/rentquerybuilder.h"
#include "util/singleton.h"

class RentDAO
{
public:
    RentDAO();
    ~RentDAO();

    void create(int userId, int equipmentId, Rent newEntity);
    void update(int userId, int equipmentId, Rent newEntity);
    void remove(int userId, int equipmentId);
    QList<Rent> findByUser(int userId);
    QList<Rent> findByEquipment(int equipmentId);
    QList<Rent> findByRentFrom(QDateTime rentFrom);
    QList<Rent> findByRentFrom(QDateTime rentFromStart, QDateTime rentFromEnd);

protected:
    RentQueryBuilder* queryBuilder;

    DatabaseAdapter* getDb();
};

typedef Singleton<RentDAO> RentDAOSingleton;

#endif // RENTDAO_H
