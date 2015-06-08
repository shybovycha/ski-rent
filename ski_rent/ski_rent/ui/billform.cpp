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
    QString css = tr("<style>.top-header { text-transform:uppercase; } * { font-family: \"Courier New\", Courier, monospace; } p { display:inline; }</style>");
    QString header = tr("<table><thead><tr><th colspan=\"2\"><h1 align=\"center\">SkiRent</h1></th></tr><tr><th colspan=\"2\"><h3 class=\"top-header\" align=\"center\">the bill</h3></th></tr></thead><tbody>");

    float total = 0.0;

    for (int i = 0; i < entries.size(); i++) {
        int time = max(ceil(abs(entries[i]->getRentFrom().msecsTo(entries[i]->getRentTo())) / (60 * 60 * 1000)), 1);
        float pricePerHour = PriceDAOSingleton::instance()->getPricePerHour(entries[i]->getType(), entries[i]->getCondition(), time);
        float totalPrice = PriceDAOSingleton::instance()->getPriceTotal(entries[i]->getType(), entries[i]->getCondition(), time, entries[i]->getAmount());

        total += totalPrice;

        QString titleLine = tr("%1 (%2)").arg(entries[i]->getType()).arg(entries[i]->getCondition());
        QString priceLine = tr("%1 hrs &times; %2 = %3").arg(time).arg(pricePerHour).arg(totalPrice);

        entriesHtml += tr("<tr><td align=\"left\">%1</td><td align=\"right\">%2</td></tr>")
                .arg(titleLine)
                .arg(priceLine);
    }

    QString spacerLine = tr("<tr><td colspan=\"2\"><hr /></td></tr>");
    QString currency = tr("USD");
    QString totalLine = tr("<tr><td align=\"left\"><h1>TOTAL, %1</h1></td><td align=\"right\"><h1>%2</h1></td></tr></tbody></table>")
            .arg(currency)
            .arg(QString::number(total, 'g', 2));

    QString html = css + header + entriesHtml + spacerLine + totalLine;

    this->setBillText(html);
}

BillForm::~BillForm()
{
    delete ui;
}
