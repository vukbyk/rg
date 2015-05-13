#include "glwidget.h"
#include "vobject.h"

#include <GL/glut.h>
#include <GL/glu.h>
//#include <glm/vec3.hpp>

#include <QKeyEvent>

#include <iostream>

using namespace glm;

GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent)
{
    connect(&timer, SIGNAL(timeout()),this, SLOT(updateGL()));
    timer.start(25);
//    elapsedT.start();

    setFocusPolicy(Qt::StrongFocus);
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
    using namespace glm;

    vec3 v(2,2,2);

    vObject o[10];
    for (int i=0; i<10;i++)
    {
        o[i].setPosition(vec3(i,0,0));
    }
//    rotation+=2.5;
    floor.put();
    glMatrixMode(GL_MODELVIEW);
    for (int i=0; i<10;i++)
    {       
        o[i].put();
    }
}

void GLWidget::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, (float)w/h, 0.01,100.0);
    gluLookAt(1,2,5, 0,0,0, 0,1,0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void GLWidget::keyPressEvent(QKeyEvent *k)
{
    switch (k->key())
    {
    case Qt::Key_W:
        rotation++;
        break;
    default:
        break;
    }
    update();
    repaint();
}
