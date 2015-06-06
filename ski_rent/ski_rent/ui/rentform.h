#ifndef RENTFORM_H
#define RENTFORM_H

#include <QWidget>
#include <QMessageBox>

#include "entities/equipment.h"
#include "entities/user.h"
#include "entities/rent.h"

#include "dao/equipmentdao.h"
#include "dao/pricedao.h"

namespace Ui {
class RentForm;
}

class RentForm : public QWidget
{
    Q_OBJECT

public:
    explicit RentForm(QWidget *parent = 0);
    ~RentForm();

    void setRent(Rent *rent);
    void setUserId(int userId);

public slots:
    void onSaveClicked();
    void onCancelClicked();
    void recalculatePricePerHour();

signals:
    void saveRent(Rent* oldRent, Rent *newRent);

private:
    Ui::RentForm *ui;
    int userId;
    Rent *oldRent, *newRent;
    QList<Equipment*> equipment;
    QMap<char, QString> conditions;
};

#endif // RENTFORM_H
