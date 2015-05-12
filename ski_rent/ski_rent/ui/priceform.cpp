#include "priceform.h"
#include "ui_priceform.h"

PriceForm::PriceForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PriceForm)
{
    ui->setupUi(this);

    this->price = 0;

    this->equipment = EquipmentDAOSingleton::instance()->all();

    for (int i = 0; i < equipment.size(); i++) {
        ui->equipmentTypeCombo->addItem(equipment[i]->getType());
    }

    conditions['A'] = tr("Brand new");
    conditions['B'] = tr("A bit used");
    conditions['C'] = tr("Used");
    conditions['D'] = tr("Hardly used");
    conditions['E'] = tr("Almost done");

    ui->conditionCombo->addItems(conditions.values());

    connect(ui->saveButton, SIGNAL(clicked()), this, SLOT(onSaveClicked()));
    connect(ui->cancelButton, SIGNAL(clicked()), this, SLOT(onCancelClicked()));
}

PriceForm::~PriceForm()
{
    delete ui;
}

void PriceForm::setEquipmentId(int equipmentId) {
    this->equipmentId = equipmentId;
    Equipment *tmpEquipment = EquipmentDAOSingleton::instance()->findById(equipmentId);
    ui->equipmentTypeCombo->setCurrentText(tmpEquipment->getType());
}

void PriceForm::setPrice(Price *price) {
    this->price = price;

    char conditionKey = price->getCondition();
    ui->conditionCombo->setCurrentIndex(this->conditions.keys().indexOf(conditionKey));

    ui->equipmentTypeCombo->setCurrentText(price->getType());

    ui->timeSpin->setValue(price->getTime());
    ui->priceSpin->setValue(price->getPrice());
}

void PriceForm::onCancelClicked() {
    this->close();
}

void PriceForm::onSaveClicked() {
    if (!this->price) {
        this->price = new Price();
    }

    int equipmentIndex = this->ui->equipmentTypeCombo->currentIndex();

    if (equipmentIndex < 0) {
        QMessageBox::critical(this, tr("Error"), tr("Please, select an equipment from a list or create one"));
        return;
    }

    this->price->setType(this->ui->equipmentTypeCombo->currentText());
    this->price->setTime(this->ui->timeSpin->value());
    this->price->setPrice(this->ui->priceSpin->value());

    int conditionIndex = this->ui->conditionCombo->currentIndex();
    char conditionKey = this->conditions.keys()[conditionIndex];
    this->price->setCondition(conditionKey);

    emit savePrice(this->price);
    this->close();
}
