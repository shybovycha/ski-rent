#ifndef DELETEUSERCOMMAND_H
#define DELETEUSERCOMMAND_H

#include "commands/basecommand.h"
#include "dao/userdao.h"

class DeleteUserCommand : public BaseCommand
{
public:
    DeleteUserCommand(int id);
    ~DeleteUserCommand();

protected:
    void routine();

    int userId;
};

#endif // DELETEUSERCOMMAND_H
