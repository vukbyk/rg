#-------------------------------------------------
#
# Project created by QtCreator 2015-05-07T14:50:09
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = rg
TEMPLATE = app

INCLUDEPATH += /usr/include/bullet

SOURCES += main.cpp\
    mainwindow.cpp \
    glwidget.cpp \
    floorgrid.cpp \
    vobject.cpp \
    camera.cpp \
    cube.cpp

HEADERS  += mainwindow.h \
    glwidget.h \
    floorgrid.h \
    vobject.h \
    camera.h \
    cube.h \

LIBS     += -lglut -lGLU \
    -lBulletDynamics \
    -lBulletCollision \
    -lBulletSoftBody \
    -lLinearMath

FORMS    += mainwindow.ui


