#include "controllers/maincontroller.h"

MainController::MainController(QObject *parent) : QObject(parent) {
    this->view = new MainWindow();
    this->userDao = new UserDAO();
    this->equipmentDao = new EquipmentDAO();

    connect(this->view, SIGNAL(quickSearchTextChanged(QString)), this, SLOT(find(QString)));
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
    this->view->setUsers(this->userDao->all());
    this->view->setEquipment(this->equipmentDao->all());

    this->view->show();
}

void MainController::find(QString query) {
    this->view->setUsers(this->userDao->find(query));
    this->view->setEquipment(this->equipmentDao->find(query));

    this->view->show();
}

void MainController::availableEquipment() {
    this->view->setEquipment(this->equipmentDao->available());

    this->view->show();
}
