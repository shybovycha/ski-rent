#ifndef USERVIEW_H
#define USERVIEW_H

#include "entities/user.h"
#include "ui/userform.h"

#include <QObject>

class UserView : public QObject
{
    Q_OBJECT

public:
    UserView();
    ~UserView();

    void edit(User user);
    void create();

signals:
    void saveUser(User user);

protected:
    User getUser();

    UserForm* userForm;
};


#endif // USERVIEW_H
