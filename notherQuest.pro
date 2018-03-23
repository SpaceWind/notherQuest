#-------------------------------------------------
#
# Project created by QtCreator 2018-02-17T14:55:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QMAKE_CXXFLAGS_WARN_ON += -Wno-unused-parameter

TARGET = notherQuest
TEMPLATE = app

include(spells/spells.pri)
include(artifacts/artifacts.pri)

SOURCES += main.cpp\
        mainwindow.cpp \
    stats.cpp \
    utils.cpp \
    testform.cpp \
    playerstats.cpp \
    enemystatusitem.cpp \
    fightmanager.cpp \
    stashitem.cpp \
    globalinfo.cpp \
    monster.cpp

HEADERS  += mainwindow.h \
    stats.h \
    utils.h \
    testform.h \
    playerstats.h \
    enemystatusitem.h \
    fightmanager.h \
    stashitem.h \
    globalinfo.h \
    monster.h

FORMS    += mainwindow.ui \
    testform.ui \
    playerstats.ui \
    enemystatusitem.ui
