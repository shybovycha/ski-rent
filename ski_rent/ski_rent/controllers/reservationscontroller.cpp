#include "reservationscontroller.h"

ReservationsController::ReservationsController() {
}

ReservationsController::~ReservationsController() {
}

void ReservationsController::createReservation(Reservation* newEntity) {
    ReservationDAOSingleton::instance()->create(newEntity);
}

void ReservationsController::updateReservation(Reservation* oldEntity, Reservation* newEntity) {
    ReservationDAOSingleton::instance()->update(oldEntity, newEntity);
}

void ReservationsController::deleteReservation(Reservation* oldEntity) {
    ReservationDAOSingleton::instance()->remove(oldEntity);
}

void ReservationsController::cancelReservation(Reservation *oldEntity) {
    ReservationDAOSingleton::instance()->remove(oldEntity);
}

void ReservationsController::reservationToRent(Reservation* oldEntity) {
    ReservationDAOSingleton::instance()->toRent(oldEntity);
}
