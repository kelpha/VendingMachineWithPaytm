#-------------------------------------------------
#
# Project created by QtCreator 2020-09-17T10:38:00
#
#-------------------------------------------------

QT       += core gui network xml sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Bio_Shield_2
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
        mainwindow.cpp \
    landingscreen.cpp \
    thermalscanproxymity.cpp \
    thermalscan.cpp \
    qrcodedisplay.cpp \
    paymentconfirmation.cpp \
    paymenterror.cpp \
    exitpage.cpp \
    globlevariables.cpp \
    qrimage1.cpp \
    qrimage2.cpp \
    qronline.cpp \
    homescreen.cpp \
    settings.cpp \
    passwordscreen.cpp \
    databasemodule.cpp \
    outofstock.cpp

HEADERS += \
        mainwindow.h \
    landingscreen.h \
    thermalscanproxymity.h \
    thermalscan.h \
    qrcodedisplay.h \
    paymentconfirmation.h \
    paymenterror.h \
    exitpage.h \
    globlevariables.h \
    qrimage1.h \
    qrimage2.h \
    qronline.h \
    homescreen.h \
    settings.h \
    passwordscreen.h \
    databasemodule.h \
    outofstock.h

FORMS += \
        mainwindow.ui \
    landingscreen.ui \
    thermalscanproxymity.ui \
    thermalscan.ui \
    qrcodedisplay.ui \
    paymentconfirmation.ui \
    paymenterror.ui \
    exitpage.ui \
    qrimage1.ui \
    qrimage2.ui \
    qronline.ui \
    homescreen.ui \
    settings.ui \
    passwordscreen.ui \
    outofstock.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc

LIBS+=-lwiringPi

DISTFILES += \
    ThermoScan.png
