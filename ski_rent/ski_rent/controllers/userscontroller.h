#ifndef USERSCONTROLLER_H
#define USERSCONTROLLER_H

#include "dao/userdao.h"

#include "views/userview.h"

#include <QObject>

class UsersController : public QObject
{
    Q_OBJECT

public:
    static UsersController* getSingletonPtr();

signals:

public slots:
    void createUser(User u);
    void updateUser(User u);
    void deleteUser(int userId);

protected:
    // explicit UsersController(QObject *parent = 0);
    UsersController();
    ~UsersController();

    UserDAO *userDao;
};

#endif // USERSCONTROLLER_H
