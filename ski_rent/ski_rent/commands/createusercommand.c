#include "createusercommand.h"

CreateUserCommand::CreateUserCommand(User u) : BaseCommand()
{
    this->user = u;
}

CreateUserCommand::~CreateUserCommand()
{

}

void CreateUserCommand::routine() {
    UserDAO::getSingletonPtr()->create(this->user);
}
