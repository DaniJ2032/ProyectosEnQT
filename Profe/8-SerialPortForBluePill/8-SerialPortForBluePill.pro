QT       += core gui serialport #Agregado de serialport para reconocer la librería

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwidget.cpp \
    serialthread.cpp

HEADERS += \
    mainwidget.h \
    serialthread.h \
    structsTxAndRx.h

FORMS += \
    mainwidget.ui

QMAKE_CXXFLAGS += -std=gnu++14 #Agregado del estadnar 14

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    8-SerialPortForBluePill.pro.user

RESOURCES += \
    Leds.qrc

ICON = "utn.png"
