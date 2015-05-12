#ifndef PRICEFORM_H
#define PRICEFORM_H

#include <QWidget>
#include <QMessageBox>

#include "entities/equipment.h"
#include "entities/user.h"
#include "entities/rent.h"

#include "dao/equipmentdao.h"
#include "dao/pricedao.h"

namespace Ui {
class PriceForm;
}

class PriceForm : public QWidget
{
    Q_OBJECT

public:
    explicit PriceForm(QWidget *parent = 0);
    ~PriceForm();

    void setPrice(Price *price);
    void setEquipmentId(int equipmentId);

public slots:
    void onSaveClicked();
    void onCancelClicked();

signals:
    void savePrice(Price *price);

private:
    Ui::PriceForm *ui;
    Price *price;
    int equipmentId;
    QList<Equipment*> equipment;
    QMap<char, QString> conditions;
};

#endif // PRICEFORM_H
