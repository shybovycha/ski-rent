#ifndef USERSCONTROLLER_H
#define USERSCONTROLLER_H

#include "dao/userdao.h"
#include "views/userview.h"
#include "util/singleton.h"

#include <QObject>

class UsersController : public QObject
{
    Q_OBJECT

public:
    UsersController();
    ~UsersController();

signals:

public slots:
    void createUser(User u);
    void updateUser(User u);
    void deleteUser(int userId);

protected:
    // explicit UsersController(QObject *parent = 0);
};

typedef Singleton<UsersController> UsersControllerSingleton;

#endif // USERSCONTROLLER_H
