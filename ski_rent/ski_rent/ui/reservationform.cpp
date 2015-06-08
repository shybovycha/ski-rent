#include "reservationform.h"
#include "ui_reservationform.h"

ReservationForm::ReservationForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReservationForm)
{
    ui->setupUi(this);

    this->oldEntity = 0;
    this->newEntity = 0;

    this->equipment = EquipmentDAOSingleton::instance()->availableForUsage();

    for (int i = 0; i < equipment.size(); i++) {
        ui->equipmentTypeCombo->addItem(equipment[i]->getType());
    }

    conditions['A'] = tr("Brand new");
    conditions['B'] = tr("A bit used");
    conditions['C'] = tr("Used");
    conditions['D'] = tr("Hardly used");
    conditions['E'] = tr("Almost done");

    ui->equipmentConditionCombo->addItems(conditions.values());
    ui->rentFromEdit->setDateTime(QDateTime::currentDateTime()); // now
    ui->rentToEdit->setDateTime(QDateTime::currentDateTime().addSecs(60 * 60)); // 1 hour later

    connect(ui->saveButton, SIGNAL(clicked()), this, SLOT(onSaveClicked()));
    connect(ui->cancelButton, SIGNAL(clicked()), this, SLOT(onCancelClicked()));
}

ReservationForm::~ReservationForm()
{
    delete ui;
}

void ReservationForm::setReservation(Reservation *reservation) {
    Equipment *tmpEquipment = EquipmentDAOSingleton::instance()->findById(reservation->getEquipmentId());

    this->oldEntity = reservation;
    this->userId = reservation->getUserId();
    this->equipmentId = reservation->getEquipmentId();

    char conditionKey = tmpEquipment->getCondition();
    ui->equipmentConditionCombo->setCurrentIndex(this->conditions.keys().indexOf(conditionKey));

    ui->equipmentTypeCombo->setCurrentText(tmpEquipment->getType());

    ui->amountSpin->setValue(reservation->getAmount());

    ui->rentFromEdit->setDateTime(reservation->getRentFrom());
    ui->rentToEdit->setDateTime(reservation->getRentTo());
}

void ReservationForm::setUserId(int userId) {
    this->userId = userId;
}

void ReservationForm::onCancelClicked() {
    this->close();
}

void ReservationForm::onSaveClicked() {
    if (!this->newEntity) {
        this->newEntity = new Reservation();
    }

    int equipmentIndex = this->ui->equipmentConditionCombo->currentIndex();

    if (equipmentIndex < 0) {
        QMessageBox::critical(this, tr("Error"), tr("Please, select an equipment from a list or create one"));
        return;
    }

    this->newEntity->setEquipmentId(this->equipment[equipmentIndex]->getId());
    this->newEntity->setAmount(this->ui->amountSpin->value());
    this->newEntity->setRentFrom(ui->rentFromEdit->dateTime());
    this->newEntity->setRentTo(ui->rentToEdit->dateTime());
    this->newEntity->setUserId(this->userId);

    emit saveReservation(this->oldEntity, this->newEntity);

    this->close();
}
