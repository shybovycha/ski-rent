#ifndef PRICE
#define PRICE

#include "entities/baseentity.h"

#include <QString>

class Price
{
public:
    Price();
    ~Price();

    int getTime();
    char getCondition();
    QString getType();
    float getPrice();

    void setTime(int val);
    void setCondition(char val);
    void setType(QString val);
    void setPrice(float val);

protected:
    QVariant get(QString field);
    void set(QString field, QVariant value);

    QMap<QString, QVariant> fields;
};

#endif // PRICE

