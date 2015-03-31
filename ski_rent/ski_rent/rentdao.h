#ifndef RENTDAO_H
#define RENTDAO_H

#include <QList>
#include <QString>
#include <QDateTime>

#include "rent.h"
#include "basedao.h"
#include "databaseadapter.h"
#include "databaseconnector.h"
#include "entityconverter.h"
#include "querybuilder.h"
#include "rentquerybuilder.h"

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

#endif // RENTDAO_H
