#-------------------------------------------------
#
# Project created by QtCreator 2015-05-07T14:50:09
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = rg
TEMPLATE = app


SOURCES += main.cpp\
    mainwindow.cpp \
    glwidget.cpp \
    floorgrid.cpp \
    vobject.cpp

HEADERS  += mainwindow.h \
    glwidget.h \
    floorgrid.h \
    vobject.h

FORMS    += mainwindow.ui

LIBS     += -lglut -lGLU
