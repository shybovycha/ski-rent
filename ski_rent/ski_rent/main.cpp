#include <QApplication>

#include "ui/welcomewindow.h"
#include "dao/userdao.h"
#include "entities/user.h"

#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    UserDAO* userDao = new UserDAO();

    /*User* user1 = new User();
    user1->setName("Oksana");
    user1->setSurname("Tunik");
    user1->setCity("Polska");
    userDao->create(*user1);*/

    QList<User> users = userDao->all();

    for (int i = 0; i < users.size(); i++) {
        qDebug() << QString("%1) %2 %3 from %4").arg(users[i].getId()).arg(users[i].getName(), users[i].getSurname(), users[i].getCountry());
    }

    WelcomeWindow w;
    w.show();

    return a.exec();
}
