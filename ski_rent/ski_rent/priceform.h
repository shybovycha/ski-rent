#ifndef PRICEFORM_H
#define PRICEFORM_H

#include <QWidget>

namespace Ui {
class PriceForm;
}

class PriceForm : public QWidget
{
    Q_OBJECT

public:
    explicit PriceForm(QWidget *parent = 0);
    ~PriceForm();

private:
    Ui::PriceForm *ui;
};

#endif // PRICEFORM_H
