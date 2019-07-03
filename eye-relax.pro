QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += core
QT += core gui
QT += multimedia

TARGET = eye-relax
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++11
         console

FORMS += \
    dialog.ui \
    mainwindow.ui \
    exercise.ui

HEADERS += \
    dialog.h \
    kolo.h \
    mainwindow.h \
    saver.h \
    timer.h

SOURCES += \
    dialog.cpp \
    mainwindow.cpp \
    saver.cpp \
    timer.cpp \
    kolo.cpp \
    main.cpp

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    eye-relax.qrc
