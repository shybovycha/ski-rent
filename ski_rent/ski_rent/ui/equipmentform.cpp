#include "equipmentform.h"
#include "ui_equipmentform.h"

EquipmentForm::EquipmentForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EquipmentForm)
{
    ui->setupUi(this);

    conditions['A'] = tr("Brand new");
    conditions['B'] = tr("A bit used");
    conditions['C'] = tr("Used");
    conditions['D'] = tr("Hardly used");
    conditions['E'] = tr("Almost done");

    ui->conditionCombo->addItems(conditions.values());

    connect(ui->saveButton, SIGNAL(clicked()), this, SLOT(onSaveClicked()));
    connect(ui->cancelButton, SIGNAL(clicked()), this, SLOT(onCancelClicked()));
}

EquipmentForm::~EquipmentForm()
{
    delete ui;
}

void EquipmentForm::setEquipment(Equipment e) {
    this->equipment = e;

    this->ui->typeEdit->setText(e.getType());
    this->ui->amountSpin->setValue(e.getAmount());
    this->ui->conditionCombo->setCurrentIndex(this->conditions.keys().indexOf(e.getCondition()));
}

void EquipmentForm::onCancelClicked() {
    this->close();
}

void EquipmentForm::onSaveClicked() {
    this->equipment.setType(this->ui->typeEdit->text());
    this->equipment.setAmount(this->ui->amountSpin->value());
    this->equipment.setCondition(this->conditions.keys()[this->ui->conditionCombo->currentIndex()]);

    emit saveEquipment(this->equipment);

    this->close();
}
