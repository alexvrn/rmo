#-------------------------------------------------
#
# Project created by QtCreator 2017-06-30T13:46:15
#
#-------------------------------------------------

QT       += core gui network printsupport

CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = rmo
TEMPLATE = app

unix:LIBS += -lX11 -lXss

SOURCES += src/main.cpp\
    src/LeftPanel/ControlLeftPanel.cpp \
    src/RightPanel/ControlRightPanel.cpp \
    src/LeftPanel/LeftPanel.cpp \
    src/RightPanel/RightPanel.cpp \
    src/ButtonGroup.cpp \
    src/LeftPanel/MonitoringLeftPanel.cpp \
    src/RightPanel/SettingRightPanel.cpp \
    src/IndicatorsStackedWidget.cpp \
    src/Indicators/GLIndicator.cpp \
    src/ControlPanel.cpp \
    src/Indicators/TOIndicator.cpp \
    src/Indicators/SAIndicator.cpp \
    src/Client/Client.cpp \
    src/Indicators/PaletteWidget.cpp \
    src/QCustomPlot/qcustomplot.cpp \
    src/Indicators/ShPIndicatorItem.cpp \
    src/Indicators/ShPIndicator.cpp \
    src/Indicators/ShPIndicatorWidget.cpp \
    src/AuthDialog/AuthDialog.cpp \
    src/ScreenSaver.cpp \
    src/Client/ResponseReceiver.cpp \
    src/Graphics/Graphic.cpp \
    riot_os_cbor/cbor.c \
    structs/cmd_data_packer.c \
    structs/cmd_data_debug.c

HEADERS += \
    src/LeftPanel/ControlLeftPanel.h \
    src/RightPanel/ControlRightPanel.h \
    src/LeftPanel/LeftPanel.h \
    src/RightPanel/RightPanel.h \
    src/ButtonGroup.h \
    src/LeftPanel/MonitoringLeftPanel.h \
    src/RightPanel/SettingRightPanel.h \
    src/IndicatorsStackedWidget.h \
    src/Indicators/GLIndicator.h \
    src/ControlPanel.h \
    src/Indicators/TOIndicator.h \
    src/Indicators/SAIndicator.h \
    src/Client/Client.h \
    src/Indicators/PaletteWidget.h \
    src/QCustomPlot/qcustomplot.h \
    src/Indicators/ShPIndicatorItem.h \
    src/Indicators/ShPIndicator.h \
    src/Indicators/ShPIndicatorWidget.h \
    src/AuthDialog/AuthDialog.h \
    src/ScreenSaver.h \
    src/Client/ResponseReceiver.h \
    src/Graphics/Graphic.h \
    src/commandType.h \
    riot_os_cbor/cbor.h \
    structs/cmd_data_packer.h \
    structs/cmd_data_debug.h

FORMS += \
    ui/ControlLeftPanel.ui \
    ui/ControlRightPanel.ui \
    ui/LeftPanel.ui \
    ui/RightPanel.ui \
    ui/ButtonGroup.ui \
    ui/MonitoringLeftPanel.ui \
    ui/SettingRightPanel.ui \
    src/Indicators/ui/GLIndicator.ui \
    src/Indicators/ui/TOIndicator.ui \
    src/Indicators/ui/SAIndicator.ui \
    src/Indicators/ui/ShPIndicatorItem.ui \
    src/Indicators/ui/ShPIndicator.ui \
    src/Indicators/ui/ShPIndicatorWidget.ui \
    ui/AuthDialog.ui

RESOURCES += \
    resources.qrc


INCLUDEPATH = src/ src/LeftPanel/ src/RightPanel/ src/Indicators/ src/Client/ src/QCustomPlot/ src/AuthDialog/ src/Graphics \
              riot_os_cbor/ structs/
