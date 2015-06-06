#include "rentform.h"
#include "ui_rentform.h"

RentForm::RentForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RentForm)
{
    ui->setupUi(this);

    this->oldRent = 0;
    this->newRent = 0;

    this->equipment = EquipmentDAOSingleton::instance()->all();

    for (int i = 0; i < equipment.size(); i++) {
        ui->equipmentTypeCombo->addItem(equipment[i]->getType());
    }

    conditions['A'] = tr("Brand new");
    conditions['B'] = tr("A bit used");
    conditions['C'] = tr("Used");
    conditions['D'] = tr("Hardly used");
    conditions['E'] = tr("Almost done");

    ui->equipmentConditionCombo->addItems(conditions.values());

    connect(ui->saveButton, SIGNAL(clicked()), this, SLOT(onSaveClicked()));
    connect(ui->cancelButton, SIGNAL(clicked()), this, SLOT(onCancelClicked()));

    connect(ui->amountSpin, SIGNAL(valueChanged(int)), this, SLOT(recalculatePricePerHour()));
    connect(ui->equipmentConditionCombo, SIGNAL(currentIndexChanged(int)), this, SLOT(recalculatePricePerHour()));
    connect(ui->equipmentTypeCombo, SIGNAL(currentIndexChanged(int)), this, SLOT(recalculatePricePerHour()));
}

RentForm::~RentForm()
{
    delete ui;
}

void RentForm::recalculatePricePerHour() {
    QString type = ui->equipmentTypeCombo->currentText();
    int conditionIndex = this->ui->equipmentConditionCombo->currentIndex();
    char condition = this->conditions.keys()[conditionIndex];
    int amount = this->ui->amountSpin->value();
    float price = PriceDAOSingleton::instance()->getPriceTotal(type, condition, 1, amount);

    ui->pricePerHourLcd->display(QString::number(price));
}

void RentForm::setRent(Rent *rent) {
    Equipment* tmpEquipment = EquipmentDAOSingleton::instance()->findById(rent->getEquipmentId());

    this->oldRent = rent;

    this->newRent = new Rent();
    this->newRent->setAmount(rent->getAmount());
    this->newRent->setEquipmentId(rent->getEquipmentId());
    this->newRent->setRentFrom(rent->getRentFrom());
    this->newRent->setUserId(rent->getUserId());

    this->userId = rent->getUserId();

    char conditionKey = tmpEquipment->getCondition();
    ui->equipmentConditionCombo->setCurrentIndex(this->conditions.keys().indexOf(conditionKey));

    ui->equipmentTypeCombo->setCurrentText(tmpEquipment->getType());

    ui->amountSpin->setValue(rent->getAmount());
}

void RentForm::setUserId(int userId) {
    this->userId = userId;
}

void RentForm::onCancelClicked() {
    this->close();
}

void RentForm::onSaveClicked() {
    if (!this->newRent) {
        this->newRent = new Rent();
        this->newRent->setRentFrom(QDateTime::currentDateTime());
    }

    int equipmentIndex = this->ui->equipmentConditionCombo->currentIndex();

    if (equipmentIndex < 0) {
        QMessageBox::critical(this, tr("Error"), tr("Please, select an equipment from a list or create one"));
        return;
    }

    this->newRent->setEquipmentId(this->equipment[equipmentIndex]->getId());
    this->newRent->setAmount(this->ui->amountSpin->value());
    this->newRent->setUserId(this->userId);

    emit saveRent(this->oldRent, this->newRent);
    this->close();
}
