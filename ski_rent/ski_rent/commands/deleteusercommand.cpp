#include "deleteusercommand.h"

DeleteUserCommand::DeleteUserCommand(int id) : BaseCommand()
{
    this->userId = id;
}

DeleteUserCommand::~DeleteUserCommand()
{

}

void DeleteUserCommand::routine() {
    UserDAO::getSingletonPtr()->remove(this->userId);
}

