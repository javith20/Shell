#-------------------------------------------------
#
# Project created by QtCreator 2018-10-15T21:48:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Shell
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


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    ls.cpp \
    CutterCommand.cpp \
    listaenlazada.cpp \
    cd.cpp \
    mkdir.cpp \
    rm.cpp \
    cp.cpp \
    date.cpp \
    fileeditor.cpp \
    user.cpp \
    fileexists.cpp

HEADERS += \
        mainwindow.h \
    ls.h \
    CutterCommand.h \
    cd.h \
    mkdir.h \
    rm.h \
    cp.h \
    date.h \
    fileeditor.h \
    user.h \
    fileexists.h

FORMS += \
        mainwindow.ui
