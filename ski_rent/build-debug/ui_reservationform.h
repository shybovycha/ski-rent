/********************************************************************************
** Form generated from reading UI file 'reservationform.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESERVATIONFORM_H
#define UI_RESERVATIONFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReservationForm
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QComboBox *equipmentTypeCombo;
    QLabel *label_3;
    QComboBox *equipmentConditionCombo;
    QLabel *label_2;
    QSpinBox *amountSpin;
    QLabel *label_4;
    QDateEdit *rentFromEdit;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton;

    void setupUi(QWidget *ReservationForm)
    {
        if (ReservationForm->objectName().isEmpty())
            ReservationForm->setObjectName(QStringLiteral("ReservationForm"));
        ReservationForm->resize(514, 300);
        gridLayout = new QGridLayout(ReservationForm);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(ReservationForm);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        equipmentTypeCombo = new QComboBox(ReservationForm);
        equipmentTypeCombo->setObjectName(QStringLiteral("equipmentTypeCombo"));
        equipmentTypeCombo->setEditable(true);

        verticalLayout->addWidget(equipmentTypeCombo);

        label_3 = new QLabel(ReservationForm);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        equipmentConditionCombo = new QComboBox(ReservationForm);
        equipmentConditionCombo->setObjectName(QStringLiteral("equipmentConditionCombo"));

        verticalLayout->addWidget(equipmentConditionCombo);

        label_2 = new QLabel(ReservationForm);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        amountSpin = new QSpinBox(ReservationForm);
        amountSpin->setObjectName(QStringLiteral("amountSpin"));

        verticalLayout->addWidget(amountSpin);

        label_4 = new QLabel(ReservationForm);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);

        rentFromEdit = new QDateEdit(ReservationForm);
        rentFromEdit->setObjectName(QStringLiteral("rentFromEdit"));

        verticalLayout->addWidget(rentFromEdit);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_2 = new QPushButton(ReservationForm);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(ReservationForm);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);


        retranslateUi(ReservationForm);

        QMetaObject::connectSlotsByName(ReservationForm);
    } // setupUi

    void retranslateUi(QWidget *ReservationForm)
    {
        ReservationForm->setWindowTitle(QApplication::translate("ReservationForm", "SkiRent - reservation", 0));
        label->setText(QApplication::translate("ReservationForm", "Equipment:", 0));
        label_3->setText(QApplication::translate("ReservationForm", "Condition:", 0));
        label_2->setText(QApplication::translate("ReservationForm", "Amount:", 0));
        label_4->setText(QApplication::translate("ReservationForm", "Rent from:", 0));
        pushButton_2->setText(QApplication::translate("ReservationForm", "Save", 0));
        pushButton->setText(QApplication::translate("ReservationForm", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class ReservationForm: public Ui_ReservationForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESERVATIONFORM_H
