#ifndef BILLFORM_H
#define BILLFORM_H

#include "entities/history.h"
#include "dao/pricedao.h"

#include <math.h>

#include <QWidget>
#include <QList>
#include <QString>

namespace Ui {
class BillForm;
}

class BillForm : public QWidget
{
    Q_OBJECT

public:
    explicit BillForm(QList<History*> entries, QWidget *parent = 0);
    explicit BillForm(QWidget *parent = 0);
    ~BillForm();

    void setBillText(QString text);
    void setBillingItems(QList<History*> entries);

private:
    Ui::BillForm *ui;
};

#endif // BILLFORM_H
