#ifndef RENTDAO_H
#define RENTDAO_H

#include <QList>
#include <QString>
#include <QDateTime>
#include <QString>

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

    void create(Rent* newEntity);
    void update(Rent* oldEntity, Rent* newEntity);
    void remove(Rent* oldEntity);
    QList<Rent*> all();
    QList<Rent*> find(QString query);
    QList<Rent*> findByUser(int userId);
    QList<Rent*> findByEquipment(int equipmentId);
    QList<Rent*> findByRentFrom(QDateTime rentFrom);
    QList<Rent*> findByRentFrom(QDateTime rentFrom, QDateTime rentTo);

protected:
    RentQueryBuilder* queryBuilder;

    DatabaseAdapter* getDb();
};

typedef Singleton<RentDAO> RentDAOSingleton;

#endif // RENTDAO_H
