#include "glwidget.h"

#include <QKeyEvent>
#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

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

//    k.tm[3][2]=-5;
//    cam.setNear(1.5);
//    cam.setFar(20);
    cam.setAngle(60);
    cam.translate(vec3(0,-1,-4));
//    cam.lookAt(vec3(0.f,2.f,5.f), vec3(0.f,0.f,0.f), vec3(0.f,1.f,0.f));
}

void GLWidget::initializeGL()
{

    glClearColor(.2,.2,.2, 1);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    float dif[]= {1,1,1,1};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, dif);

//    glEnable(GL_COLOR_MATERIAL);
//    m.init();
    vrb.init();
    k.setParent(&vrb);

//  Bullet objekti inicijalizacija

    //pretty much initialize everything logically
//    collisionConfig=new btDefaultCollisionConfiguration();
//    dispatcher=new btCollisionDispatcher(collisionConfig);
//    broadphase=new btDbvtBroadphase();
//    solver=new btSequentialImpulseConstraintSolver();
    world=new btDiscreteDynamicsWorld(dispatcher,broadphase,solver,collisionConfig);
    world->setGravity(btVector3(0,-9.81,0));	//gravity on Earth

    //similar to createSphere
    btTransform t;
    t.setIdentity();
    t.setOrigin(btVector3(0,0,0));
    btStaticPlaneShape* plane=new btStaticPlaneShape(btVector3(0,1,0),0);
    btMotionState* motion=new btDefaultMotionState(t);
    btRigidBody::btRigidBodyConstructionInfo info(0.0,motion,plane);
    btRigidBody* body=new btRigidBody(info);
    body->setRestitution(1);
    world->addRigidBody(body);
//    bodies.push_back(body);

//    addSphere(0.3,0,6,0,1.0);	//add a new sphere above the ground

    vRigidBody *vbody=&vrb;//new vRigidBody();
    vbody->translate(btVector3(0,2,0));
    world->addRigidBody(vbody);	//and let the world know about it
    bodies.push_back(vbody);	//to be easier to clean, I store them a vector
    vbody->setRestitution(.5);
}


void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    cam.keyEvent(pressedKeys);
    cam.mouseEvent(mouseX, mouseY);
    cam.draw();

    floor.draw();
    k.draw();

    k.keyEvent(pressedKeys);
//    m.draw();
    m.keyEvent(pressedKeys);

    glLoadIdentity();
    float pos[]= {2, 2, 3, 1};
    glLightfv(GL_LIGHT0, GL_POSITION, pos);
//    float rot[]= {-2,-2,-3, 1};
    world->stepSimulation(1/60.0);

//  Bullet crtanje
    for(uint i=0, bs=bodies.size();i<bs;i++)
    {
//        if(bodies[i]->getCollisionShape()->getShapeType()==STATIC_PLANE_PROXYTYPE)
//            renderPlane(bodies[i]);
//        else if(bodies[i]->getCollisionShape()->getShapeType()==SPHERE_SHAPE_PROXYTYPE)
            renderSphere(bodies[i]);

//            bodies[i]->draw();
    }
    vRigidBody* b=bodies[0];
    btTransform t;
    b->getMotionState()->getWorldTransform(t);
    glm::mat4x4 mat(1);
//    t.getOpenGLMatrix(glm::value_ptr(b->tm));
    t.getOpenGLMatrix(glm::value_ptr(mat));
    b->tm=mat;
//    b->setAngularVelocity(btVector3(1,2,3));

    b->setMassProps(10,btVector3(100,1,0));
    b->draw();

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


btRigidBody* GLWidget::addSphere(float rad,float x,float y,float z,float mass)
{
    btTransform t;	//position and rotation
    t.setIdentity();
    t.setOrigin(btVector3(x,y,z));	//put it to x,y,z coordinates
    btSphereShape* sphere=new btSphereShape(rad);	//it's a sphere, so use sphereshape
    btVector3 inertia(0,0,0);	//inertia is 0,0,0 for static object, else
    if(mass!=0.0)
        sphere->calculateLocalInertia(mass,inertia);	//it can be determined by this function (for all kind of shapes)

    btMotionState* motion=new btDefaultMotionState(t);	//set the position (and motion)
    btRigidBody::btRigidBodyConstructionInfo info(mass,motion,sphere,inertia);	//create the constructioninfo, you can create multiple bodies with the same info
//    btRigidBody* body=new btRigidBody(info);	//let's create the body itself
    btRigidBody* body=new btRigidBody(btRigidBody::btRigidBodyConstructionInfo (1,new btDefaultMotionState(),new btSphereShape(.1)));
    body->translate(btVector3(x,y,z));
    world->addRigidBody(body);	//and let the world know about it
//    bodies.push_back(body);	//to be easier to clean, I store them a vector
    body->setRestitution(.5);
    return body;
}

void GLWidget::renderSphere(btRigidBody* sphere)
{
    if(sphere->getCollisionShape()->getShapeType()!=SPHERE_SHAPE_PROXYTYPE)	//only render, if it's a sphere
    {
//        cout<<"udje"<<endl;
        return;
    }
    glColor3f(1,0,0);
    float r=((btSphereShape*)sphere->getCollisionShape())->getRadius();
    btTransform t;
    sphere->getMotionState()->getWorldTransform(t);	//get the transform
    float mat[16];
    t.getOpenGLMatrix(mat);	//OpenGL matrix stores the rotation and orientation
    glPushMatrix();
        glMultMatrixf(mat);	//multiplying the current matrix with it moves the object in place
        glutSolidSphere(r,20,20);
    glPopMatrix();
}
