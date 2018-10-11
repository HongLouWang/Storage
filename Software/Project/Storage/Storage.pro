#-------------------------------------------------
#
# Project created by QtCreator 2018-10-10T06:01:53
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Storage
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        login.cpp \
    f_login.cpp \
    ../../Pullman/Main/pullman_main.cpp \
    ../../Pullman/ControlPannel/controlpannel.cpp \
    ../../Pullman/Main/p_fetchdata.cpp \
    pullman_logistics_trace.cpp \
    ../../Pullman/Logistics_Trace/pullman_logistics_trace.cpp

HEADERS += \
        login.h \
    include.h \
    ../../Pullman/database.h \
    f_login.h \
    ../../Pullman/Main/pullman_main.h \
    ../../Pullman/ControlPannel/controlpannel.h \
    windows.h \
    ../../Pullman/Main/p_fetchdata.h \
    pullman_logistics_trace.h \
    ../../Pullman/Logistics_Trace/pullman_logistics_trace.h

FORMS += \
        login.ui \
    ../../Pullman/Main/pullman_main.ui \
    ../../Pullman/ControlPannel/controlpannel.ui \
    pullman_logistics_trace.ui \
    ../../Pullman/Logistics_Trace/pullman_logistics_trace.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
INCLUDEPATH += D:/Work/Storage/Software/Pullman/
INCLUDEPATH += D:/Work/Storage/Software/Pullman/Main
INCLUDEPATH += D:/Work/Storage/Software/Pullman/ControlPannel
