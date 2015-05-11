#ifndef RENTCONTROLLER_H
#define RENTCONTROLLER_H

#include <QObject>
#include "entities/rent.h"
#include "dao/rentdao.h"
#include "util/singleton.h"

class RentController : public QObject
{
    Q_OBJECT

public:
    RentController();
    ~RentController();

public slots:
    void createRent(int userId, int equipmentId, Rent* e);
    void updateRent(int userId, int equipmentId, Rent* e);
    void deleteRent(int userId, int equipmentId);
};

typedef Singleton<RentController> RentControllerSingleton;

#endif // RENTCONTROLLER_H
