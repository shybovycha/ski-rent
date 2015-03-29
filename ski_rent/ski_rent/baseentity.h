#ifndef BASEENTITY_H
#define BASEENTITY_H


class BaseEntity
{
public:
    BaseEntity();
    ~BaseEntity();

    unsigned int getId();
    void setId(unsigned int val);

protected:
    unsigned int id;
};

#endif // BASEENTITY_H
