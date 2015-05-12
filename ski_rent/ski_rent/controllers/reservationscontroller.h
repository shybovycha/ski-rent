#ifndef RESERVATIONSCONTROLLER_H
#define RESERVATIONSCONTROLLER_H

#include <QObject>

#include "util/singleton.h"
#include "entities/reservation.h"
#include "dao/reservationdao.h"

class ReservationsController
{
public:
    ReservationsController();
    ~ReservationsController();

public slots:
    void createReservation(Reservation* newEntity);
    void updateReservation(int userId, int equipmentId, Reservation* newEntity);
    void removeReservation(int userId, int equipmentId);
};

#endif // RESERVATIONSCONTROLLER_H
