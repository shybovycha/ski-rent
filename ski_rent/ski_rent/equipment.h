#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <QString>

#include "baseentity.h"

class Equipment : public BaseEntity
{
public:
    Equipment();
    ~Equipment();

    QString getType();
    int getAmount();
    char getCondition();

    void setType(QString val);
    void setAmount(int val);
    void setCondition(char val);
};

#endif // EQUIPMENT_H
