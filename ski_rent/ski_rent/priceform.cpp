#include "priceform.h"
#include "ui_priceform.h"

PriceForm::PriceForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PriceForm)
{
    ui->setupUi(this);
}

PriceForm::~PriceForm()
{
    delete ui;
}
