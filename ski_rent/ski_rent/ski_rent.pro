#-------------------------------------------------
#
# Project created by QtCreator 2015-03-24T08:36:44
#
#-------------------------------------------------

QT       += core gui sql

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
    userform.cpp \
    userdao.cpp \
    user.cpp \
    baseentity.cpp \
    databaseconnector.cpp \
    databaseadapter.cpp \
    mysqladapter.cpp \
    basedao.cpp \
    userquerybuilder.cpp \
    userentityconverter.cpp \
    equipment.cpp \
    equipmentdao.cpp \
    equipmentquerybuilder.cpp \
    equipmnetentityconverter.cpp \
    rent.cpp \
    rententityconverter.cpp \
    rentquerybuilder.cpp \
    rentdao.cpp \
    history.cpp \
    historydao.cpp \
    historyquerybuilder.cpp \
    historyentityconverter.cpp \
    reservation.cpp \
    reservationdao.cpp \
    reservationquerybuilder.cpp \
    reservationentityconverter.cpp

HEADERS  += mainwindow.h \
    welcomewindow.h \
    configurationwindow.h \
    equipmentform.h \
    rentform.h \
    reservationform.h \
    priceform.h \
    userform.h \
    userdao.h \
    user.h \
    baseentity.h \
    databaseconnector.h \
    databaseadapter.h \
    mysqladapter.h \
    dbrow.h \
    entityconverter.h \
    basedao.h \
    querybuilder.h \
    equipment.h \
    equipmentdao.h \
    rent.h \
    rentdao.h \
    rentquerybuilder.h \
    history.h \
    historydao.h \
    historyquerybuilder.h \
    reservation.h \
    reservationdao.h \
    reservationquerybuilder.h

FORMS    += mainwindow.ui \
    welcomewindow.ui \
    configurationwindow.ui \
    equipmentform.ui \
    rentform.ui \
    reservationform.ui \
    priceform.ui \
    userform.ui

LIBS += -L/home/shybovycha/Qt/5.4/gcc_64/lib/ -lmysqlclient
