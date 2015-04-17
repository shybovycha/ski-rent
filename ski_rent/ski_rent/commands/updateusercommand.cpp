#include "updateusercommand.h"

UpdateUserCommand::UpdateUserCommand(User u) : BaseCommand()
{
    this->user = u;
}

UpdateUserCommand::~UpdateUserCommand()
{

}

void UpdateUserCommand::routine() {
    UserDAO::getSingletonPtr()->update(this->user);
}
