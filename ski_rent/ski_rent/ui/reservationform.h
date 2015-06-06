#ifndef RESERVATIONFORM_H
#define RESERVATIONFORM_H

#include <QWidget>
#include <QMap>
#include <QString>
#include <QList>
#include <QMessageBox>

#include "entities/reservation.h"
#include "entities/equipment.h"
#include "entities/user.h"
#include "dao/equipmentdao.h"

namespace Ui {
class ReservationForm;
}

class ReservationForm : public QWidget
{
    Q_OBJECT

public:
    explicit ReservationForm(QWidget *parent = 0);
    ~ReservationForm();

    void setReservation(Reservation *reservation);
    void setUserId(int userId);

public slots:
    void onSaveClicked();
    void onCancelClicked();

signals:
    void saveReservation(Reservation* oldReservation, Reservation* reservation);

private:
    Ui::ReservationForm *ui;
    int userId;
    int equipmentId;
    Reservation *oldEntity, *newEntity;
    QList<Equipment*> equipment;
    QMap<char, QString> conditions;
};

#endif // RESERVATIONFORM_H
