#include "welcomewindow.h"
#include <QApplication>

#include "userdao.h"
#include "user.h"
#include "QDebug"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    UserDAO* userDao = new UserDAO();
    QList<User> users = userDao->findUsers("artem");

    for (int i = 0; i < users.size(); i++) {
        qDebug() << QString("%1) %2 %3 from %4").arg(users[i].getId()).arg(users[i].getName(), users[i].getSurname(), users[i].getCountry());
    }

    WelcomeWindow w;
    w.show();

    return a.exec();
}
