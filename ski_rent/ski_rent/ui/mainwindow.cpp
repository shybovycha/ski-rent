#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->ui->tabWidget->setCurrentIndex(0);

    this->userRowModel = new AbstractRowModel<User>();
    this->equipmentRowModel = new AbstractRowModel<Equipment>();
    this->rentRowModel = new AbstractRowModel<Rent>();
    this->reservationRowModel = new AbstractRowModel<Reservation>();

    this->ui->newRentButton->setEnabled(false);
    this->ui->newReservationButton->setEnabled(false);
    this->ui->newReturnButton->setEnabled(false);

    this->ui->editEquipmentButton->setEnabled(false);
    this->ui->deleteEquipmentButton->setEnabled(false);

    this->ui->editUserButton->setEnabled(false);
    this->ui->deleteUserButton->setEnabled(false);

    this->ui->userList->setModel(this->userRowModel);
    this->ui->equipmentList->setModel(this->equipmentRowModel);
    this->ui->rentList->setModel(this->rentRowModel);
    this->ui->reservationList->setModel(this->reservationRowModel);

    connect(this->ui->quickSearchEdit, SIGNAL(textEdited(QString)), this, SLOT(onQuickSearchTextChanged(QString)));

    connect(this->ui->createEquipmentButton, SIGNAL(clicked()), this, SLOT(onCreateEquipmentClicked()));
    connect(this->ui->editEquipmentButton, SIGNAL(clicked()), this, SLOT(onEditEquipmentClicked()));
    connect(this->ui->deleteEquipmentButton, SIGNAL(clicked()), this, SLOT(onDeleteEquipmentClicked()));

    connect(this->ui->createUserButton, SIGNAL(clicked()), this, SLOT(onCreateUserClicked()));
    connect(this->ui->editUserButton, SIGNAL(clicked()), this, SLOT(onEditUserClicked()));
    connect(this->ui->deleteUserButton, SIGNAL(clicked()), this, SLOT(onDeleteUserClicked()));

    connect(this->ui->userList, SIGNAL(clicked(QModelIndex)), this, SLOT(onUserRowSelected(QModelIndex)));
    connect(this->ui->equipmentList, SIGNAL(clicked(QModelIndex)), this, SLOT(onEquipmentRowSelected(QModelIndex)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setUsers(QList<User*> users) {
    this->userRowModel->clear();
    this->userRowModel->add(users);
    this->ui->tabWidget->setTabText(0, tr("Users (%1)").arg(users.size()));
}

void MainWindow::setEquipment(QList<Equipment*> equipment) {
    this->equipmentRowModel->clear();
    this->equipmentRowModel->add(equipment);
    this->ui->tabWidget->setTabText(1, tr("Equipment (%1)").arg(equipment.size()));
}

void MainWindow::onCreateEquipmentSubmitted(Equipment* e) {
    emit createEquipment(e);
    emit quickSearchTextChanged(this->ui->quickSearchEdit->text());
}

void MainWindow::onDeleteEquipmentSubmitted(int id) {
    emit deleteEquipment(id);
    emit quickSearchTextChanged(this->ui->quickSearchEdit->text());
}

void MainWindow::onUpdateEquipmentSubmitted(Equipment* e) {
    emit updateEquipment(e);
    emit quickSearchTextChanged(this->ui->quickSearchEdit->text());
}

void MainWindow::onCreateUserSubmitted(User* u) {
    emit createUser(u);
    emit quickSearchTextChanged(this->ui->quickSearchEdit->text());
}

void MainWindow::onDeleteUserSubmitted(int id) {
    emit deleteUser(id);
    emit quickSearchTextChanged(this->ui->quickSearchEdit->text());
}

void MainWindow::onUpdateUserSubmitted(User* u) {
    emit updateUser(u);
    emit quickSearchTextChanged(this->ui->quickSearchEdit->text());
}

void MainWindow::onQuickSearchTextChanged(QString s) {
    emit quickSearchTextChanged(s);
}

void MainWindow::onCreateEquipmentClicked() {
    EquipmentForm *win = new EquipmentForm();
    connect(win, SIGNAL(saveEquipment(Equipment*)), this, SLOT(onCreateEquipmentSubmitted(Equipment*)));
    win->show();
}

void MainWindow::onEditEquipmentClicked() {
    Equipment* e = this->getSelectedEquipment();
    EquipmentForm *win = new EquipmentForm();
    win->setEquipment(e);
    connect(win, SIGNAL(saveEquipment(Equipment*)), this, SLOT(onUpdateEquipmentSubmitted(Equipment*)));
    win->show();
}

void MainWindow::onDeleteEquipmentClicked() {
    Equipment* e = this->getSelectedEquipment();

    int ans = QMessageBox::question(this, tr("Please, confirm"), tr("Do you want to remove %1?").arg(e->getType()), QMessageBox::Yes, QMessageBox::No);

    if (ans == QMessageBox::Yes) {
        emit deleteEquipment(e->getId());
        emit quickSearchTextChanged(this->ui->quickSearchEdit->text());
    }
}

void MainWindow::onCreateUserClicked() {
    UserForm *win = new UserForm();
    connect(win, SIGNAL(saveUser(User*)), this, SLOT(onCreateUserSubmitted(User*)));
    win->show();
}

void MainWindow::onEditUserClicked() {
    User* u = this->getSelectedUser();
    UserForm *win = new UserForm();
    win->setUser(u);
    connect(win, SIGNAL(saveUser(User*)), this, SLOT(onUpdateUserSubmitted(User*)));
    win->show();
}

void MainWindow::onDeleteUserClicked() {
    User* u = this->getSelectedUser();

    int ans = QMessageBox::question(this, tr("Please, confirm"), tr("Do you want to remove user %1 %2?").arg(u->getSurname(), u->getName()), QMessageBox::Yes, QMessageBox::No);

    if (ans == QMessageBox::Yes) {
        emit deleteUser(u->getId());
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

Equipment* MainWindow::getSelectedEquipment() {
    int index = this->ui->equipmentList->selectionModel()->selectedRows().at(0).row();
    return this->equipmentRowModel->at(index);
}

User* MainWindow::getSelectedUser() {
    int index = this->ui->userList->selectionModel()->selectedRows().at(0).row();
    return this->userRowModel->at(index);
}
