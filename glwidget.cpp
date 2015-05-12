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

    vObject o(vec3(0,0,0),v);

    //rotation+=2.5;
    glPushMatrix();
        glRotatef(rotation, 0, 1, 0);
        glTranslatef(o.p.x,o.p.y,o.p.z);
//        glutSolidTeapot(.6);
        glColor3f(0.5,0.0,0);
        glutSolidCube(.6);
    glPopMatrix();
    floor.put();
}

void GLWidget::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, (float)w/h, 0.01,100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(1,2,5, 0,0,0, 0,1,0);
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
