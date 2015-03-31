#ifndef RESERVATIONDAO_H
#define RESERVATIONDAO_H

#include <QList>
#include <QDateTime>

#include "reservation.h"
#include "databaseadapter.h"
#include "databaseconnector.h"
#include "reservationquerybuilder.h"
#include "entityconverter.h"

class ReservationDAO
{
public:
    ReservationDAO();
    ~ReservationDAO();

    QList<Reservation> all();
    QList<Reservation> findByUser(int userId);
    QList<Reservation> findByEquipment(int equipmentId);
    QList<Reservation> findByRentDate(QDateTime dateFrom, QDateTime dateTo);
    void create(Reservation newEntity);
    void remove(int userId, int equipmentId);
    void update(int userId, int equipmentId, Reservation newEntity);

protected:
    ReservationQueryBuilder* queryBuilder;

    DatabaseAdapter* getDb();
};

#endif // RESERVATIONDAO_H
