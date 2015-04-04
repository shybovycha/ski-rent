#include "equipmentform.h"
#include "ui_equipmentform.h"

EquipmentForm::EquipmentForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EquipmentForm)
{
    ui->setupUi(this);
}

EquipmentForm::~EquipmentForm()
{
    delete ui;
}
