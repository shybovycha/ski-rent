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

void UsersController::deleteUser(int userId) {
    this->userDao->remove(userId);
}

UsersController* UsersController::getSingletonPtr() {
    static UsersController* instance = 0;

    if (!instance) {
        instance = new UsersController();
    }

    return instance;
}
