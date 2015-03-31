/********************************************************************************
** Form generated from reading UI file 'priceform.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRICEFORM_H
#define UI_PRICEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
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

class Ui_PriceForm
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QComboBox *typeCombo;
    QLabel *label_2;
    QComboBox *conditionCombo;
    QLabel *label_3;
    QSpinBox *timeSpin;
    QLabel *label_4;
    QDoubleSpinBox *priceSpin;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *saveButton;
    QPushButton *cancelButton;

    void setupUi(QWidget *PriceForm)
    {
        if (PriceForm->objectName().isEmpty())
            PriceForm->setObjectName(QStringLiteral("PriceForm"));
        PriceForm->resize(535, 261);
        gridLayout = new QGridLayout(PriceForm);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(PriceForm);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        typeCombo = new QComboBox(PriceForm);
        typeCombo->setObjectName(QStringLiteral("typeCombo"));

        verticalLayout->addWidget(typeCombo);

        label_2 = new QLabel(PriceForm);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        conditionCombo = new QComboBox(PriceForm);
        conditionCombo->setObjectName(QStringLiteral("conditionCombo"));

        verticalLayout->addWidget(conditionCombo);

        label_3 = new QLabel(PriceForm);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        timeSpin = new QSpinBox(PriceForm);
        timeSpin->setObjectName(QStringLiteral("timeSpin"));

        verticalLayout->addWidget(timeSpin);

        label_4 = new QLabel(PriceForm);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);

        priceSpin = new QDoubleSpinBox(PriceForm);
        priceSpin->setObjectName(QStringLiteral("priceSpin"));

        verticalLayout->addWidget(priceSpin);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        saveButton = new QPushButton(PriceForm);
        saveButton->setObjectName(QStringLiteral("saveButton"));

        horizontalLayout->addWidget(saveButton);

        cancelButton = new QPushButton(PriceForm);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout->addWidget(cancelButton);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);


        retranslateUi(PriceForm);

        QMetaObject::connectSlotsByName(PriceForm);
    } // setupUi

    void retranslateUi(QWidget *PriceForm)
    {
        PriceForm->setWindowTitle(QApplication::translate("PriceForm", "SkiRent - price", 0));
        label->setText(QApplication::translate("PriceForm", "Equipment:", 0));
        label_2->setText(QApplication::translate("PriceForm", "Condition:", 0));
        label_3->setText(QApplication::translate("PriceForm", "Time:", 0));
        label_4->setText(QApplication::translate("PriceForm", "Price:", 0));
        saveButton->setText(QApplication::translate("PriceForm", "Save", 0));
        cancelButton->setText(QApplication::translate("PriceForm", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class PriceForm: public Ui_PriceForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRICEFORM_H
