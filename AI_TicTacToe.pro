#-------------------------------------------------
#
# Project created by QtCreator 2015-10-09T09:10:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets opengl

TARGET = AI_TicTacToe
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    NewGameDialog.cpp \
    GameWidget.cpp \
    GameMap.cpp \
    Player.cpp \
    Game.cpp \
    AIPlayerRandom.cpp \
    AIPlayerDifficult.cpp

HEADERS  += MainWindow.h \
    NewGameDialog.h \
    common.h \
    GameWidget.h \
    GameMap.h \
    Player.h \
    Game.h \
    AIPlayerRandom.h \
    AIPlayerDifficult.h

FORMS    += MainWindow.ui \
    NewGameDialog.ui

CONFIG += c++11
