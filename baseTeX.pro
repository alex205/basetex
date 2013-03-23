#-------------------------------------------------
#
# Project created by QtCreator 2013-02-03T16:48:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = baseTeX
TEMPLATE = app


SOURCES += main.cpp\
        fenetre.cpp \
    fenetreSlot.cpp \
    fenetreGenerer.cpp \
    fenetreMethod.cpp

HEADERS  += fenetre.h

RESOURCES += \
    ressources.qrc
TRANSLATIONS = basetex_en.ts
