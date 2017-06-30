#-------------------------------------------------
#
# Project created by QtCreator 2017-06-30T13:46:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = rmo
TEMPLATE = app


SOURCES += src/main.cpp\
    src/ControlLeftPanel.cpp \
    src/ControlRightPanel.cpp

HEADERS += \
    src/ControlLeftPanel.h \
    src/ControlRightPanel.h

FORMS += \
    src/ControlLeftPanel.ui \
    src/ControlRightPanel.ui
