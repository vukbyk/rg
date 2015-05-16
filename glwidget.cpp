#include "glwidget.h"

#include <QKeyEvent>
#include <iostream>

using namespace glm;
using namespace std;

GLWidget::GLWidget(QWidget *parent) : QGLWidget(parent)
{
    connect(&timer, SIGNAL(timeout()),this, SLOT(updateGL()));
    timer.start(25);
//    elapsedT.start();
    lastRotateX=lastRotateY=lastRotateZ=-1;
    rotation=0;
    setFocusPolicy(Qt::StrongFocus);

    for(int i =0; i < 256; i++)
    {
        pressedKeys[i] = false;
    }

//    cam.setAspect(size().width(), size().height());
    cam.setAngle(60);
//    cam.lookAt(vec3(0.f,2.f,5.f), vec3(0.f,0.f,0.f), vec3(0.f,1.f,0.f));

    for (int i=0; i<10;i++)
    {
        o[i].setPosition(vec3(i,0,0));
    }

}

void GLWidget::initializeGL()
{
    glClearColor(.2,.2,.2, 1);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    floorGrid floor;
    floor.put();

//    cube o[10];
//    for (int i=0; i<10;i++)
//    {
//        o[i].setPosition(vec3(i,0,0));
//    }

//    rotation+=2.5;
    for (int i=0; i<10;i++)
    {
//        o[i].setRotation(/*rotation*/2.5, vec3(.1,0,0));
        o[i].put();
//        o[i].input(pressedKeys);
    }
    glMatrixMode(GL_PROJECTION);
    cam.put();
    cam.keyEvent(pressedKeys);
//    vObject k;
//    k.setPosition(vec3(-1.f,0,0));
//    k.lookAt(vec3(1.f,-2.f,0.f), vec3(0.f,0.f,0.f), vec3(0.f,1.f,1.f));
//    k.put();
}

void GLWidget::resizeGL(int w, int h)
{
    cam.setAspect(w,h);
}

void GLWidget::keyPressEvent(QKeyEvent *event)
{
    int currKey = event->key();
    if(currKey >= 0 && currKey < 256)
    {
        pressedKeys[event->key()] = true;
    }
}

void GLWidget::mousePressEvent(QMouseEvent *event)
{
    lastRotateX=event->x();
    lastRotateY=event->y();
}

void GLWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton)
    {
        cam.setRotation((event->x()-lastRotateX)*.5, vec3(0,1,0));
        cam.setRotation((event->y()-lastRotateY)*.5, vec3(1,0,0));
        lastRotateX=event->x();
        lastRotateY=event->y();
    }
}

void GLWidget::keyReleaseEvent(QKeyEvent *event)
{
    int currKey = event->key();
    if(currKey >= 0 && currKey < 256)
    {
       pressedKeys[event->key()] = false;
    }
}

