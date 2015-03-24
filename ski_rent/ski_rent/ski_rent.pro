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
    configurationwindow.cpp

HEADERS  += mainwindow.h \
    welcomewindow.h \
    configurationwindow.h

FORMS    += mainwindow.ui \
    welcomewindow.ui \
    configurationwindow.ui
