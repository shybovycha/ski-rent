#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->ui->tabWidget->setCurrentIndex(0);

    // row models
    this->userRowModel = new AbstractRowModel<User>();
    this->equipmentRowModel = new AbstractRowModel<Equipment>();
    this->historyRowModel = new AbstractRowModel<History>();
    this->rentRowModel = new RentRowModel();
    this->reservationRowModel = new ReservationRowModel();
    this->priceRowModel = new PriceRowModel();

    this->ui->userList->setModel(this->userRowModel);
    this->ui->equipmentList->setModel(this->equipmentRowModel);
    this->ui->rentList->setModel(this->rentRowModel);
    this->ui->reservationList->setModel(this->reservationRowModel);
    this->ui->priceList->setModel(this->priceRowModel);
    this->ui->historyList->setModel(this->historyRowModel);

    // disabling buttons which require selection
    this->ui->newRentButton->setEnabled(false);
    this->ui->newReservationButton->setEnabled(false);

    this->ui->newReturnButton->setEnabled(false);

    this->ui->editEquipmentButton->setEnabled(false);
    this->ui->deleteEquipmentButton->setEnabled(false);

    this->ui->editUserButton->setEnabled(false);
    this->ui->deleteUserButton->setEnabled(false);

    this->ui->editRentButton->setEnabled(false);

    this->ui->reservationToRentButton->setEnabled(false);
    this->ui->editReservationButton->setEnabled(false);
    this->ui->cancelReservationButton->setEnabled(false);

    this->ui->editPriceButton->setEnabled(false);
    this->ui->deletePriceButton->setEnabled(false);

    // assign slots to signals
    connect(this->ui->quickSearchEdit, SIGNAL(textEdited(QString)), this, SLOT(onQuickSearchTextChanged(QString)));

    connect(this->ui->createEquipmentButton, SIGNAL(clicked()), this, SLOT(onCreateEquipmentClicked()));
    connect(this->ui->editEquipmentButton, SIGNAL(clicked()), this, SLOT(onEditEquipmentClicked()));
    connect(this->ui->deleteEquipmentButton, SIGNAL(clicked()), this, SLOT(onDeleteEquipmentClicked()));

    connect(this->ui->createUserButton, SIGNAL(clicked()), this, SLOT(onCreateUserClicked()));
    connect(this->ui->editUserButton, SIGNAL(clicked()), this, SLOT(onEditUserClicked()));
    connect(this->ui->deleteUserButton, SIGNAL(clicked()), this, SLOT(onDeleteUserClicked()));

    connect(this->ui->newReservationButton, SIGNAL(clicked()), this, SLOT(onNewReservationClicked()));
    connect(this->ui->newRentButton, SIGNAL(clicked()), this, SLOT(onNewRentClicked()));

    connect(this->ui->editRentButton, SIGNAL(clicked()), this, SLOT(onEditRentClicked()));
    connect(this->ui->newReturnButton, SIGNAL(clicked()), this, SLOT(onNewReturnClicked()));

    connect(this->ui->reservationToRentButton, SIGNAL(clicked()), this, SLOT(onReservationToRentClicked()));
    connect(this->ui->editReservationButton, SIGNAL(clicked()), this, SLOT(onEditReservationClicked()));
    connect(this->ui->cancelReservationButton, SIGNAL(clicked()), this, SLOT(onCancelReservationClicked()));

    connect(this->ui->createPriceButton, SIGNAL(clicked()), this, SLOT(onCreatePriceClicked()));
    connect(this->ui->editPriceButton, SIGNAL(clicked()), this, SLOT(onEditPriceClicked()));
    connect(this->ui->deletePriceButton, SIGNAL(clicked()), this, SLOT(onDeletePriceClicked()));

    // slots for enabling editing/deleting buttons
    connect(this->ui->userList, SIGNAL(clicked(QModelIndex)), this, SLOT(onUserRowSelected(QModelIndex)));
    connect(this->ui->equipmentList, SIGNAL(clicked(QModelIndex)), this, SLOT(onEquipmentRowSelected(QModelIndex)));
    connect(this->ui->rentList, SIGNAL(clicked(QModelIndex)), this, SLOT(onRentRowSelected(QModelIndex)));
    connect(this->ui->reservationList, SIGNAL(clicked(QModelIndex)), this, SLOT(onReservationRowSelected(QModelIndex)));
    connect(this->ui->priceList, SIGNAL(clicked(QModelIndex)), this, SLOT(onPriceRowSelected(QModelIndex)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onClose() {
    QApplication::quit();
}

void MainWindow::closeEvent(QCloseEvent *event) {
    event->accept();
    QApplication::quit();
}

// filling views with entities

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

void MainWindow::setRents(QList<Rent*> rents) {
    this->rentRowModel->clear();
    this->rentRowModel->add(rents);
    this->ui->tabWidget->setTabText(2, tr("Rents (%1)").arg(rents.size()));
}

void MainWindow::setReservations(QList<Reservation*> reservations) {
    this->reservationRowModel->clear();
    this->reservationRowModel->add(reservations);
    this->ui->tabWidget->setTabText(3, tr("Reservations (%1)").arg(reservations.size()));
}

void MainWindow::setPrices(QList<Price*> prices) {
    this->priceRowModel->clear();
    this->priceRowModel->add(prices);
    this->ui->tabWidget->setTabText(4, tr("Prices (%1)").arg(prices.size()));
}

void MainWindow::setHistoryEntries(QList<History*> entries) {
    this->historyRowModel->clear();
    this->historyRowModel->add(entries);
    this->ui->tabWidget->setTabText(5, tr("Archive (%1)").arg(entries.size()));
}

// modal window callbacks

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

void MainWindow::onCreatePriceSubmitted(Price *e) {
    emit createPrice(e);
    emit quickSearchTextChanged(this->ui->quickSearchEdit->text());
}

void MainWindow::onUpdatePriceSubmitted(QString type, char condition, int time, Price *e) {
    emit updatePrice(type, condition, time, e);
    emit quickSearchTextChanged(this->ui->quickSearchEdit->text());
}

void MainWindow::onDeletePriceSubmitted(QString type, char condition, int time) {
    emit deletePrice(type, condition, time);
    emit quickSearchTextChanged(this->ui->quickSearchEdit->text());
}

void MainWindow::onCreateReservationSubmitted(Reservation* _, Reservation *r) {
    emit createReservation(r);
    emit quickSearchTextChanged(this->ui->quickSearchEdit->text());
}

void MainWindow::onUpdateReservationSubmitted(Reservation *oldEntity, Reservation *newEntity) {
    emit updateReservation(oldEntity, newEntity);
    emit quickSearchTextChanged(this->ui->quickSearchEdit->text());
}

void MainWindow::onCreateRentSubmitted(Rent* _, Rent* r) {
    emit createRent(r);
    emit quickSearchTextChanged(this->ui->quickSearchEdit->text());
}

void MainWindow::onUpdateRentSubmitted(Rent* oldRent, Rent* newRent) {
    emit updateRent(oldRent, newRent);
    emit quickSearchTextChanged(this->ui->quickSearchEdit->text());
}

void MainWindow::returnFromRentSubmitted(Rent* r) {
    emit returnFromRent(r);
    emit quickSearchTextChanged(this->ui->quickSearchEdit->text());
}

void MainWindow::reservationToRentSubmitted(Reservation* r) {
    emit reservationToRent(r);
    emit quickSearchTextChanged(this->ui->quickSearchEdit->text());
}

// buttons' click handlers

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

void MainWindow::onNewReservationClicked() {
    QList<Equipment*> available = EquipmentDAOSingleton::instance()->availableForUsage();

    if (available.isEmpty()) {
        QMessageBox::warning(this, tr("Error"), tr("Could not reserve anything because there is no equipment or there is no equipment with price set"), QMessageBox::Ok);
        return;
    }

    User* u = this->getSelectedUser();
    ReservationForm *win = new ReservationForm();
    win->setUserId(u->getId());
    connect(win, SIGNAL(saveReservation(Reservation*, Reservation*)), this, SLOT(onCreateReservationSubmitted(Reservation*, Reservation*)));
    win->show();
}

void MainWindow::onNewRentClicked() {
    QList<Equipment*> available = EquipmentDAOSingleton::instance()->availableForUsage();

    if (available.isEmpty()) {
        QMessageBox::warning(this, tr("Error"), tr("Could not reserve anything because there is no equipment or there is no equipment with price set"), QMessageBox::Ok);
        return;
    }

    User* u = this->getSelectedUser();
    RentForm *win = new RentForm();
    win->setUserId(u->getId());
    connect(win, SIGNAL(saveRent(Rent*, Rent*)), this, SLOT(onCreateRentSubmitted(Rent*, Rent*)));
    win->show();
}

void MainWindow::onEditRentClicked() {
    QList<Rent*> rents = this->getSelectedRents();

    for (int i = 0; i < rents.size(); i++) {
        Rent* rent = rents.at(i);
        RentForm* win = new RentForm();
        win->setRent(rent);
        connect(win, SIGNAL(saveRent(Rent*, Rent*)), this, SLOT(onUpdateRentSubmitted(Rent*, Rent*)));
        win->show();
    }
}

QList<History*> MainWindow::returnFromRent(QList<Rent*> entries) {
    QDateTime now = QDateTime::currentDateTime();
    QList<History*> results;

    for (int i = 0; i < entries.size(); i++) {
        Rent* e = entries.at(i);
        int time = abs(e->getRentFrom().msecsTo(now));
        time /= (1000 * 60 * 60); // hours
        User *user = UserDAOSingleton::instance()->findById(e->getUserId());
        Equipment *equipment = EquipmentDAOSingleton::instance()->findById(e->getEquipmentId());
        Price *price = PriceDAOSingleton::instance()->find(equipment->getType(), equipment->getCondition(), time)[0];

        HistoryDAOSingleton::instance()->create(user, equipment, e, now, price);
        RentDAOSingleton::instance()->remove(e);

        History* resultRow = new History();
        resultRow->setAmount(e->getAmount());
        resultRow->setType(equipment->getType());
        resultRow->setCondition(equipment->getCondition());
        resultRow->setPrice(price->getPrice());
        resultRow->setRentFrom(e->getRentFrom());
        resultRow->setRentTo(now);

        results.append(resultRow);
    }

    return results;
}

void MainWindow::onNewReturnClicked() {
    if (QMessageBox::question(this, tr("Are you sure?"), tr("Are these returns correct?"), QMessageBox::Yes, QMessageBox::No) != QMessageBox::Yes) {
        return;
    }

    QList<Rent*> rents = this->getSelectedRents();
    QList<History*> results = this->returnFromRent(rents);

    emit quickSearchTextChanged(this->ui->quickSearchEdit->text());

    BillForm* win = new BillForm(results);
    win->show();
}

void MainWindow::onReservationToRentClicked() {
    Reservation *reservation = this->getSelectedReservation();

    if (QMessageBox::question(this, tr("Are you sure?"), tr("Is this reservation correct?"), QMessageBox::Yes, QMessageBox::No) == QMessageBox::Yes) {
        emit reservationToRentSubmitted(reservation);
        emit quickSearchTextChanged(this->ui->quickSearchEdit->text());
    }
}

void MainWindow::onEditReservationClicked() {
    Reservation *r = this->getSelectedReservation();
    ReservationForm *win = new ReservationForm();
    win->setReservation(r);
    connect(win, SIGNAL(saveReservation(Reservation*, Reservation*)), this, SLOT(onUpdateReservationSubmitted(Reservation*, Reservation*)));
    win->show();
}

void MainWindow::onCancelReservationClicked() {
    Reservation *reservation = this->getSelectedReservation();

    if (QMessageBox::question(this, tr("Are you sure?"), tr("Is this reservation cancel correct?"), QMessageBox::Yes, QMessageBox::No) == QMessageBox::Yes) {
        emit reservationCancel(reservation);
        emit quickSearchTextChanged(this->ui->quickSearchEdit->text());
    }
}

void MainWindow::onCreatePriceClicked() {
    PriceForm *win = new PriceForm();
    connect(win, SIGNAL(savePrice(Price*)), this, SLOT(onCreatePriceSubmitted(Price*)));
    win->show();
}

void MainWindow::onEditPriceClicked() {
    Price *p = this->getSelectedPrice();
    PriceForm *win = new PriceForm();
    win->setPrice(p);
    connect(win, SIGNAL(savePrice(Price*)), this, SLOT(onUpdatePriceSubmitted(Price*)));
    win->show();
}

void MainWindow::onDeletePriceClicked() {
    Price *p = this->getSelectedPrice();

    if (QMessageBox::question(this, tr("Are you sure?"), tr("Sure, you want to remove this price?"), QMessageBox::Yes, QMessageBox::No) == QMessageBox::Yes) {
        emit removePrice(p);
        emit quickSearchTextChanged(this->ui->quickSearchEdit->text());
    }
}

// row selected handlers

void MainWindow::onPriceRowSelected(QModelIndex index) {
    if (this->ui->priceList->selectionModel()->hasSelection()) {
        this->ui->editPriceButton->setEnabled(true);
        this->ui->deletePriceButton->setEnabled(true);
    } else {
        this->ui->editPriceButton->setEnabled(false);
        this->ui->deletePriceButton->setEnabled(false);
    }
}

void MainWindow::onReservationRowSelected(QModelIndex index) {
    if (this->ui->reservationList->selectionModel()->hasSelection()) {
        this->ui->reservationToRentButton->setEnabled(true);
        this->ui->editReservationButton->setEnabled(true);
        this->ui->cancelReservationButton->setEnabled(true);
    } else {
        this->ui->reservationToRentButton->setEnabled(false);
        this->ui->editReservationButton->setEnabled(false);
        this->ui->cancelReservationButton->setEnabled(false);
    }
}

void MainWindow::onRentRowSelected(QModelIndex index) {
    if (this->ui->rentList->selectionModel()->selectedRows().size() > 0) {
        this->ui->editRentButton->setEnabled(true);
        this->ui->newReturnButton->setEnabled(true);
    } else {
        this->ui->editRentButton->setEnabled(false);
        this->ui->newReturnButton->setEnabled(false);
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
        this->ui->newReservationButton->setEnabled(true);
        this->ui->newRentButton->setEnabled(true);
    } else {
        this->ui->editUserButton->setEnabled(false);
        this->ui->deleteUserButton->setEnabled(false);
        this->ui->newReservationButton->setEnabled(false);
        this->ui->newRentButton->setEnabled(false);
    }
}

// selected entity getters

Price* MainWindow::getSelectedPrice() {
    int index = this->ui->priceList->selectionModel()->selectedRows().at(0).row();
    return this->priceRowModel->at(index);
}

Reservation* MainWindow::getSelectedReservation() {
    int index = this->ui->reservationList->selectionModel()->selectedRows().at(0).row();
    return this->reservationRowModel->at(index);
}

QList<Rent*> MainWindow::getSelectedRents() {
    QModelIndexList indices = this->ui->rentList->selectionModel()->selectedRows();
    QList<Rent*> res;

    for (int i = 0; i < indices.size(); i++) {
        int index = indices.at(i).row();
        res.append(this->rentRowModel->at(index));
    }

    return res;
}

Equipment* MainWindow::getSelectedEquipment() {
    int index = this->ui->equipmentList->selectionModel()->selectedRows().at(0).row();
    return this->equipmentRowModel->at(index);
}

User* MainWindow::getSelectedUser() {
    int index = this->ui->userList->selectionModel()->selectedRows().at(0).row();
    return this->userRowModel->at(index);
}
