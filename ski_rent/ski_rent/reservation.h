#ifndef RESERVATION_H
#define RESERVATION_H

#include "baseentity.h"

#include <QString>
#include <QDateTime>

class Reservation : public BaseEntity
{
public:
    Reservation();
    ~Reservation();

    int getUserId();
    int getEquipmentId();
    int getAmount();
    QDateTime getRentFrom();
    QDateTime getRentTo();

    void setUserId(int val);
    void setEquipmentId(int val);
    void setAmount(int val);
    void setRentFrom(QDateTime val);
    void setRentTo(QDateTime val);
};

#endif // RESERVATION_H
