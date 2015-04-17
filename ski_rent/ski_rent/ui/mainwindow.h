#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "commands/compositecommand.h"
#include "commands/createequipmentcommand.h"
#include "commands/deleteequipmentcommand.h"
#include "commands/updateequipmentcommand.h"
#include "commands/createusercommand.h"
#include "commands/deleteusercommand.h"
#include "commands/updateusercommand.h"
#include "commands/quicksearchcommand.h"

#include "entities/user.h"
#include "entities/equipment.h"

#include "ui/userrowmodel.h"
#include "ui/equipmentrowmodel.h"

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

    void setUsers(QList<User> users);
    void setEquipment(QList<Equipment> equipment);

protected:
    Equipment getSelectedEquipment();
    User getSelectedUser();

public slots:
    void onQuickSearchTextChanged(QString s);

    void onCreateEquipmentClicked();
    void onEditEquipmentClicked();
    void onDeleteEquipmentClicked();

    void onCreateEquipmentSubmitted(Equipment e);
    void onUpdateEquipmentSubmitted(Equipment e);
    void onDeleteEquipmentSubmitted(int id);

    void onCreateUserClicked();
    void onEditUserClicked();
    void onDeleteUserClicked();

    void onCreateUserSubmitted(User e);
    void onUpdateUserSubmitted(User e);
    void onDeleteUserSubmitted(int id);

    void onEquipmentRowSelected(QModelIndex index);
    void onUserRowSelected(QModelIndex index);

signals:
    void quickSearchTextChanged(QString s);

    void createEquipment(Equipment e);
    void updateEquipment(Equipment e);
    void deleteEquipment(int id);

    void createUser(User e);
    void updateUser(User e);
    void deleteUser(int id);

private:
    Ui::MainWindow *ui;
    UserRowModel *userRowModel;
    EquipmentRowModel *equipmentRowModel;
};

#endif // MAINWINDOW_H
