#-------------------------------------------------
#
# Project created by QtCreator 2018-10-10T06:01:53
#
#-------------------------------------------------

QT       += core gui sql network printsupport serialport

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
    ../../Pullman/Logistics_Trace/pullman_logistics_trace.cpp \
    ../../Pullman/New_Pickup/pullman_new_pickup.cpp \
    ../../Pullman/log.cpp \
    ../../Pullman/New_Customer/pullman_new_customer.cpp \
    ../../Pullman/camera.cpp \
    ../../Pullman/New_Customer/wf_pullman_new_customer.cpp \
    ../../Pullman/qmail.cpp \
    ../../SendMailAPI/emailaddress.cpp \
    ../../SendMailAPI/mimeattachment.cpp \
    ../../SendMailAPI/mimecontentformatter.cpp \
    ../../SendMailAPI/mimefile.cpp \
    ../../SendMailAPI/mimehtml.cpp \
    ../../SendMailAPI/mimeinlinefile.cpp \
    ../../SendMailAPI/mimemessage.cpp \
    ../../SendMailAPI/mimemultipart.cpp \
    ../../SendMailAPI/mimepart.cpp \
    ../../SendMailAPI/mimetext.cpp \
    ../../SendMailAPI/quotedprintable.cpp \
    ../../SendMailAPI/smtpclient.cpp \
    ../../Pullman/New_Freight_Arrive/pullman_new_freight_arrive.cpp \
    ../../Pullman/New_Freight_Arrive/wf_pullman_new_freight_arrive.cpp \
    ../../Pullman/New_Customer/print_pullman_new_customer.cpp \
    getshiefpostable.cpp \
    ../../Pullman/New_Freight_Arrive_Config/pullman_new_freight_arrive_config.cpp

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
    ../../Pullman/Logistics_Trace/pullman_logistics_trace.h \
    ../../Pullman/New_Pickup/pullman_new_pickup.h \
    ../../Pullman/log.h \
    ../../Pullman/userinfo.h \
    ../../Pullman/New_Customer/pullman_new_customer.h \
    ../../Pullman/camera.h \
    ../../Pullman/New_Customer/wf_pullman_new_customer.h \
    ../../Pullman/qmail.h \
    ../../SendMailAPI/emailaddress.h \
    ../../SendMailAPI/mimeattachment.h \
    ../../SendMailAPI/mimecontentformatter.h \
    ../../SendMailAPI/mimefile.h \
    ../../SendMailAPI/mimehtml.h \
    ../../SendMailAPI/mimeinlinefile.h \
    ../../SendMailAPI/mimemessage.h \
    ../../SendMailAPI/mimemultipart.h \
    ../../SendMailAPI/mimepart.h \
    ../../SendMailAPI/mimetext.h \
    ../../SendMailAPI/quotedprintable.h \
    ../../SendMailAPI/smtpclient.h \
    ../../SendMailAPI/smtpmime.h \
    ../../Pullman/New_Freight_Arrive/pullman_new_freight_arrive.h \
    ../../Pullman/New_Freight_Arrive/wf_pullman_new_freight_arrive.h \
    ../../Pullman/New_Customer/print_pullman_new_customer.h \
    getshiefpostable.h \
    shief.h \
    ../../Pullman/New_Freight_Arrive_Config/pullman_new_freight_arrive_config.h

    ../../Pullman/Logistics_Trace/pullman_logistics_trace.h

FORMS += \
        login.ui \
    ../../Pullman/Main/pullman_main.ui \
    ../../Pullman/ControlPannel/controlpannel.ui \
    ../../Pullman/Logistics_Trace/pullman_logistics_trace.ui \
    ../../Pullman/New_Pickup/pullman_new_pickup.ui \
    ../../Pullman/New_Customer/pullman_new_customer.ui \
    ../../Pullman/New_Freight_Arrive/pullman_new_freight_arrive.ui \
    ../../Pullman/New_Freight_Arrive_Config/pullman_new_freight_arrive_config.ui

    ../../Pullman/Logistics_Trace/pullman_logistics_trace.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += D:/Work/Storage/Software/Pullman/
INCLUDEPATH += D:/Work/Storage/Software/Pullman/Main
INCLUDEPATH += D:/Work/Storage/Software/Pullman/ControlPannel
INCLUDEPATH += D:/Work/Storage/Software/Pullman/Logistics_Trace
INCLUDEPATH += D:/Work/Storage/Software/Pullman/New_Pickup
INCLUDEPATH += D:/Work/Storage/Software/OpenCV/include/opencv
INCLUDEPATH += D:/Work/Storage/Software/SendMailAPI
INCLUDEPATH += D:/Work/Storage/Software/Pullman/New_Customer

LIBS        +=D:/Work/Storage/Software/OpenCV/lib/highgui210.lib\

LIBS        +=D:/Work/Storage/Software/OpenCV/lib/cxcore210.lib\

LIBS        +=D:/Work/Storage/Software/OpenCV/lib/cv210.lib









