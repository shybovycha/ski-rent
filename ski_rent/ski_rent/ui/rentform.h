#ifndef RENTFORM_H
#define RENTFORM_H

#include <QWidget>

namespace Ui {
class RentForm;
}

class RentForm : public QWidget
{
    Q_OBJECT

public:
    explicit RentForm(QWidget *parent = 0);
    ~RentForm();

private:
    Ui::RentForm *ui;
};

#endif // RENTFORM_H
