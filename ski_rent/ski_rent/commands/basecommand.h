#ifndef BASECOMMAND_H
#define BASECOMMAND_H

class BaseCommand
{
public:
    void execute();

protected:
    BaseCommand();
    ~BaseCommand();

    virtual void routine() = 0;
};

#endif // BASECOMMAND_H
