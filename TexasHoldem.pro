#-------------------------------------------------
#
# Project created by QtCreator 2014-02-03T15:26:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TexasHoldem
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    hand.cpp \
    card.cpp \
    table.cpp \
    calculator.cpp \
    solver.cpp \
    situation.cpp \
    fullsituation.cpp \
    threader.cpp

HEADERS  += mainwindow.h \
    hand.h \
    card.h \
    table.h \
    calculator.h \
    solver.h \
    situation.h \
    fullsituation.h \
    threader.h

FORMS    += mainwindow.ui
