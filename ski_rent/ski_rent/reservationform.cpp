#include "reservationform.h"
#include "ui_reservationform.h"

ReservationForm::ReservationForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReservationForm)
{
    ui->setupUi(this);
}

ReservationForm::~ReservationForm()
{
    delete ui;
}
