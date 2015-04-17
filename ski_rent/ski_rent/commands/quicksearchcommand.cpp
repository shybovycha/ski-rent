#include "quicksearchcommand.h"
#include "ui/mainwindow.h"

QuickSearchCommand::QuickSearchCommand(QString q, QWidget* w) : BaseCommand()
{
    this->query = q;
    this->target = w;
}

QuickSearchCommand::~QuickSearchCommand()
{

}

void QuickSearchCommand::routine() {
    ((MainWindow*) this->target)->setEquipment(EquipmentDAO::getSingletonPtr()->find(this->query));
    ((MainWindow*) this->target)->setUsers(UserDAO::getSingletonPtr()->find(this->query));
//    this->target->setRents(RentDAO::getSingletonPtr()->find(this->query));
//    this->target->setReservations(ReservationsDAO::getSingletonPtr()->find(this->query));
}
