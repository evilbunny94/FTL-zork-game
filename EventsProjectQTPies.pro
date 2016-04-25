#-------------------------------------------------
#
# Project created by QtCreator 2016-04-06T16:03:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EventsProjectQTPies
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    endscreen.cpp \
    inventory.cpp \
    Items.cpp \
    Objective.cpp \
    Room.cpp

HEADERS  += mainwindow.h \
    endscreen.h \
    inventory.h \
    Items.h \
    Objective.h \
    Room.h

FORMS    += mainwindow.ui \
    endscreen.ui

RESOURCES += \
    images.qrc

DISTFILES +=
