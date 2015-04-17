#include "controllers/maincontroller.h"
// #include "controllers/equipmentcontroller.h"

MainController::MainController(QObject *parent) : QObject(parent) {
    this->view = new MainWindow();
//    this->userDao = new UserDAO();
//    this->equipmentDao = new EquipmentDAO();

    connect(this->view, SIGNAL(quickSearchTextChanged(QString)), this, SLOT(find(QString)));

    connect(this->view, SIGNAL(createEquipment(Equipment)), EquipmentController::getSingletonPtr(), SLOT(createEquipment(Equipment)));
    connect(this->view, SIGNAL(updateEquipment(Equipment)), EquipmentController::getSingletonPtr(), SLOT(updateEquipment(Equipment)));
    connect(this->view, SIGNAL(deleteEquipment(int)), EquipmentController::getSingletonPtr(), SLOT(deleteEquipment(int)));

    connect(this->view, SIGNAL(createUser(User)), UsersController::getSingletonPtr(), SLOT(createUser(User)));
    connect(this->view, SIGNAL(updateUser(User)), UsersController::getSingletonPtr(), SLOT(updateUser(User)));
    connect(this->view, SIGNAL(deleteUser(int)), UsersController::getSingletonPtr(), SLOT(deleteUser(int)));

    // EquipmentController* equipmentController = EquipmentController::getSingletonPtr();
    // connect(this->view, SIGNAL(create(QString)), equipmentController, SLOT(find(QString)));
}

MainController::~MainController() {
    delete this->view;
}

MainController* MainController::getInstancePtr() {
    static MainController *instance;

    if (!instance) {
        instance = new MainController();
    }

    return instance;
}

void MainController::index() {
    this->view->setUsers(UserDAO::getSingletonPtr()->all());
    this->view->setEquipment(EquipmentDAO::getSingletonPtr()->all());

    this->view->show();
}

void MainController::find(QString query) {
    this->view->setUsers(UserDAO::getSingletonPtr()->find(query));
    this->view->setEquipment(EquipmentDAO::getSingletonPtr()->find(query));

    this->view->show();
}

void MainController::availableEquipment() {
    this->view->setEquipment(((EquipmentDAO*) EquipmentDAO::getSingletonPtr())->available());

    this->view->show();
}
