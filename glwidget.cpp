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

    setFocusPolicy(Qt::StrongFocus);

    mouseX=mouseY=0;
    for(int i =0; i < 256; i++)
    {
        pressedKeys[i] = false;
    }
//    k.p.z=-1;
//    k.tm[3][2]=-1;

    cam.setAngle(60);
    cam.translate(vec3(0,-1,-4));
//    cam.lookAt(vec3(0.f,2.f,5.f), vec3(0.f,0.f,0.f), vec3(0.f,1.f,0.f));

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

//    glLoadIdentity();

    floor.draw();
    k.draw();
    k.keyEvent(pressedKeys);
    cam.keyEvent(pressedKeys);
    cam.mouseEvent(mouseX, mouseY);
    cam.draw();
}

void GLWidget::resizeGL(int w, int h)
{
    glViewport(0.f, 0.f , w, h);
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
        cam.rotate(vec3(radians((event->y()-lastRotateY)*.5), 0, 0));
        cam.rotate(vec3(0, radians((event->x()-lastRotateX)*.5), 0));
//        mouseX=event->x()-lastRotateX;
//        mouseY=event->y()-lastRotateY;
        lastRotateY=event->y();
        lastRotateX=event->x();
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

