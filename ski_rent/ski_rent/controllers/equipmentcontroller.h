#ifndef EQUIPMENTCONTROLLER_H
#define EQUIPMENTCONTROLLER_H

#include "dao/equipmentdao.h"
#include "views/equipmentview.h"
#include "util/singleton.h"

#include <QObject>

class EquipmentController : public QObject
{
    Q_OBJECT

public:
    EquipmentController();
    ~EquipmentController();

public slots:
    void createEquipment(Equipment* e);
    void updateEquipment(Equipment* e);
    void deleteEquipment(int id);
};

typedef Singleton<EquipmentController> EquipmentControllerSingleton;

#endif // EQUIPMENTCONTROLLER_H
