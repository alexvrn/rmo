#-------------------------------------------------
#
# Project created by QtCreator 2017-06-30T13:46:15
#
#-------------------------------------------------

QT       += core gui network concurrent printsupport

CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = rmo
TEMPLATE = app

unix:LIBS += -lX11 -lXss

SOURCES += src/main.cpp\
    src/LeftPanel/LeftPanel.cpp \
    src/RightPanel/RightPanel.cpp \
    src/ButtonGroup.cpp \
    src/LeftPanel/MonitoringLeftPanel.cpp \
    src/RightPanel/SettingRightPanel.cpp \
    #src/IndicatorsStackedWidget.cpp \
    src/Indicators/GL/GLIndicator.cpp \
    src/Indicators/TO/TOIndicator.cpp \
    src/Indicators/SA/SAIndicator.cpp \
    src/Client/Client.cpp \
    src/Client/ClientWorker.cpp \
    src/Indicators/PaletteWidget.cpp \
    src/QCustomPlot/qcustomplot.cpp \
    src/Indicators/ShP/ShPIndicatorItem.cpp \
    src/Indicators/ShP/ShPIndicator.cpp \
    src/Indicators/ShP/ShPIndicatorWidget.cpp \
    src/AuthDialog/AuthDialog.cpp \
    src/ScreenSaver.cpp \
    src/Client/ResponseReceiver.cpp \
    src/Graphics/Graphic.cpp \
    riot_os_cbor/cbor.c \
    structs/cmd_data_packer.c \
    structs/cmd_data_debug.c \
    src/CPColorMap/CPColorMap.cpp \
    src/AbstractGraphic.cpp \
    src/GraphicTime.cpp \
    src/GraphicTimeWorker.cpp \
    src/GraphicValue.cpp \
    src/GraphicValueWorker.cpp \
    src/Indicator.cpp \
    src/MainWindow.cpp \
    src/Indicators/GL/GLMarkerFormular.cpp \
    src/Indicators/GL/GLSection.cpp \
    src/Indicators/GL/GLIndicatorWidget.cpp \
    src/Indicators/ZPS/ZPSIndicator.cpp \
    src/Indicators/ZPS/ZPSIndicatorData.cpp \
    src/Indicators/ZPS/ZPSTableData.cpp \
    src/Indicators/IZL/IZLIndicator.cpp \
    src/Indicators/IZL/PanelTask.cpp \
    src/Indicators/IZL/PanelViewer.cpp \
    src/Indicators/IZL/TonalModel.cpp \
    src/Indicators/IZL/ViewerModel.cpp \
    src/IndicatorList.cpp

HEADERS += \
    src/LeftPanel/LeftPanel.h \
    src/RightPanel/RightPanel.h \
    src/ButtonGroup.h \
    src/LeftPanel/MonitoringLeftPanel.h \
    src/RightPanel/SettingRightPanel.h \
    #src/IndicatorsStackedWidget.h \
    src/Indicators/GL/GLIndicator.h \
    src/Indicators/TO/TOIndicator.h \
    src/Indicators/SA/SAIndicator.h \
    src/Client/Client.h \
    src/Client/ClientWorker.h   \
    src/Indicators/PaletteWidget.h \
    src/QCustomPlot/qcustomplot.h \
    src/Indicators/ShP/ShPIndicatorItem.h \
    src/Indicators/ShP/ShPIndicator.h \
    src/Indicators/ShP/ShPIndicatorWidget.h \
    src/AuthDialog/AuthDialog.h \
    src/ScreenSaver.h \
    src/Client/ResponseReceiver.h \
    src/Graphics/Graphic.h \
    src/commandType.h \
    riot_os_cbor/cbor.h \
    structs/cmd_data_packer.h \
    structs/cmd_data_debug.h \
    src/CPColorMap/CPColorMap.h \
    src/AbstractGraphic.h \
    src/GraphicTime.h \
    src/GraphicTimeWorker.h \
    src/GraphicValue.h \
    src/GraphicValueWorker.h \
    src/Indicator.h \
    src/MainWindow.h \
    src/Indicators/GL/GLMarkerFormular.h \
    src/Indicators/GL/GLSection.h \
    src/Indicators/GL/GLIndicatorWidget.h \
    src/Indicators/ZPS/ZPSIndicator.h \
    src/Indicators/ZPS/ZPSIndicatorData.h \
    src/Indicators/ZPS/ZPSTableData.h \
    src/Indicators/IZL/IZLIndicator.h \
    src/Indicators/IZL/PanelTask.h \
    src/Indicators/IZL/PanelViewer.h \
    src/Indicators/IZL/TonalModel.h \
    src/Indicators/IZL/ViewerModel.h \
    src/IndicatorList.h

FORMS += \
    ui/LeftPanel.ui \
    ui/RightPanel.ui \
    ui/ButtonGroup.ui \
    ui/MonitoringLeftPanel.ui \
    ui/SettingRightPanel.ui \
    src/Indicators/GL/GLIndicator.ui \
    src/Indicators/TO/TOIndicator.ui \
    src/Indicators/SA/SAIndicator.ui \
    src/Indicators/ShP/ShPIndicatorItem.ui \
    src/Indicators/ShP/ShPIndicator.ui \
    src/Indicators/ShP/ShPIndicatorWidget.ui \
    ui/AuthDialog.ui \
    ui/GraphicTime.ui \
    ui/GraphicValue.ui \
    src/Indicators/GL/GLMarkerFormular.ui \
    src/Indicators/GL/GLSection.ui \
    src/Indicators/GL/GLIndicatorWidget.ui \
    src/Indicators/ZPS/ZPSIndicator.ui \
    src/Indicators/ZPS/ZPSIndicatorData.ui \
    src/Indicators/IZL/IZLIndicator.ui \
    src/Indicators/IZL/PanelTask.ui \
    src/Indicators/IZL/PanelViewer.ui \
    src/IndicatorList.ui

RESOURCES += \
    resources.qrc


INCLUDEPATH = src/ src/LeftPanel/ src/RightPanel/ src/Client/ src/QCustomPlot/ src/AuthDialog/ src/Graphics \
              riot_os_cbor/ structs/ \
              src/Indicators/ src/Indicators/ShP/ src/Indicators/SA/ src/Indicators/TO/ src/Indicators/GL/ \
              src/Indicators/ZPS/ src/Indicators/IZL/ \
              src/CPColorMap/
