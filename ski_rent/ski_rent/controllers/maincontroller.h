#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include "dao/equipmentdao.h"
#include "dao/userdao.h"

#include "ui/mainwindow.h"

#include "controllers/equipmentcontroller.h"
#include "controllers/userscontroller.h"

#include <QObject>
#include <QString>

class MainController : public QObject
{
    Q_OBJECT

public slots:
    void index();
    void find(QString query);
    void availableEquipment();

public:
    static MainController* getInstancePtr();

protected:
    MainController(QObject *parent = 0);
    ~MainController();

    UserDAO *userDao;
    EquipmentDAO *equipmentDao;
    MainWindow *view;
};

#endif
