#ifndef EQUIPMENTVIEW_H
#define EQUIPMENTVIEW_H

#include "entities/equipment.h"
#include "ui/equipmentform.h"

#include <QObject>

class EquipmentView : public QObject
{
    Q_OBJECT

public:
    EquipmentView();
    ~EquipmentView();

    void edit(Equipment equipment);
    void create();

signals:
    void saveEquipment(Equipment equipment);

protected:
    Equipment getEquipment();

    EquipmentForm* equipmentForm;
};

#endif // EQUIPMENTVIEW_H
