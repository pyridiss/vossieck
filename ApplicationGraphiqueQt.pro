#-------------------------------------------------
#
# Project created by QtCreator 2013-08-26T11:02:15
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ApplicationGraphiqueQt
TEMPLATE = app


SOURCES += main.cpp \
    mainwindow.cpp \
    screentitle.cpp \
    finalscreen.cpp \
    homepv.cpp \
    homehabitat.cpp \
    homeheat.cpp \
    industryelectricity.cpp \
    industryheat.cpp \
    homeelectricity.cpp \
    industrysteam.cpp

HEADERS  += \
    mainwindow.h \
    screentitle.h \
    finalscreen.h \
    homepv.h \
    homehabitat.h \
    homeheat.h \
    industryelectricity.h \
    industryheat.h \
    homeelectricity.h \
    industrysteam.h

FORMS    +=

CONFIG += mobility
MOBILITY = 

RESOURCES = ApplicationGraphiqueQt.qrc

ICON = Icon.png

TRANSLATIONS = app_de.ts \
               app_fr.ts

OTHER_FILES += \
    logo.png

