#ifndef USERFORM_H
#define USERFORM_H

#include <QWidget>

#include "entities/user.h"

namespace Ui {
class UserForm;
}

class UserForm : public QWidget
{
    Q_OBJECT

public:
    explicit UserForm(QWidget *parent = 0);
    ~UserForm();

    void setUser(User* u);

public slots:
    void onSaveClicked();
    void onCancelClicked();

signals:
    void saveUser(User* u);

private:
    Ui::UserForm *ui;
    User* user;
};

#endif // USERFORM_H
