/********************************************************************************
** Form generated from reading UI file 'equipmentform.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EQUIPMENTFORM_H
#define UI_EQUIPMENTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EquipmentForm
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *typeEdit;
    QLabel *label_2;
    QSpinBox *amountSpin;
    QLabel *label_3;
    QComboBox *conditionCombo;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *saveButton;
    QPushButton *cancelButton;

    void setupUi(QWidget *EquipmentForm)
    {
        if (EquipmentForm->objectName().isEmpty())
            EquipmentForm->setObjectName(QStringLiteral("EquipmentForm"));
        EquipmentForm->resize(536, 209);
        gridLayout = new QGridLayout(EquipmentForm);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(EquipmentForm);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        typeEdit = new QLineEdit(EquipmentForm);
        typeEdit->setObjectName(QStringLiteral("typeEdit"));

        verticalLayout->addWidget(typeEdit);

        label_2 = new QLabel(EquipmentForm);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        amountSpin = new QSpinBox(EquipmentForm);
        amountSpin->setObjectName(QStringLiteral("amountSpin"));

        verticalLayout->addWidget(amountSpin);

        label_3 = new QLabel(EquipmentForm);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        conditionCombo = new QComboBox(EquipmentForm);
        conditionCombo->setObjectName(QStringLiteral("conditionCombo"));

        verticalLayout->addWidget(conditionCombo);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        saveButton = new QPushButton(EquipmentForm);
        saveButton->setObjectName(QStringLiteral("saveButton"));

        horizontalLayout->addWidget(saveButton);

        cancelButton = new QPushButton(EquipmentForm);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout->addWidget(cancelButton);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);


        retranslateUi(EquipmentForm);

        QMetaObject::connectSlotsByName(EquipmentForm);
    } // setupUi

    void retranslateUi(QWidget *EquipmentForm)
    {
        EquipmentForm->setWindowTitle(QApplication::translate("EquipmentForm", "SkiRent - equipment", 0));
        label->setText(QApplication::translate("EquipmentForm", "Type:", 0));
        label_2->setText(QApplication::translate("EquipmentForm", "Amount:", 0));
        label_3->setText(QApplication::translate("EquipmentForm", "Condition:", 0));
        saveButton->setText(QApplication::translate("EquipmentForm", "Save", 0));
        cancelButton->setText(QApplication::translate("EquipmentForm", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class EquipmentForm: public Ui_EquipmentForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EQUIPMENTFORM_H
