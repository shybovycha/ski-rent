#ifndef RESERVATIONSCONTROLLER_H
#define RESERVATIONSCONTROLLER_H

#include <QObject>

#include "util/singleton.h"
#include "entities/reservation.h"
#include "dao/reservationdao.h"

class ReservationsController : public QObject
{
    Q_OBJECT

public:
    ReservationsController();
    virtual ~ReservationsController();

public slots:
    void createReservation(Reservation* newEntity);
    void updateReservation(int userId, int equipmentId, Reservation* newEntity);
    void deleteReservation(int userId, int equipmentId);
    void reservationToRent(Reservation* oldEntity);
};

typedef Singleton<ReservationsController> ReservationsControllerSingleton;

#endif // RESERVATIONSCONTROLLER_H
