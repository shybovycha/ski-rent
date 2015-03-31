#ifndef RENT_H
#define RENT_H

#include "baseentity.h"

#include <QDateTime>

class Rent : public BaseEntity
{
public:
    Rent();
    ~Rent();

    int getUserId();
    int getEquipmentId();
    int getAmount();
    QDateTime getRentFrom();

    void setUserId(int val);
    void setEquipmentId(int val);
    void setAmount(int val);
    void setRentFrom(QDateTime val);
};

#endif // RENT_H
