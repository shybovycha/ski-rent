#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->userRowModel = new UserRowModel();
    this->equipmentRowModel = new EquipmentRowModel();

    this->ui->newRentButton->setEnabled(false);
    this->ui->newReservationButton->setEnabled(false);
    this->ui->newReturnButton->setEnabled(false);

    this->ui->editEquipmentButton->setEnabled(false);
    this->ui->deleteEquipmentButton->setEnabled(false);

    this->ui->editUserButton->setEnabled(false);
    this->ui->deleteUserButton->setEnabled(false);

    this->ui->userList->setModel(this->userRowModel);
    this->ui->equipmentList->setModel(this->equipmentRowModel);

    connect(this->ui->quickSearchEdit, SIGNAL(textEdited(QString)), this, SLOT(onQuickSearchTextChanged(QString)));

    connect(this->ui->createEquipmentButton, SIGNAL(clicked()), this, SLOT(onCreateEquipmentClicked()));
    connect(this->ui->editEquipmentButton, SIGNAL(clicked()), this, SLOT(onEditEquipmentClicked()));
    connect(this->ui->deleteEquipmentButton, SIGNAL(clicked()), this, SLOT(onDeleteEquipmentClicked()));

    connect(this->ui->userList, SIGNAL(clicked(QModelIndex)), this, SLOT(onUserRowSelected(QModelIndex)));
    connect(this->ui->equipmentList, SIGNAL(clicked(QModelIndex)), this, SLOT(onEquipmentRowSelected(QModelIndex)));
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

void MainWindow::onCreateEquipmentClicked() {
    EquipmentForm *win = new EquipmentForm();
    connect(win, SIGNAL(saveEquipment(Equipment)), this, SLOT(onCreateEquipmentSubmitted(Equipment)));
    win->show();
}

void MainWindow::onCreateEquipmentSubmitted(Equipment e) {
    emit createEquipment(e);
    emit quickSearchTextChanged(this->ui->quickSearchEdit->text());
}

void MainWindow::onDeleteEquipmentSubmitted(int id) {
    emit deleteEquipment(id);
    emit quickSearchTextChanged(this->ui->quickSearchEdit->text());
}

void MainWindow::onUpdateEquipmentSubmitted(Equipment e) {
    emit updateEquipment(e);
    emit quickSearchTextChanged(this->ui->quickSearchEdit->text());
}

void MainWindow::onEditEquipmentClicked() {
    int index = this->ui->equipmentList->selectionModel()->selectedRows().at(0).row();
    Equipment e = this->equipmentRowModel->at(index);
    EquipmentForm *win = new EquipmentForm();
    win->setEquipment(e);
    connect(win, SIGNAL(saveEquipment(Equipment)), this, SLOT(onUpdateEquipmentSubmitted(Equipment)));
    win->show();
}

void MainWindow::onDeleteEquipmentClicked() {
    int index = this->ui->equipmentList->selectionModel()->selectedRows().at(0).row();
    Equipment e = this->equipmentRowModel->at(index);

    int ans = QMessageBox::question(this, tr("Please, confirm"), tr("Do you want to remove %1?").arg(e.getType()), QMessageBox::Yes, QMessageBox::No);

    if (ans == QMessageBox::Yes) {
        emit deleteEquipment(e.getId());
        emit quickSearchTextChanged(this->ui->quickSearchEdit->text());
    }
}

void MainWindow::onEquipmentRowSelected(QModelIndex index) {
    if (this->ui->equipmentList->selectionModel()->hasSelection()) {
        this->ui->editEquipmentButton->setEnabled(true);
        this->ui->deleteEquipmentButton->setEnabled(true);
    } else {
        this->ui->editEquipmentButton->setEnabled(false);
        this->ui->deleteEquipmentButton->setEnabled(false);
    }
}

void MainWindow::onUserRowSelected(QModelIndex index) {
    if (this->ui->userList->selectionModel()->hasSelection()) {
        this->ui->editUserButton->setEnabled(true);
        this->ui->deleteUserButton->setEnabled(true);
    } else {
        this->ui->editUserButton->setEnabled(false);
        this->ui->deleteUserButton->setEnabled(false);
    }
}
