#-------------------------------------------------
#
# Project created by QtCreator 2015-03-24T08:36:44
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ski_rent
TEMPLATE = app

SOURCES += main.cpp \
    dao/basedao.cpp \
    dao/equipmentdao.cpp \
    dao/historydao.cpp \
    dao/rentdao.cpp \
    dao/reservationdao.cpp \
    dao/userdao.cpp \
    db/databaseadapter.cpp \
    db/databaseconnector.cpp \
    db/mysqladapter.cpp \
    entities/baseentity.cpp \
    entities/equipment.cpp \
    entities/history.cpp \
    entities/rent.cpp \
    entities/reservation.cpp \
    entities/user.cpp \
    entity_converters/equipmnetentityconverter.cpp \
    entity_converters/historyentityconverter.cpp \
    entity_converters/rententityconverter.cpp \
    entity_converters/reservationentityconverter.cpp \
    entity_converters/userentityconverter.cpp \
    query_builders/equipmentquerybuilder.cpp \
    query_builders/historyquerybuilder.cpp \
    query_builders/rentquerybuilder.cpp \
    query_builders/reservationquerybuilder.cpp \
    query_builders/userquerybuilder.cpp \
    ui/configurationwindow.cpp \
    ui/equipmentform.cpp \
    ui/mainwindow.cpp \
    ui/priceform.cpp \
    ui/rentform.cpp \
    ui/reservationform.cpp \
    ui/userform.cpp \
    ui/welcomewindow.cpp \
    dao/pricedao.cpp \
    entities/price.cpp \
    entity_converters/priceentityconverter.cpp \
    query_builders/pricequerybuilder.cpp \
    controllers/maincontroller.cpp \
    controllers/userscontroller.cpp \
    controllers/equipmentcontroller.cpp \
    ui/userrowmodel.cpp \
    ui/equipmenrowtmodel.cpp \
    views/equipmentview.cpp \
    views/mainview.cpp \
    views/userview.cpp \
    commands/createusercommand.c \
    commands/basecommand.cpp \
    commands/deleteusercommand.cpp \
    commands/updateusercommand.cpp \
    commands/createequipmentcommand.cpp \
    commands/deleteequipmentcommand.cpp \
    commands/updateequipmentcommand.cpp \
    commands/quicksearchcommand.cpp \
    commands/compositecommand.cpp

HEADERS  += \
    dao/basedao.h \
    dao/equipmentdao.h \
    dao/historydao.h \
    dao/rentdao.h \
    dao/reservationdao.h \
    dao/userdao.h \
    db/databaseadapter.h \
    db/databaseconnector.h \
    db/dbrow.h \
    db/mysqladapter.h \
    entities/baseentity.h \
    entities/equipment.h \
    entities/history.h \
    entities/rent.h \
    entities/reservation.h \
    entities/user.h \
    entity_converters/entityconverter.h \
    query_builders/historyquerybuilder.h \
    query_builders/querybuilder.h \
    query_builders/rentquerybuilder.h \
    query_builders/reservationquerybuilder.h \
    ui/configurationwindow.h \
    ui/equipmentform.h \
    ui/mainwindow.h \
    ui/priceform.h \
    ui/rentform.h \
    ui/reservationform.h \
    ui/userform.h \
    ui/welcomewindow.h \
    entities/price.h \
    dao/pricedao.h \
    query_builders/pricequerybuilder.h \
    controllers/maincontroller.h \
    controllers/userscontroller.h \
    controllers/equipmentcontroller.h \
    ui/userrowmodel.h \
    ui/equipmentrowmodel.h \
    commands/createusercommand.h \
    views/equipmentview.h \
    views/mainview.h \
    views/userview.h \
    commands/basecommand.h \
    commands/deleteusercommand.h \
    commands/updateusercommand.h \
    commands/createequipmentcommand.h \
    commands/deleteequipmentcommand.h \
    commands/updateequipmentcommand.h \
    commands/quicksearchcommand.h \
    commands/compositecommand.h

FORMS    += \
    ui/configurationwindow.ui \
    ui/equipmentform.ui \
    ui/mainwindow.ui \
    ui/priceform.ui \
    ui/rentform.ui \
    ui/reservationform.ui \
    ui/userform.ui \
    ui/welcomewindow.ui

LIBS += -L/home/shybovycha/Qt/5.4/gcc_64/lib/ -lmysqlclient
