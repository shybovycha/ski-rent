#include <QApplication>

#include "controllers/maincontroller.h"

#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainControllerSingleton::instance()->index();

    return a.exec();
}
