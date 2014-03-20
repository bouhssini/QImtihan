#-------------------------------------------------
#
# Project created by QtCreator 2013-05-09T14:46:29
#
#-------------------------------------------------

QT       += core gui webkit network
QT       += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QImtihan
TEMPLATE = app


SOURCES += main.cpp\
        frmstart.cpp \
    frmurl.cpp \
    frmconnect.cpp \
    funCmd.cpp \
    frmnataij.cpp

HEADERS  += frmstart.h \
    General.h \
    frmurl.h \
    frmconnect.h \
    frmnataij.h

FORMS    += frmstart.ui \
    frmconnect.ui \
    frmnataij.ui

RESOURCES += \
    res.qrc

win32:RC_FILE = MyApp.rc
