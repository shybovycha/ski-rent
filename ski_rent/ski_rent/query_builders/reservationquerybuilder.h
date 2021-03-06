#ifndef RESERVATIONQUERYBUILDER_H
#define RESERVATIONQUERYBUILDER_H

#include "entities/reservation.h"

#include <QString>
#include <QStringList>
#include <QDateTime>

class ReservationQueryBuilder
{
public:
    ReservationQueryBuilder();
    ~ReservationQueryBuilder();

    QString getListAllQuery();
    QString getToRentQuery(Reservation* oldEntity);
    QString getCreateQuery(Reservation* newEntity);
    QString getRemoveQuery(Reservation* oldEntity);
    QString getSearchQuery(QString query);
    QString getFindByUserQuery(int userId);
    QString getFindByEquipmentQuery(int equipmentId);
    QString getFindByRentDateQuery(QDateTime dateFrom, QDateTime dateTo);
    QString getUpdateQuery(Reservation* oldEntity, Reservation* newEntity);

protected:
    QString tableName;
};

#endif // RESERVATIONQUERYBUILDER_H
