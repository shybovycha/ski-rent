/********************************************************************************
** Form generated from reading UI file 'configurationwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGURATIONWINDOW_H
#define UI_CONFIGURATIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConfigurationWindow
{
public:
    QGridLayout *gridLayout;
    QToolBox *toolBox;
    QWidget *page;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *databaseUri;
    QLabel *label_2;
    QLineEdit *databaseUserEdit;
    QLabel *label_3;
    QLineEdit *databasePasswordEdit;
    QLabel *label_4;
    QLineEdit *databaseNameEdit;
    QSpacerItem *verticalSpacer;
    QWidget *page_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *saveButton;
    QPushButton *cancelButton;

    void setupUi(QWidget *ConfigurationWindow)
    {
        if (ConfigurationWindow->objectName().isEmpty())
            ConfigurationWindow->setObjectName(QStringLiteral("ConfigurationWindow"));
        ConfigurationWindow->resize(651, 343);
        gridLayout = new QGridLayout(ConfigurationWindow);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        toolBox = new QToolBox(ConfigurationWindow);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        toolBox->setEnabled(true);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        page->setGeometry(QRect(0, 0, 633, 236));
        gridLayout_2 = new QGridLayout(page);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(page);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        databaseUri = new QLineEdit(page);
        databaseUri->setObjectName(QStringLiteral("databaseUri"));

        verticalLayout->addWidget(databaseUri);

        label_2 = new QLabel(page);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        databaseUserEdit = new QLineEdit(page);
        databaseUserEdit->setObjectName(QStringLiteral("databaseUserEdit"));

        verticalLayout->addWidget(databaseUserEdit);

        label_3 = new QLabel(page);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        databasePasswordEdit = new QLineEdit(page);
        databasePasswordEdit->setObjectName(QStringLiteral("databasePasswordEdit"));
        databasePasswordEdit->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(databasePasswordEdit);

        label_4 = new QLabel(page);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);

        databaseNameEdit = new QLineEdit(page);
        databaseNameEdit->setObjectName(QStringLiteral("databaseNameEdit"));

        verticalLayout->addWidget(databaseNameEdit);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);

        toolBox->addItem(page, QStringLiteral("Database"));
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        page_2->setEnabled(false);
        page_2->setGeometry(QRect(0, 0, 633, 236));
        toolBox->addItem(page_2, QStringLiteral("WIP"));

        gridLayout->addWidget(toolBox, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        saveButton = new QPushButton(ConfigurationWindow);
        saveButton->setObjectName(QStringLiteral("saveButton"));

        horizontalLayout->addWidget(saveButton);

        cancelButton = new QPushButton(ConfigurationWindow);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout->addWidget(cancelButton);


        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 1);


        retranslateUi(ConfigurationWindow);

        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ConfigurationWindow);
    } // setupUi

    void retranslateUi(QWidget *ConfigurationWindow)
    {
        ConfigurationWindow->setWindowTitle(QApplication::translate("ConfigurationWindow", "SkiRent - configuration", 0));
        label->setText(QApplication::translate("ConfigurationWindow", "Database address and port:", 0));
        label_2->setText(QApplication::translate("ConfigurationWindow", "Database user:", 0));
        label_3->setText(QApplication::translate("ConfigurationWindow", "Database password:", 0));
        databasePasswordEdit->setInputMask(QString());
        label_4->setText(QApplication::translate("ConfigurationWindow", "Database name:", 0));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("ConfigurationWindow", "Database", 0));
        toolBox->setItemText(toolBox->indexOf(page_2), QApplication::translate("ConfigurationWindow", "WIP", 0));
        saveButton->setText(QApplication::translate("ConfigurationWindow", "Save", 0));
        cancelButton->setText(QApplication::translate("ConfigurationWindow", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class ConfigurationWindow: public Ui_ConfigurationWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGURATIONWINDOW_H
