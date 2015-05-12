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

void ReservationsController::deleteReservation(int userId, int equipmentId) {
    ReservationDAOSingleton::instance()->remove(userId, equipmentId);
}

void ReservationsController::cancelReservation(Reservation *oldEntry) {
    ReservationDAOSingleton::instance()->remove(oldEntry->getUserId(), oldEntry->getEquipmentId());
}

void ReservationsController::reservationToRent(Reservation* oldEntity) {
    ReservationDAOSingleton::instance()->toRent(oldEntity);
}
