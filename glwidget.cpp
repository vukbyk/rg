#include "glwidget.h"
#include <GL/glut.h>
#include <GL/glu.h>

GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent)
{
    connect(&timer, SIGNAL(timeout()),this, SLOT(updateGL()));
    timer.start(25);
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
//    glBegin(GL_TRIANGLES);
//        glColor3f(.5,.5,.5);
//        glVertex3f(-0.5, -0.5, 0);
//        glVertex3f( 0.5, -0.5, 0);
//        glVertex3f( 0  ,  0.5, 0);
//    glEnd();

//    glBegin(GL_QUADS);
//        glColor3f(1,0,0);
//        glVertex3f(-0.5, -0.5, 0);
//        glColor3f(0,1,0);
//        glVertex3f( 0.5, -0.5, 0);
//        glColor3f(0,0,1);
//        glVertex3f( 0.5  ,  0.5, .1);
//        glColor3f(1,1,0);
//        glVertex3f( -0.5  ,  0.5, .1);
//    glEnd();

    glRotatef(.5,.25, .125, 1);
    glColor3f(0.5,0.0,0.5);
    glutSolidTeapot(.6);
}

void GLWidget::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, (float)w/h, 0.01,100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0,0,5, 0,0,0, 0,1,0);
}

