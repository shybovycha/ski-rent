#ifndef CREATEUSERCOMMAND_H
#define CREATEUSERCOMMAND_H

#include "commands/basecommand.h"
#include "entities/user.h"
#include "dao/userdao.h"

class CreateUserCommand : public BaseCommand {
public:
    CreateUserCommand(User u);
    ~CreateUserCommand();

protected:
    void routine();

    User user;
};

#endif
