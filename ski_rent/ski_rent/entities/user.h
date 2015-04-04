#ifndef USER_H
#define USER_H

#include "entities/baseentity.h"

#include <QString>

class User : public BaseEntity
{
public:
    User();
    ~User();

    QString getName();
    QString getSurname();
    QString getDocumentType();
    QString getDocumentNumber();
    QString getCountry();
    QString getCity();
    QString getAddress();
    QString getPhone();

    void setName(QString val);
    void setSurname(QString val);
    void setDocumentType(QString val);
    void setDocumentNumber(QString val);
    void setCountry(QString val);
    void setCity(QString val);
    void setAddress(QString val);
    void setPhone(QString val);
};

#endif // USER_H
