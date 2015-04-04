#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "entities/user.h"
#include "entities/equipment.h"

#include "ui/userrowmodel.h"
#include "ui/equipmentrowmodel.h"

#include <QList>
#include <QWidget>

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

signals:
    void quickSearchTextChanged(QString s);

private:
    Ui::MainWindow *ui;
    UserRowModel *userRowModel;
    EquipmentRowModel *equipmentRowModel;
};

#endif // MAINWINDOW_H
