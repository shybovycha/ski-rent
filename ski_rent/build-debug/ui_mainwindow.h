/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QColumnView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QGridLayout *gridLayout;
    QToolBox *toolBox;
    QWidget *rentsPage;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *newReservationButton;
    QPushButton *newRentButton;
    QPushButton *newReturnButton;
    QColumnView *userList;
    QWidget *usersPage;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *createEquipmentButton;
    QPushButton *deleteEquipmentButton;
    QPushButton *editEquipmentButton;
    QColumnView *equipmentList;
    QLineEdit *quickSearchEdit;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(704, 346);
        gridLayout = new QGridLayout(MainWindow);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        toolBox = new QToolBox(MainWindow);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        rentsPage = new QWidget();
        rentsPage->setObjectName(QStringLiteral("rentsPage"));
        rentsPage->setGeometry(QRect(0, 0, 686, 241));
        gridLayout_2 = new QGridLayout(rentsPage);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        newReservationButton = new QPushButton(rentsPage);
        newReservationButton->setObjectName(QStringLiteral("newReservationButton"));

        horizontalLayout->addWidget(newReservationButton);

        newRentButton = new QPushButton(rentsPage);
        newRentButton->setObjectName(QStringLiteral("newRentButton"));

        horizontalLayout->addWidget(newRentButton);

        newReturnButton = new QPushButton(rentsPage);
        newReturnButton->setObjectName(QStringLiteral("newReturnButton"));

        horizontalLayout->addWidget(newReturnButton);


        verticalLayout->addLayout(horizontalLayout);

        userList = new QColumnView(rentsPage);
        userList->setObjectName(QStringLiteral("userList"));
        userList->setAlternatingRowColors(true);
        userList->setSelectionMode(QAbstractItemView::SingleSelection);
        userList->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout->addWidget(userList);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);

        toolBox->addItem(rentsPage, QStringLiteral("Users"));
        usersPage = new QWidget();
        usersPage->setObjectName(QStringLiteral("usersPage"));
        usersPage->setGeometry(QRect(0, 0, 686, 241));
        gridLayout_3 = new QGridLayout(usersPage);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        createEquipmentButton = new QPushButton(usersPage);
        createEquipmentButton->setObjectName(QStringLiteral("createEquipmentButton"));

        horizontalLayout_2->addWidget(createEquipmentButton);

        deleteEquipmentButton = new QPushButton(usersPage);
        deleteEquipmentButton->setObjectName(QStringLiteral("deleteEquipmentButton"));

        horizontalLayout_2->addWidget(deleteEquipmentButton);

        editEquipmentButton = new QPushButton(usersPage);
        editEquipmentButton->setObjectName(QStringLiteral("editEquipmentButton"));

        horizontalLayout_2->addWidget(editEquipmentButton);


        verticalLayout_2->addLayout(horizontalLayout_2);

        equipmentList = new QColumnView(usersPage);
        equipmentList->setObjectName(QStringLiteral("equipmentList"));
        equipmentList->setAlternatingRowColors(true);
        equipmentList->setSelectionMode(QAbstractItemView::SingleSelection);
        equipmentList->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout_2->addWidget(equipmentList);


        gridLayout_3->addLayout(verticalLayout_2, 0, 0, 1, 1);

        toolBox->addItem(usersPage, QStringLiteral("Equipment"));

        gridLayout->addWidget(toolBox, 1, 0, 1, 1);

        quickSearchEdit = new QLineEdit(MainWindow);
        quickSearchEdit->setObjectName(QStringLiteral("quickSearchEdit"));

        gridLayout->addWidget(quickSearchEdit, 0, 0, 1, 1);


        retranslateUi(MainWindow);

        toolBox->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "SkiRent - main", 0));
        newReservationButton->setText(QApplication::translate("MainWindow", "New Reservation", 0));
        newRentButton->setText(QApplication::translate("MainWindow", "New Rent", 0));
        newReturnButton->setText(QApplication::translate("MainWindow", "Return", 0));
        toolBox->setItemText(toolBox->indexOf(rentsPage), QApplication::translate("MainWindow", "Users", 0));
        createEquipmentButton->setText(QApplication::translate("MainWindow", "Create", 0));
        deleteEquipmentButton->setText(QApplication::translate("MainWindow", "Delete", 0));
        editEquipmentButton->setText(QApplication::translate("MainWindow", "Edit", 0));
        toolBox->setItemText(toolBox->indexOf(usersPage), QApplication::translate("MainWindow", "Equipment", 0));
#ifndef QT_NO_TOOLTIP
        quickSearchEdit->setToolTip(QApplication::translate("MainWindow", "Quick Search", 0));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
