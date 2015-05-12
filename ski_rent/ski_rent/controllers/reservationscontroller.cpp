#include "reservationscontroller.h"

ReservationsController::ReservationsController() {
}

ReservationsController::~ReservationsController() {
}

void ReservationsController::createReservation(Reservation* newEntity) {
    ReservationDAOSingleton::instance()->create(newEntity);
}

void ReservationsController::updateReservation(int userId, int equipmentId, Reservation* newEntity) {
    ReservationDAOSingleton::instance()->update(userId, equipmentId, newEntity);
}

void ReservationsController::removeReservation(int userId, int equipmentId) {
    ReservationDAOSingleton::instance()->remove(userId, equipmentId);
}
