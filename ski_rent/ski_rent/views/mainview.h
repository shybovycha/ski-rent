#ifndef MAINVIEW_H
#define MAINVIEW_H

#include "entities/user.h"
#include "entities/equipment.h"
#include "ui/mainwindow.h"

#include <QObject>
#include <QList>

class MainView
{
public:
    MainView();
    ~MainView();

    void setUsers(QList<User> users);
    void setEquipment(QList<Equipment> equipment);
    void show();

protected:
    MainWindow* mainWindow;
};

#endif // MAINVIEW_H
