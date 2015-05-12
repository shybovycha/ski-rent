#ifndef RESERVATIONDAO_H
#define RESERVATIONDAO_H

#include <QList>
#include <QDateTime>

#include "entities/reservation.h"
#include "db/databaseadapter.h"
#include "db/databaseconnector.h"
#include "query_builders/reservationquerybuilder.h"
#include "entity_converters/entityconverter.h"
#include "util/singleton.h"

class ReservationDAO
{
public:
    ReservationDAO();
    ~ReservationDAO();

    QList<Reservation*> all();
    QList<Reservation*> find(QString query);
    QList<Reservation*> findByUser(int userId);
    QList<Reservation*> findByEquipment(int equipmentId);
    QList<Reservation*> findByRentDate(QDateTime dateFrom, QDateTime dateTo);
    void create(Reservation* newEntity);
    void remove(int userId, int equipmentId);
    void update(int userId, int equipmentId, Reservation* newEntity);
    void toRent(Reservation* oldEntity);

protected:
    ReservationQueryBuilder* queryBuilder;

    DatabaseAdapter* getDb();
};

typedef Singleton<ReservationDAO> ReservationDAOSingleton;

#endif // RESERVATIONDAO_H
