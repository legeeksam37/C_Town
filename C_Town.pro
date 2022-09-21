#-------------------------------------------------
#
# Project created by QtCreator 2020-05-02T22:16:21
#
#-------------------------------------------------

QT       += core gui \
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = C_Town
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    Balle.cpp \
    Cowboy.cpp \
    Brigand.cpp \
    Game.cpp \
    Score.cpp \
    Health.cpp \
    Dame.cpp \
    Horse.cpp \
    Freewomencounter.cpp \
    Freebrigands.cpp \
    Wall1.cpp \
    Jail.cpp \
    Building.cpp \
    Potion.cpp \
    Snake.cpp

HEADERS += \
    Balle.h \
    Cowboy.h \
    Brigand.h \
    Game.h \
    Score.h \
    Health.h \
    Dame.h \
    Horse.h \
    Freewomencounter.h \
    Freebrigands.h \
    Wall1.h \
    Jail.h \
    Building.h \
    Potion.h \
    Snake.h

FORMS +=

RESOURCES += \
    res.qrc
