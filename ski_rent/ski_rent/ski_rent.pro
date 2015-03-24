#-------------------------------------------------
#
# Project created by QtCreator 2015-03-24T08:36:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ski_rent
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    welcomewindow.cpp \
    configurationwindow.cpp \
    equipmentform.cpp \
    rentform.cpp \
    reservationform.cpp \
    priceform.cpp \
    userform.cpp

HEADERS  += mainwindow.h \
    welcomewindow.h \
    configurationwindow.h \
    equipmentform.h \
    rentform.h \
    reservationform.h \
    priceform.h \
    userform.h

FORMS    += mainwindow.ui \
    welcomewindow.ui \
    configurationwindow.ui \
    equipmentform.ui \
    rentform.ui \
    reservationform.ui \
    priceform.ui \
    userform.ui
