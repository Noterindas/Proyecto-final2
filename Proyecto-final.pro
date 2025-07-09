QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    abejag.cpp \
    abejap.cpp \
    cocodrilo.cpp \
    dinosaurio.cpp \
    gamerover.cpp \
    ganaste.cpp \
    goku.cpp \
    main.cpp \
    mainwindow.cpp \
    mapa.cpp \
    nam.cpp \
    nivel2.cpp \
    serpiente.cpp

HEADERS += \
    abejag.h \
    abejap.h \
    cocodrilo.h \
    dinosaurio.h \
    gamerover.h \
    ganaste.h \
    goku.h \
    mainwindow.h \
    mapa.h \
    nam.h \
    nivel2.h \
    serpiente.h

FORMS += \
    gamerover.ui \
    ganaste.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    imagenes.qrc
