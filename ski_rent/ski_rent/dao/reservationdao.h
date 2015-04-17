#ifndef RESERVATIONDAO_H
#define RESERVATIONDAO_H

#include <QList>
#include <QDateTime>

#include "entities/reservation.h"
#include "db/databaseadapter.h"
#include "db/databaseconnector.h"
#include "query_builders/reservationquerybuilder.h"
#include "entity_converters/entityconverter.h"

class ReservationDAO
{
public:
    static ReservationDAO* getSingletonPtr();

    QList<Reservation> all();
    QList<Reservation> findByUser(int userId);
    QList<Reservation> findByEquipment(int equipmentId);
    QList<Reservation> findByRentDate(QDateTime dateFrom, QDateTime dateTo);
    void create(Reservation newEntity);
    void remove(int userId, int equipmentId);
    void update(int userId, int equipmentId, Reservation newEntity);

protected:
    ReservationDAO();
    ~ReservationDAO();

    ReservationQueryBuilder* queryBuilder;

    DatabaseAdapter* getDb();
};

#endif // RESERVATIONDAO_H
