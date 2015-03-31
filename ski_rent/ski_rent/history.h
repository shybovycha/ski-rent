#ifndef HISTORY_H
#define HISTORY_H

#include "baseentity.h"
#include <QDateTime>
#include <QString>

class History : public BaseEntity
{
public:
    History();
    ~History();

    QString getName();
    QString getSurname();
    QString getDocumentType();
    QString getDocumentNumber();
    QString getCountry();
    QString getCity();
    QString getAddress();
    QString getPhone();

    QString getType();
    int getAmount();
    char getCondition();

    QDateTime getRentFrom();
    QDateTime getRentTo();

    float getPrice();

    void setPrice(float val);

    void setRentFrom(QDateTime val);
    void setRentTo(QDateTime val);

    void setType(QString val);
    void setAmount(int val);
    void setCondition(char val);

    void setName(QString val);
    void setSurname(QString val);
    void setDocumentType(QString val);
    void setDocumentNumber(QString val);
    void setCountry(QString val);
    void setCity(QString val);
    void setAddress(QString val);
    void setPhone(QString val);
};

#endif // HISTORY_H
