#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "entities/user.h"
#include "entities/equipment.h"
#include "entities/rent.h"
#include "entities/reservation.h"
#include "entities/price.h"

#include "row_models/abstractrowmodel.h"

#include "ui/equipmentform.h"
#include "ui/userform.h"

#include <QList>
#include <QWidget>
#include <QDebug>
#include <QMessageBox>

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

public slots:
    void onQuickSearchTextChanged(QString s);

    void onCreateEquipmentClicked();
    void onEditEquipmentClicked();
    void onDeleteEquipmentClicked();

    void onCreateEquipmentSubmitted(Equipment* e);
    void onUpdateEquipmentSubmitted(Equipment* e);
    void onDeleteEquipmentSubmitted(int id);

    void onCreateUserClicked();
    void onEditUserClicked();
    void onDeleteUserClicked();

    void onCreateUserSubmitted(User* e);
    void onUpdateUserSubmitted(User* e);
    void onDeleteUserSubmitted(int id);

    void onEquipmentRowSelected(QModelIndex index);
    void onUserRowSelected(QModelIndex index);
    void onRentRowSelected(QModelIndex index);
    void onPriceRowSelected(QModelIndex index);

signals:
    void quickSearchTextChanged(QString s);

    void createEquipment(Equipment* e);
    void updateEquipment(Equipment* e);
    void deleteEquipment(int id);

    void createUser(User* e);
    void updateUser(User* e);
    void deleteUser(int id);

private:
    Ui::MainWindow *ui;
    AbstractRowModel<User> *userRowModel;
    AbstractRowModel<Equipment> *equipmentRowModel;
    AbstractRowModel<Rent> *rentRowModel;
    AbstractRowModel<Reservation> *reservationRowModel;
    AbstractRowModel<Price> *priceRowModel;
};

#endif // MAINWINDOW_H
