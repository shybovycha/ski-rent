#ifndef UPDATEUSERCOMMAND_H
#define UPDATEUSERCOMMAND_H

#include "commands/basecommand.h"
#include "dao/userdao.h"

class UpdateUserCommand : public BaseCommand
{
public:
    UpdateUserCommand(User u);
    ~UpdateUserCommand();

protected:
    void routine();

    User user;
};

#endif // UPDATEUSERCOMMAND_H
