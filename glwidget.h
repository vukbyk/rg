#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QTimer>
//#include <QElapsedTimer>

#include <GL/glut.h>
#include <GL/glu.h>
#include <bullet/btBulletDynamicsCommon.h>

#include <vobject.h>
#include <vmodel.h>
#include <vrigidbody.h>
#include <camera.h>
#include <floorgrid.h>
#include <cube.h>
#include <vworld.h>


class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = 0);

    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

    btRigidBody *addSphere(float rad, float x, float y, float z, float mass);
    void renderSphere(btRigidBody *sphere);
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
    vRigidBody vrb;
//    cube o[10];
    floorGrid floor;

    vWorld world;
//Bullet objekti
//    btDynamicsWorld* world;	//every physical object go to the world
//    btDispatcher* dispatcher;	//what collision algorithm to use?
//    btCollisionConfiguration* collisionConfig;	//what collision algorithm to use?
//    btBroadphaseInterface* broadphase;	//should Bullet examine every object, or just what close to each other
//    btConstraintSolver* solver;					//solve collisions, apply forces, impulses
//    std::vector<vRigidBody*> bodies;
//Bullet objekti

    void keyReleaseEvent(QKeyEvent *event);
    void keyPressEvent(QKeyEvent*);

    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
//signals:

//public slots:

};

#endif // GLWIDGET_H
