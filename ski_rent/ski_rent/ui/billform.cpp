#include "billform.h"
#include "ui_billform.h"

BillForm::BillForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BillForm)
{
    ui->setupUi(this);

    connect(this->ui->closeButton, SIGNAL(clicked()), this, SLOT(close()));
}

BillForm::BillForm(QList<History*> entries, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BillForm)
{
    ui->setupUi(this);

    connect(this->ui->closeButton, SIGNAL(clicked()), this, SLOT(close()));

    this->setBillingItems(entries);
}

void BillForm::setBillText(QString text) {
    this->ui->billTextEdit->setHtml(text);
}

void BillForm::setBillingItems(QList<History*> entries) {
    QString entriesHtml = "";
    QString css = tr("<style>.top-header { width:100%; text-align:center; text-transform:uppercase; } .row { display:block; } .title { display:inline-block; width:70%; } .price { display:inline-block; width:30%; } .spacer { font-family: \"Courier New\", Courier, monospace; }</style>");
    QString header = tr("<h1>SkiRent</h1><div class=\"top-header\"><h3>the bill</h3></div>");

    float total = 0.0;

    for (int i = 0; i < entries.size(); i++) {
        int time = ceil(abs(entries[i]->getRentFrom().msecsTo(entries[i]->getRentTo())) / (60 * 60 * 1000));
        float pricePerHour = PriceDAOSingleton::instance()->getPricePerHour(entries[i]->getType(), entries[i]->getCondition(), time);
        float totalPrice = PriceDAOSingleton::instance()->getPriceTotal(entries[i]->getType(), entries[i]->getCondition(), time, entries[i]->getAmount());

        total += totalPrice;

        QString titleLine = tr("%1 (%2)").arg(entries[i]->getType()).arg(entries[i]->getCondition());
        QString priceLine = tr("%1 hrs &times; %2 = %3").arg(time).arg(pricePerHour).arg(totalPrice);

        entriesHtml += tr("<div class=\"row\"><span class=\"title\">%1</span><span class=\"price\">%2</span></div>")
                .arg(titleLine)
                .arg(priceLine);
    }

    QString spacerLine = tr("<div class=\"spacer\">----------------------</div>");
    QString currency = tr("USD");
    QString totalLine = tr("<div class=\"row\"><h1><span class=\"title\">TOTAL, %1</span><span class=\"price\">%2</span></h1></div>")
            .arg(currency)
            .arg(QString::number(total, 'g', 2));

    QString html = css + header + entriesHtml + spacerLine + totalLine;

    this->setBillText(html);
}

BillForm::~BillForm()
{
    delete ui;
}
