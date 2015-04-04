#include "userscontroller.h"

UsersController::UsersController() // QObject *parent) : QObject(parent)
{
    this->userDao = new UserDAO();
}

UsersController::~UsersController() {
    delete this->userDao;
}

void UsersController::createUser(User u) {
    this->userDao->create(u);
}

void UsersController::updateUser(User u) {
    this->userDao->update(u);
}
