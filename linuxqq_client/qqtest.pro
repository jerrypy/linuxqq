#-------------------------------------------------
#
# Project created by QtCreator 2013-11-10T16:11:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qqtest
TEMPLATE = app


SOURCES += main.cpp\
        login.cpp \
    mainwindow.cpp \
    registerdialog.cpp \
    maininterface.cpp \
    filesend.cpp \
    filerecieve.cpp \
    connectserver.cpp \
    servermsg_thread.cpp

HEADERS  += login.h \
    mainwindow.h \
    registerdialog.h \
    maininterface.h \
    filesend.h \
    filerecieve.h \
    qq_deftypes.h \
    connectserver.h \
    servermsg_thread.h


FORMS    += login.ui \
    mainwindow.ui \
    registerdialog.ui \
    maininterface.ui \
    filesend.ui \
    filerecieve.ui

LIBS += -lmysqlclient

RESOURCES += \
    sources.qrc
