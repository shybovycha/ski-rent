#include "views/userview.h"

/*UserView::UserView(QObject *parent) : QObject(parent) {
}*/

UserView::UserView() {
    // this->userForm = new UserForm();
}

UserView::~UserView() {
    // delete this->userForm;
}


void UserView::edit(User user) {
    // this->userForm->ui->name->text(user.getName());
}

void UserView::create() {
    // pass
}

// emit saveUser(getUser());

User UserView::getUser() {
    User result;

    // result.setName(this->userForm->ui->name_edit->text());

    return result;
}

