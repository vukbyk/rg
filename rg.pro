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
#INCLUDEPATH += /usr/local/include/bullet
#INCLUDEPATH +=  ../bullet/src \
#                ../bullet/Extras/Serialize
#                ../bullet/Extras

SOURCES += main.cpp\
    mainwindow.cpp \
    glwidget.cpp \
    floorgrid.cpp \
    vobject.cpp \
    camera.cpp \
    cube.cpp \
    vmodel.cpp \
    vrigidbody.cpp \
    vworld.cpp

HEADERS  += mainwindow.h \
    glwidget.h \
    floorgrid.h \
    vobject.h \
    camera.h \
    cube.h \
    vmodel.h \
    vrigidbody.h \
    vworld.h

LIBS     += \
    -lglut \
    -lGLU \
    -lBulletDynamics \
    -lBulletCollision \
    -lBulletSoftBody \
    -lLinearMath \
    -lBulletWorldImporter \
    -lassimp \
    -lSDL \
    -lSDL_image\
    -lSDL2#\
#    -lSDL2_image


FORMS    += mainwindow.ui


