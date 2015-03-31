/********************************************************************************
** Form generated from reading UI file 'userform.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERFORM_H
#define UI_USERFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserForm
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_5;
    QComboBox *countryCombo;
    QLabel *label_6;
    QComboBox *cityCombo;
    QLabel *label_7;
    QLineEdit *addressEdit;
    QLabel *label_8;
    QLineEdit *phoneEdit;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *nameEdit;
    QLabel *label_2;
    QLineEdit *surnameEdit;
    QLabel *label_3;
    QComboBox *documentTypeCombo;
    QLabel *label_4;
    QLineEdit *documentNumberEdit;
    QSpacerItem *verticalSpacer;
    QPushButton *saveButton;
    QPushButton *cancelButton;

    void setupUi(QWidget *UserForm)
    {
        if (UserForm->objectName().isEmpty())
            UserForm->setObjectName(QStringLiteral("UserForm"));
        UserForm->resize(584, 261);
        gridLayout = new QGridLayout(UserForm);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_5 = new QLabel(UserForm);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_2->addWidget(label_5);

        countryCombo = new QComboBox(UserForm);
        countryCombo->setObjectName(QStringLiteral("countryCombo"));
        countryCombo->setEditable(true);

        verticalLayout_2->addWidget(countryCombo);

        label_6 = new QLabel(UserForm);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_2->addWidget(label_6);

        cityCombo = new QComboBox(UserForm);
        cityCombo->setObjectName(QStringLiteral("cityCombo"));
        cityCombo->setEditable(true);

        verticalLayout_2->addWidget(cityCombo);

        label_7 = new QLabel(UserForm);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_2->addWidget(label_7);

        addressEdit = new QLineEdit(UserForm);
        addressEdit->setObjectName(QStringLiteral("addressEdit"));

        verticalLayout_2->addWidget(addressEdit);

        label_8 = new QLabel(UserForm);
        label_8->setObjectName(QStringLiteral("label_8"));

        verticalLayout_2->addWidget(label_8);

        phoneEdit = new QLineEdit(UserForm);
        phoneEdit->setObjectName(QStringLiteral("phoneEdit"));

        verticalLayout_2->addWidget(phoneEdit);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        gridLayout->addLayout(verticalLayout_2, 0, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(UserForm);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        nameEdit = new QLineEdit(UserForm);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));

        verticalLayout->addWidget(nameEdit);

        label_2 = new QLabel(UserForm);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        surnameEdit = new QLineEdit(UserForm);
        surnameEdit->setObjectName(QStringLiteral("surnameEdit"));

        verticalLayout->addWidget(surnameEdit);

        label_3 = new QLabel(UserForm);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        documentTypeCombo = new QComboBox(UserForm);
        documentTypeCombo->setObjectName(QStringLiteral("documentTypeCombo"));

        verticalLayout->addWidget(documentTypeCombo);

        label_4 = new QLabel(UserForm);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);

        documentNumberEdit = new QLineEdit(UserForm);
        documentNumberEdit->setObjectName(QStringLiteral("documentNumberEdit"));

        verticalLayout->addWidget(documentNumberEdit);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        saveButton = new QPushButton(UserForm);
        saveButton->setObjectName(QStringLiteral("saveButton"));

        gridLayout->addWidget(saveButton, 1, 0, 1, 1);

        cancelButton = new QPushButton(UserForm);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        gridLayout->addWidget(cancelButton, 1, 1, 1, 1);


        retranslateUi(UserForm);

        QMetaObject::connectSlotsByName(UserForm);
    } // setupUi

    void retranslateUi(QWidget *UserForm)
    {
        UserForm->setWindowTitle(QApplication::translate("UserForm", "SkiRent - user", 0));
        label_5->setText(QApplication::translate("UserForm", "Country:", 0));
        label_6->setText(QApplication::translate("UserForm", "City:", 0));
        label_7->setText(QApplication::translate("UserForm", "Address:", 0));
        label_8->setText(QApplication::translate("UserForm", "Phone:", 0));
        label->setText(QApplication::translate("UserForm", "Name:", 0));
        label_2->setText(QApplication::translate("UserForm", "Surname:", 0));
        label_3->setText(QApplication::translate("UserForm", "Document:", 0));
        label_4->setText(QApplication::translate("UserForm", "Document number:", 0));
        saveButton->setText(QApplication::translate("UserForm", "Save", 0));
        cancelButton->setText(QApplication::translate("UserForm", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class UserForm: public Ui_UserForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERFORM_H
