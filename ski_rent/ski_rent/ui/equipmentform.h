#ifndef EQUIPMENTFORM_H
#define EQUIPMENTFORM_H

#include <QWidget>

namespace Ui {
class EquipmentForm;
}

class EquipmentForm : public QWidget
{
    Q_OBJECT

public:
    explicit EquipmentForm(QWidget *parent = 0);
    ~EquipmentForm();

private:
    Ui::EquipmentForm *ui;
};

#endif // EQUIPMENTFORM_H
