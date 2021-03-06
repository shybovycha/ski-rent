#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include "dao/equipmentdao.h"
#include "dao/userdao.h"
#include "dao/pricedao.h"
#include "dao/rentdao.h"
#include "dao/reservationdao.h"

#include "ui/mainwindow.h"

#include "controllers/equipmentcontroller.h"
#include "controllers/userscontroller.h"
#include "controllers/pricecontroller.h"
#include "controllers/reservationscontroller.h"
#include "controllers/rentcontroller.h"

#include "util/singleton.h"

#include <QObject>
#include <QString>

class MainController : public QObject
{
    Q_OBJECT

public:
    MainController(QObject *parent = 0);
    ~MainController();

public slots:
    void index();
    void find(QString query);
    void availableEquipment();

protected:
    MainWindow *view;
};

typedef Singleton<MainController> MainControllerSingleton;

#endif
