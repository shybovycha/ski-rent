#include "userscontroller.h"

UsersController::UsersController() // QObject *parent) : QObject(parent)
{
//    this->userDao = new UserDAO();
}

UsersController::~UsersController() {
//    delete this->userDao;
}

void UsersController::createUser(User u) {
    UserDAO::getSingletonPtr()->create(u);
}

void UsersController::updateUser(User u) {
    UserDAO::getSingletonPtr()->update(u);
}

void UsersController::deleteUser(int userId) {
    UserDAO::getSingletonPtr()->remove(userId);
}

UsersController* UsersController::getSingletonPtr() {
    static UsersController* instance = 0;

    if (!instance) {
        instance = new UsersController();
    }

    return instance;
}
