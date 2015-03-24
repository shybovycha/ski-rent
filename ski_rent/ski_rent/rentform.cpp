#include "rentform.h"
#include "ui_rentform.h"

RentForm::RentForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RentForm)
{
    ui->setupUi(this);
}

RentForm::~RentForm()
{
    delete ui;
}
