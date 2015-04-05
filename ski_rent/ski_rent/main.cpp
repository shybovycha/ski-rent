#include <QApplication>

#include "controllers/maincontroller.h"

#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainController::getInstancePtr()->index();

    return a.exec();
}
