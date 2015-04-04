#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    this->userRowModel = new UserRowModel();
    this->equipmentRowModel = new EquipmentRowModel();

    ui->setupUi(this);

    this->ui->userList->setModel(this->userRowModel);
    this->ui->equipmentList->setModel(this->equipmentRowModel);

    connect(this->ui->quickSearchEdit, SIGNAL(textEdited(QString)), this, SLOT(onQuickSearchTextChanged(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setUsers(QList<User> users) {
    this->userRowModel->clear();
    this->userRowModel->add(users);
}

void MainWindow::setEquipment(QList<Equipment> equipment) {
    this->equipmentRowModel->clear();
    this->equipmentRowModel->add(equipment);
}

void MainWindow::onQuickSearchTextChanged(QString s) {
    emit quickSearchTextChanged(s);
}
