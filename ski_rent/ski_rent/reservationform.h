#ifndef RESERVATIONFORM_H
#define RESERVATIONFORM_H

#include <QWidget>

namespace Ui {
class ReservationForm;
}

class ReservationForm : public QWidget
{
    Q_OBJECT

public:
    explicit ReservationForm(QWidget *parent = 0);
    ~ReservationForm();

private:
    Ui::ReservationForm *ui;
};

#endif // RESERVATIONFORM_H
