#include "userscontroller.h"

UsersController::UsersController() {
}

UsersController::~UsersController() {
}

void UsersController::createUser(User u) {
    UserDAOSingleton::instance()->create(u);
}

void UsersController::updateUser(User u) {
    UserDAOSingleton::instance()->update(u);
}

void UsersController::deleteUser(int userId) {
    UserDAOSingleton::instance()->remove(userId);
}
