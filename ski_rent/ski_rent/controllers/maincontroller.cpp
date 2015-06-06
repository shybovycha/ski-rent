#include "controllers/maincontroller.h"

MainController::MainController(QObject *parent) : QObject(parent) {
    this->view = new MainWindow();

    connect(this->view, SIGNAL(quickSearchTextChanged(QString)), this, SLOT(find(QString)));

    connect(this->view, SIGNAL(createEquipment(Equipment*)), EquipmentControllerSingleton::instance(), SLOT(createEquipment(Equipment*)));
    connect(this->view, SIGNAL(updateEquipment(Equipment*)), EquipmentControllerSingleton::instance(), SLOT(updateEquipment(Equipment*)));
    connect(this->view, SIGNAL(deleteEquipment(int)), EquipmentControllerSingleton::instance(), SLOT(deleteEquipment(int)));

    connect(this->view, SIGNAL(createUser(User*)), UsersControllerSingleton::instance(), SLOT(createUser(User*)));
    connect(this->view, SIGNAL(updateUser(User*)), UsersControllerSingleton::instance(), SLOT(updateUser(User*)));
    connect(this->view, SIGNAL(deleteUser(int)), UsersControllerSingleton::instance(), SLOT(deleteUser(int)));

    connect(this->view, SIGNAL(createPrice(Price*)), PriceControllerSingleton::instance(), SLOT(createPrice(Price*)));
    connect(this->view, SIGNAL(updatePrice(QString, char, int, Price*)), PriceControllerSingleton::instance(), SLOT(updatePrice(QString, char, int, Price*)));
    connect(this->view, SIGNAL(deletePrice(QString, char, int)), PriceControllerSingleton::instance(), SLOT(deletePrice(QString, char, int)));

    connect(this->view, SIGNAL(createReservation(Reservation*)), ReservationsControllerSingleton::instance(), SLOT(createReservation(Reservation*)));
    connect(this->view, SIGNAL(updateReservation(Reservation*, Reservation*)), ReservationsControllerSingleton::instance(), SLOT(updateReservation(Reservation*, Reservation*)));
    connect(this->view, SIGNAL(reservationCancel(Reservation*)), ReservationsControllerSingleton::instance(), SLOT(cancelReservation(Reservation*)));

    connect(this->view, SIGNAL(createRent(Rent*)), RentControllerSingleton::instance(), SLOT(createRent(Rent*)));
    connect(this->view, SIGNAL(updateRent(int, int, Rent*)), RentControllerSingleton::instance(), SLOT(updateRent(int, int, Rent*)));

    connect(this->view, SIGNAL(reservationToRent(Reservation*)), ReservationsControllerSingleton::instance(), SLOT(reservationToRent(Reservation*)));
    connect(this->view, SIGNAL(returnFromRent(Rent*)), RentControllerSingleton::instance(), SLOT(returnFromRent(Rent*)));
}

MainController::~MainController() {
    delete this->view;
}

void MainController::index() {
    this->view->setUsers(UserDAOSingleton::instance()->all());
    this->view->setEquipment(EquipmentDAOSingleton::instance()->all());
    this->view->setRents(RentDAOSingleton::instance()->all());
    this->view->setReservations(ReservationDAOSingleton::instance()->all());
    this->view->setPrices(PriceDAOSingleton::instance()->all());

    this->view->show();
}

void MainController::find(QString query) {
    query = query.trimmed();

    this->view->setUsers(UserDAOSingleton::instance()->find(query));
    this->view->setEquipment(EquipmentDAOSingleton::instance()->find(query));
    this->view->setRents(RentDAOSingleton::instance()->find(query));
    this->view->setReservations(ReservationDAOSingleton::instance()->find(query));
    this->view->setPrices(PriceDAOSingleton::instance()->find(query));

    this->view->show();
}

void MainController::availableEquipment() {
    this->view->setEquipment(EquipmentDAOSingleton::instance()->available());

    this->view->show();
}
