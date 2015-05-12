#include "reservationform.h"
#include "ui_reservationform.h"

ReservationForm::ReservationForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReservationForm)
{
    ui->setupUi(this);

    this->reservation = 0;

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
}

ReservationForm::~ReservationForm()
{
    delete ui;
}

void ReservationForm::setReservation(Reservation *reservation) {
    Equipment *tmpEquipment = EquipmentDAOSingleton::instance()->findById(reservation->getEquipmentId());

    this->reservation = reservation;
    this->userId = reservation->getUserId();

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
    if (!this->reservation) {
        this->reservation = new Reservation();
    }

    int equipmentIndex = this->ui->equipmentConditionCombo->currentIndex();

    if (equipmentIndex < 0) {
        QMessageBox::critical(this, tr("Error"), tr("Please, select an equipment from a list or create one"));
        return;
    }

    this->reservation->setEquipmentId(this->equipment[equipmentIndex]->getId());
    this->reservation->setAmount(this->ui->amountSpin->value());
    this->reservation->setRentFrom(ui->rentFromEdit->dateTime());
    this->reservation->setRentTo(ui->rentToEdit->dateTime());
    this->reservation->setUserId(this->userId);

//    int conditionIndex = this->ui->conditionCombo->currentIndex();
//    char conditionKey = this->conditions.keys()[conditionIndex];
//    this->reservation->setCondition(conditionKey);
    // TODO: set first available equipment

    emit saveReservation(this->reservation);
    this->close();
}
