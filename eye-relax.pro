QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = designer
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++11

FORMS += \
    mainwindow.ui

HEADERS += \
    mainwindow.h

SOURCES += \
    mainwindow.cpp \
    main.cpp

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
