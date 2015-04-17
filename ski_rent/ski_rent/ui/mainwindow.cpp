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

void MainWindow::setUsers(QList<User> users) {
    this->userRowModel->clear();
    this->userRowModel->add(users);
}

void MainWindow::setEquipment(QList<Equipment> equipment) {
    this->equipmentRowModel->clear();
    this->equipmentRowModel->add(equipment);
}

void MainWindow::onCreateEquipmentSubmitted(Equipment e) {
    BaseCommand* cmd = CompositeCommand::first(new CreateEquipmentCommand(e))->then(new QuickSearchCommand(this->ui->quickSearchEdit->text(), this));
    cmd->execute();
}

void MainWindow::onDeleteEquipmentSubmitted(int id) {
    BaseCommand* cmd = CompositeCommand::first(new DeleteEquipmentCommand(id))->then(new QuickSearchCommand(this->ui->quickSearchEdit->text(), this));
    cmd->execute();
}

void MainWindow::onUpdateEquipmentSubmitted(Equipment e) {
    BaseCommand* cmd = CompositeCommand::first(new UpdateEquipmentCommand(e))->then(new QuickSearchCommand(this->ui->quickSearchEdit->text(), this));
    cmd->execute();
}

void MainWindow::onCreateUserSubmitted(User u) {
    BaseCommand* cmd = CompositeCommand::first(new CreateUserCommand(u))->then(new QuickSearchCommand(this->ui->quickSearchEdit->text(), this));
    cmd->execute();
}

void MainWindow::onDeleteUserSubmitted(int id) {
    BaseCommand* cmd = CompositeCommand::first(new DeleteUserCommand(id))->then(new QuickSearchCommand(this->ui->quickSearchEdit->text(), this));
    cmd->execute();
}

void MainWindow::onUpdateUserSubmitted(User u) {
    BaseCommand* cmd = CompositeCommand::first(new UpdateUserCommand(u))->then(new QuickSearchCommand(this->ui->quickSearchEdit->text(), this));
    cmd->execute();
}

void MainWindow::onQuickSearchTextChanged(QString s) {
    BaseCommand* cmd = new QuickSearchCommand(this->ui->quickSearchEdit->text(), this);
    cmd->execute();
}

void MainWindow::onCreateEquipmentClicked() {
    EquipmentForm *win = new EquipmentForm();
    connect(win, SIGNAL(saveEquipment(Equipment)), this, SLOT(onCreateEquipmentSubmitted(Equipment)));
    win->show();
}

void MainWindow::onEditEquipmentClicked() {
    Equipment e = this->getSelectedEquipment();
    EquipmentForm *win = new EquipmentForm();
    win->setEquipment(e);
    connect(win, SIGNAL(saveEquipment(Equipment)), this, SLOT(onUpdateEquipmentSubmitted(Equipment)));
    win->show();
}

void MainWindow::onDeleteEquipmentClicked() {
    Equipment e = this->getSelectedEquipment();

    int ans = QMessageBox::question(this, tr("Please, confirm"), tr("Do you want to remove %1?").arg(e.getType()), QMessageBox::Yes, QMessageBox::No);

    if (ans == QMessageBox::Yes) {
        BaseCommand* cmd = CompositeCommand::first(new DeleteEquipmentCommand(e.getId()))->then(new QuickSearchCommand(this->ui->quickSearchEdit->text(), this));
        cmd->execute();
    }
}

void MainWindow::onCreateUserClicked() {
    UserForm *win = new UserForm();
    connect(win, SIGNAL(saveUser(User)), this, SLOT(onCreateUserSubmitted(User)));
    win->show();
}

void MainWindow::onEditUserClicked() {
    User u = this->getSelectedUser();
    UserForm *win = new UserForm();
    win->setUser(u);
    connect(win, SIGNAL(saveUser(User)), this, SLOT(onUpdateUserSubmitted(User)));
    win->show();
}

void MainWindow::onDeleteUserClicked() {
    User u = this->getSelectedUser();

    int ans = QMessageBox::question(this, tr("Please, confirm"), tr("Do you want to remove user %1 %2?").arg(u.getSurname(), u.getName()), QMessageBox::Yes, QMessageBox::No);

    if (ans == QMessageBox::Yes) {
        BaseCommand* cmd = CompositeCommand::first(new DeleteUserCommand(u.getId()))->then(new QuickSearchCommand(this->ui->quickSearchEdit->text(), this));
        cmd->execute();
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

Equipment MainWindow::getSelectedEquipment() {
    int index = this->ui->equipmentList->selectionModel()->selectedRows().at(0).row();
    return this->equipmentRowModel->at(index);
}

User MainWindow::getSelectedUser() {
    int index = this->ui->userList->selectionModel()->selectedRows().at(0).row();
    return this->userRowModel->at(index);
}
