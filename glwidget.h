#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QTimer>
//#include <QElapsedTimer>

#include <GL/glut.h>
#include <GL/glu.h>

#include "vobject.h"
#include "vmodel.h"
#include "camera.h"
#include "floorgrid.h"
#include "cube.h"

class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = 0);

    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

private:

    float lastRotateX, lastRotateY, lastRotateZ;

    QTimer timer;
    bool pressedKeys[256];
    float mouseX, mouseY;

//    QElapsedTimer elapsedT;
//    qint64 lastTime = 0;
//    int dt;

    camera cam;
    cube k;
    vModel m;
//    cube o[10];
    floorGrid floor;

    unsigned int tex;


    void keyReleaseEvent(QKeyEvent *event);
    void keyPressEvent(QKeyEvent*);

    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
//signals:

//public slots:

};

#endif // GLWIDGET_H
