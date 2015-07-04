#include "vrigidbody.h"

#include <glm/gtc/type_ptr.hpp>

vRigidBody::vRigidBody():
    btRigidBody(btRigidBodyConstructionInfo (10,new btDefaultMotionState(),new btSphereShape(.1)))//,btVector3(1,10,1)))
{
    btSphereShape* sphere=new btSphereShape(1);	//it's a sphere, so use sphereshape
    btVector3 inertia(0,0,0);	//inertia is 0,0,0 for static object, else
    if(getInvMass()!=0.0)
        sphere->calculateLocalInertia(getInvMass(),inertia);
    setInvInertiaDiagLocal(inertia);
//    setLinearFactor(btVector3(0,0,0));
//    setAngularFactor(btVector3(0,1,0));
    setDamping(.1, .5);
    setCollisionShape(new btBoxShape(btVector3(2,1,2) ));
}

void vRigidBody::draw()
{
    glColor3f(1,1,0);
    btVector3 extent=((btBoxShape*)this->getCollisionShape())->getHalfExtentsWithoutMargin();
    btTransform tr;
    this->getMotionState()->getWorldTransform(tr);
    float mt[16];
    tr.getOpenGLMatrix(mt);
    glPushMatrix();
            glMultMatrixf(mt);     //translation,rotation
            glBegin(GL_LINE_LOOP);
                    glVertex3f(-extent.x(),extent.y(),-extent.z());
                    glVertex3f(-extent.x(),-extent.y(),-extent.z());
                    glVertex3f(-extent.x(),-extent.y(),extent.z());
                    glVertex3f(-extent.x(),extent.y(),extent.z());

                    glVertex3f(extent.x(),extent.y(),-extent.z());
                    glVertex3f(extent.x(),-extent.y(),-extent.z());
                    glVertex3f(extent.x(),-extent.y(),extent.z());
                    glVertex3f(extent.x(),extent.y(),extent.z());

                    glVertex3f(-extent.x(),extent.y(),extent.z());
                    glVertex3f(-extent.x(),-extent.y(),extent.z());
                    glVertex3f(extent.x(),-extent.y(),extent.z());
                    glVertex3f(extent.x(),extent.y(),extent.z());

                    glVertex3f(-extent.x(),extent.y(),-extent.z());
                    glVertex3f(-extent.x(),-extent.y(),-extent.z());
                    glVertex3f(extent.x(),-extent.y(),-extent.z());
                    glVertex3f(extent.x(),extent.y(),-extent.z());

                    glVertex3f(-extent.x(),extent.y(),-extent.z());
                    glVertex3f(-extent.x(),extent.y(),extent.z());
                    glVertex3f(extent.x(),extent.y(),extent.z());
                    glVertex3f(extent.x(),extent.y(),-extent.z());

                    glVertex3f(-extent.x(),-extent.y(),-extent.z());
                    glVertex3f(-extent.x(),-extent.y(),extent.z());
                    glVertex3f(extent.x(),-extent.y(),extent.z());
                    glVertex3f(extent.x(),-extent.y(),-extent.z());
            glEnd();
    glPopMatrix();

    btTransform t;
    getMotionState()->getWorldTransform(t);
    glm::mat4x4 mat(1);
    t.getOpenGLMatrix(glm::value_ptr(tm));
    vModel::draw();
}

