#-------------------------------------------------
#
# Project created by QtCreator 2017-06-30T13:46:15
#
#-------------------------------------------------

QT       += core gui network

CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = rmo
TEMPLATE = app

INCLUDEPATH = src/ src/LeftPanel/ src/RightPanel/ src/Indicators/ src/Client/

SOURCES += src/main.cpp\
    src/LeftPanel/ControlLeftPanel.cpp \
    src/RightPanel/ControlRightPanel.cpp \
    src/LeftPanel/LeftPanel.cpp \
    src/RightPanel/RightPanel.cpp \
    src/ButtonGroup.cpp \
    src/LeftPanel/MonitoringLeftPanel.cpp \
    src/RightPanel/SettingRightPanel.cpp \
    src/Indicators/ShPIndicator.cpp \
    src/IndicatorsStackedWidget.cpp \
    src/Indicators/GLIndicator.cpp \
    src/ControlPanel.cpp \
    src/Indicators/TOIndicator.cpp \
    src/Indicators/SAIndicator.cpp \
    src/Client/Client.cpp \
    src/Indicators/PaletteWidget.cpp

HEADERS += \
    src/LeftPanel/ControlLeftPanel.h \
    src/RightPanel/ControlRightPanel.h \
    src/LeftPanel/LeftPanel.h \
    src/RightPanel/RightPanel.h \
    src/ButtonGroup.h \
    src/LeftPanel/MonitoringLeftPanel.h \
    src/RightPanel/SettingRightPanel.h \
    src/Indicators/ShPIndicator.h \
    src/IndicatorsStackedWidget.h \
    src/Indicators/GLIndicator.h \
    src/ControlPanel.h \
    src/Indicators/TOIndicator.h \
    src/Indicators/SAIndicator.h \
    src/Client/Client.h \
    src/Indicators/PaletteWidget.h

FORMS += \
    ui/ControlLeftPanel.ui \
    ui/ControlRightPanel.ui \
    ui/LeftPanel.ui \
    ui/RightPanel.ui \
    ui/ButtonGroup.ui \
    ui/MonitoringLeftPanel.ui \
    ui/SettingRightPanel.ui \
    src/Indicators/ui/ShPIndicator.ui \
    src/Indicators/ui/GLIndicator.ui \
    src/Indicators/ui/TOIndicator.ui \
    src/Indicators/ui/SAIndicator.ui
