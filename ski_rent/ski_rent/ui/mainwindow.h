#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "entities/user.h"
#include "entities/equipment.h"

#include "ui/userrowmodel.h"
#include "ui/equipmentrowmodel.h"
#include "ui/equipmentform.h"

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

public slots:
    void onQuickSearchTextChanged(QString s);
    void onCreateEquipmentClicked();
    void onCreateEquipmentSubmitted(Equipment e);
    void onEditEquipmentClicked();
    void onUpdateEquipmentSubmitted(Equipment e);
    void onDeleteEquipmentClicked();
    void onDeleteEquipmentSubmitted(int id);
    void onEquipmentRowSelected(QModelIndex index);
    void onUserRowSelected(QModelIndex index);

signals:
    void quickSearchTextChanged(QString s);
    void createEquipment(Equipment e);
    void updateEquipment(Equipment e);
    void deleteEquipment(int id);

private:
    Ui::MainWindow *ui;
    UserRowModel *userRowModel;
    EquipmentRowModel *equipmentRowModel;
};

#endif // MAINWINDOW_H
