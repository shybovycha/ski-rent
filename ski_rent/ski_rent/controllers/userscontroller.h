#ifndef USERSCONTROLLER_H
#define USERSCONTROLLER_H

#include "dao/userdao.h"

#include "views/userview.h"

#include <QObject>

class UsersController : public QObject
{
    Q_OBJECT

public:
    // explicit UsersController(QObject *parent = 0);
    UsersController();
    ~UsersController();

signals:

public slots:
    void createUser(User u);
    void updateUser(User u);

protected:
    UserDAO *userDao;
};

#endif // USERSCONTROLLER_H
