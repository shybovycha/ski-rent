#include "controllers/maincontroller.h"
// #include "controllers/equipmentcontroller.h"

MainController::MainController(QObject *parent) : QObject(parent) {
    this->view = new MainWindow();

    connect(this->view, SIGNAL(quickSearchTextChanged(QString)), this, SLOT(find(QString)));

    connect(this->view, SIGNAL(createEquipment(Equipment*)), EquipmentControllerSingleton::instance(), SLOT(createEquipment(Equipment*)));
    connect(this->view, SIGNAL(updateEquipment(Equipment*)), EquipmentControllerSingleton::instance(), SLOT(updateEquipment(Equipment*)));
    connect(this->view, SIGNAL(deleteEquipment(int)), EquipmentControllerSingleton::instance(), SLOT(deleteEquipment(int)));

    connect(this->view, SIGNAL(createUser(User*)), UsersControllerSingleton::instance(), SLOT(createUser(User*)));
    connect(this->view, SIGNAL(updateUser(User*)), UsersControllerSingleton::instance(), SLOT(updateUser(User*)));
    connect(this->view, SIGNAL(deleteUser(int)), UsersControllerSingleton::instance(), SLOT(deleteUser(int)));

    // EquipmentController* equipmentController = EquipmentControllerSingleton::instance();
    // connect(this->view, SIGNAL(create(QString)), equipmentController, SLOT(find(QString)));
}

MainController::~MainController() {
    delete this->view;
}

void MainController::index() {
    this->view->setUsers(UserDAOSingleton::instance()->all());
    this->view->setEquipment(EquipmentDAOSingleton::instance()->all());

    this->view->show();
}

void MainController::find(QString query) {
    this->view->setUsers(UserDAOSingleton::instance()->find(query));
    this->view->setEquipment(EquipmentDAOSingleton::instance()->find(query));

    this->view->show();
}

void MainController::availableEquipment() {
    this->view->setEquipment(EquipmentDAOSingleton::instance()->available());

    this->view->show();
}
