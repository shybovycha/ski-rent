#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "entities/user.h"
#include "entities/equipment.h"
#include "entities/rent.h"
#include "entities/reservation.h"
#include "entities/price.h"

#include "dao/historydao.h"
#include "dao/rentdao.h"

#include "row_models/abstractrowmodel.h"
#include "row_models/pricerowmodel.h"
#include "row_models/rentrowmodel.h"
#include "row_models/reservationrowmodel.h"

#include "ui/equipmentform.h"
#include "ui/userform.h"
#include "ui/rentform.h"
#include "ui/reservationform.h"
#include "ui/priceform.h"
#include "ui/billform.h"

#include <QList>
#include <QWidget>
#include <QDebug>
#include <QMessageBox>
#include <QCloseEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void setUsers(QList<User*> users);
    void setEquipment(QList<Equipment*> equipment);

protected:
    Equipment* getSelectedEquipment();
    User* getSelectedUser();
    Price* getSelectedPrice();
    Reservation* getSelectedReservation();
    QList<Rent*> getSelectedRents();
    QList<History*> returnFromRent(QList<Rent*> entries);

    void closeEvent(QCloseEvent *event);

public slots:
    void onClose();

    void onQuickSearchTextChanged(QString s);

    void onCreateEquipmentClicked();
    void onEditEquipmentClicked();
    void onDeleteEquipmentClicked();

    void onCreateUserClicked();
    void onEditUserClicked();
    void onDeleteUserClicked();

    void onCreatePriceClicked();
    void onEditPriceClicked();
    void onDeletePriceClicked();

    void onEditRentClicked();
    void onEditReservationClicked();

    void onCreatePriceSubmitted(Price *e);
    void onUpdatePriceSubmitted(QString, char, int, Price *e);
    void onDeletePriceSubmitted(QString, char, int);

    void onCreateUserSubmitted(User *e);
    void onUpdateUserSubmitted(User *e);
    void onDeleteUserSubmitted(int id);

    void onCreateEquipmentSubmitted(Equipment *e);
    void onUpdateEquipmentSubmitted(Equipment *e);
    void onDeleteEquipmentSubmitted(int id);

    void onCreateReservationSubmitted(Reservation* _, Reservation *newEntity);
    void onUpdateReservationSubmitted(Reservation *oldEntity, Reservation *newEntity);

    void onCreateRentSubmitted(Rent*, Rent*);
    void onUpdateRentSubmitted(Rent*, Rent*);

    void returnFromRentSubmitted(Rent*);
    void reservationToRentSubmitted(Reservation*);

    void onEquipmentRowSelected(QModelIndex index);
    void onUserRowSelected(QModelIndex index);
    void onRentRowSelected(QModelIndex index);
    void onReservationRowSelected(QModelIndex index);
    void onPriceRowSelected(QModelIndex index);

    void onNewReservationClicked();
    void onNewRentClicked();
    void onNewReturnClicked();
    void onReservationToRentClicked();
    void onCancelReservationClicked();

    void setRents(QList<Rent*> rents);
    void setReservations(QList<Reservation*> reservations);
    void setPrices(QList<Price*> prices);

signals:
    void quickSearchTextChanged(QString s);

    void createEquipment(Equipment *e);
    void updateEquipment(Equipment *e);
    void deleteEquipment(int id);

    void createUser(User *e);
    void updateUser(User *e);
    void deleteUser(int id);

    void reservationToRent(Reservation*);
    void removePrice(Price*);
    void reservationCancel(Reservation*);
    void updateReservation(Reservation*, Reservation*);
    void returnFromRent(Rent*);
    void createPrice(Price*);
    void updatePrice(QString type, char condition, int time, Price*);
    void deletePrice(QString type, char condition, int time);
    void createReservation(Reservation*);
    void createRent(Rent*);
    void updateRent(Rent*, Rent*);
    void removeRent(Rent*);

private:
    Ui::MainWindow *ui;
    AbstractRowModel<User> *userRowModel;
    AbstractRowModel<Equipment> *equipmentRowModel;
    RentRowModel *rentRowModel;
    ReservationRowModel *reservationRowModel;
    PriceRowModel *priceRowModel;
};

#endif // MAINWINDOW_H
