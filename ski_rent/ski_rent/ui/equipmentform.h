#ifndef EQUIPMENTFORM_H
#define EQUIPMENTFORM_H

#include <QWidget>

#include "entities/equipment.h"

namespace Ui {
class EquipmentForm;
}

class EquipmentForm : public QWidget
{
    Q_OBJECT

public:
    explicit EquipmentForm(QWidget *parent = 0);
    ~EquipmentForm();

    void setEquipment(Equipment* e);

public slots:
    void onCancelClicked();
    void onSaveClicked();

signals:
    void saveEquipment(Equipment* e);

private:
    Ui::EquipmentForm *ui;
    Equipment* equipment;
    QMap<char, QString> conditions;
};

#endif // EQUIPMENTFORM_H
