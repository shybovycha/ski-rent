#include "rentform.h"
#include "ui_rentform.h"

RentForm::RentForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RentForm)
{
    ui->setupUi(this);

    this->rent = 0;

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
    //Price *price = PriceDAOSingleton::instance()->find(type, condition, 1.0)[0];
    Price *price = new Price();
    price->setPrice(1.0);

    ui->pricePerHourLcd->display(QString::number(price->getPrice()));
}

void RentForm::setRent(Rent *rent) {
    Equipment* tmpEquipment = EquipmentDAOSingleton::instance()->findById(rent->getEquipmentId());

    this->rent = rent;
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
    if (!this->rent) {
        this->rent = new Rent();
    }

    int equipmentIndex = this->ui->equipmentConditionCombo->currentIndex();

    if (equipmentIndex < 0) {
        QMessageBox::critical(this, tr("Error"), tr("Please, select an equipment from a list or create one"));
        return;
    }

    this->rent->setEquipmentId(this->equipment[equipmentIndex]->getId());
    this->rent->setAmount(this->ui->amountSpin->value());
    this->rent->setRentFrom(QDateTime::currentDateTime());
    this->rent->setUserId(this->userId);

//    int conditionIndex = this->ui->equipmentConditionCombo->currentIndex();
//    char conditionKey = this->conditions.keys()[conditionIndex];
    // this->rent->setCondition(conditionKey); // TODO: set first available equipment

    emit saveRent(this->rent);
    this->close();
}
