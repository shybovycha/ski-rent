#include "userform.h"
#include "ui_userform.h"

UserForm::UserForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserForm)
{
    ui->setupUi(this);

    // DO NOT TRANSLATE - THIS WILL CAUSE DATA INCONSISTENCY
    ui->documentTypeCombo->addItem("Passport");
    ui->documentTypeCombo->addItem("Visa");
    ui->documentTypeCombo->addItem("PESEL");

    // TODO: ADD ALL THE CITIES FROM DB
    // TODO: ADD ALL THE COUNTRIES FROM DB

    connect(this->ui->saveButton, SIGNAL(clicked()), this, SLOT(onSaveClicked()));
    connect(this->ui->cancelButton, SIGNAL(clicked()), this, SLOT(onCancelClicked()));
}

UserForm::~UserForm()
{
    delete ui;
}

void UserForm::onSaveClicked() {
    this->user.setName(this->ui->nameEdit->text());
    this->user.setSurname(this->ui->surnameEdit->text());
    this->user.setDocumentType(this->ui->documentTypeCombo->currentText());
    this->user.setDocumentNumber(this->ui->documentNumberEdit->text());
    this->user.setCountry(this->ui->countryCombo->currentText());
    this->user.setCity(this->ui->cityCombo->currentText());
    this->user.setAddress(this->ui->addressEdit->text());
    this->user.setPhone(this->ui->phoneEdit->text());

    emit saveUser(this->user);
    this->close();
}

void UserForm::onCancelClicked() {
    this->close();
}

void UserForm::setUser(User u) {
    this->user = u;

    this->ui->nameEdit->setText(u.getName());
    this->ui->surnameEdit->setText(u.getSurname());
    this->ui->documentTypeCombo->setCurrentText(u.getDocumentType());
    this->ui->documentNumberEdit->setText(u.getDocumentNumber());
    this->ui->countryCombo->setCurrentText(u.getCountry());
    this->ui->cityCombo->setCurrentText(u.getCity());
    this->ui->addressEdit->setText(u.getAddress());
    this->ui->phoneEdit->setText(u.getPhone());
}
