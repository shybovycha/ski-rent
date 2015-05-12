#include "equipmentform.h"
#include "ui_equipmentform.h"

EquipmentForm::EquipmentForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EquipmentForm)
{
    ui->setupUi(this);

    this->equipment = 0;

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

void EquipmentForm::setEquipment(Equipment* e) {
    this->equipment = e;

    this->ui->typeEdit->setText(e->getType());
    this->ui->amountSpin->setValue(e->getAmount());
    char conditionKey = e->getCondition();
    this->ui->conditionCombo->setCurrentIndex(this->conditions.keys().indexOf(conditionKey));
}

void EquipmentForm::onCancelClicked() {
    this->close();
}

void EquipmentForm::onSaveClicked() {
    if (!this->equipment) {
        this->equipment = new Equipment();
    }

    this->equipment->setType(this->ui->typeEdit->text());
    this->equipment->setAmount(this->ui->amountSpin->value());

    int conditionIndex = this->ui->conditionCombo->currentIndex();
    char conditionKey = this->conditions.keys()[conditionIndex];
    this->equipment->setCondition(conditionKey);

    emit saveEquipment(this->equipment);

    this->close();
}
