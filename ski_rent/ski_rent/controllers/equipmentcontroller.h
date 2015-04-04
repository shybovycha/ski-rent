#ifndef EQUIPMENTCONTROLLER_H
#define EQUIPMENTCONTROLLER_H

#include "dao/equipmentdao.h"

#include "views/equipmentview.h"

#include <QObject>

class EquipmentController : public QObject
{
    Q_OBJECT

public:
//    explicit EquipmentController(QObject *parent = 0);
    EquipmentController();
    ~EquipmentController();

signals:

public slots:
    void createEquipment(Equipment e);
    void updateEquipment(Equipment e);

protected:
    EquipmentDAO *equipmentDao;
};

#endif // EQUIPMENTCONTROLLER_H
