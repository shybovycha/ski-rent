#ifndef BASEENTITY_H
#define BASEENTITY_H

#include <QMap>
#include <QString>
#include <QVariant>

class BaseEntity
{
public:
    BaseEntity();
    ~BaseEntity();

    unsigned int getId() const;
    void setId(unsigned int val);

    QVariant get(QString field) const;
    void set(QString field, QVariant value);

    bool operator=(const BaseEntity &e);

protected:
    unsigned int id;
    QMap<QString, QVariant> fields;
};

#endif // BASEENTITY_H
