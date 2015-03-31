/********************************************************************************
** Form generated from reading UI file 'rentform.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RENTFORM_H
#define UI_RENTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RentForm
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QComboBox *equipmentTypeCombo;
    QLabel *label_2;
    QComboBox *equipmentConditionCombo;
    QLabel *label_3;
    QSpinBox *amountSpin;
    QLabel *label_4;
    QLCDNumber *pricePerHourLcd;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *saveButton;
    QPushButton *cancelButton;

    void setupUi(QWidget *RentForm)
    {
        if (RentForm->objectName().isEmpty())
            RentForm->setObjectName(QStringLiteral("RentForm"));
        RentForm->resize(705, 300);
        gridLayout = new QGridLayout(RentForm);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(RentForm);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        equipmentTypeCombo = new QComboBox(RentForm);
        equipmentTypeCombo->setObjectName(QStringLiteral("equipmentTypeCombo"));
        equipmentTypeCombo->setEditable(true);

        verticalLayout->addWidget(equipmentTypeCombo);

        label_2 = new QLabel(RentForm);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        equipmentConditionCombo = new QComboBox(RentForm);
        equipmentConditionCombo->setObjectName(QStringLiteral("equipmentConditionCombo"));

        verticalLayout->addWidget(equipmentConditionCombo);

        label_3 = new QLabel(RentForm);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        amountSpin = new QSpinBox(RentForm);
        amountSpin->setObjectName(QStringLiteral("amountSpin"));

        verticalLayout->addWidget(amountSpin);

        label_4 = new QLabel(RentForm);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);

        pricePerHourLcd = new QLCDNumber(RentForm);
        pricePerHourLcd->setObjectName(QStringLiteral("pricePerHourLcd"));

        verticalLayout->addWidget(pricePerHourLcd);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        saveButton = new QPushButton(RentForm);
        saveButton->setObjectName(QStringLiteral("saveButton"));

        horizontalLayout->addWidget(saveButton);

        cancelButton = new QPushButton(RentForm);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout->addWidget(cancelButton);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);


        retranslateUi(RentForm);

        QMetaObject::connectSlotsByName(RentForm);
    } // setupUi

    void retranslateUi(QWidget *RentForm)
    {
        RentForm->setWindowTitle(QApplication::translate("RentForm", "SkiRent - rent", 0));
        label->setText(QApplication::translate("RentForm", "Equipment:", 0));
        label_2->setText(QApplication::translate("RentForm", "Condition:", 0));
        label_3->setText(QApplication::translate("RentForm", "Amount:", 0));
        label_4->setText(QApplication::translate("RentForm", "Price per hour:", 0));
        saveButton->setText(QApplication::translate("RentForm", "Save", 0));
        cancelButton->setText(QApplication::translate("RentForm", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class RentForm: public Ui_RentForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RENTFORM_H
