#include "vrigidbody.h"
#include <iostream>

#include <BulletWorldImporter/btBulletWorldImporter.h>


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


    setCollisionShape(new btBoxShape(btVector3(2,1,2) ));

//        for(int i=0; i<100;++i)
//        {
//            std::cout<< "i(" << i << ")" << "= " << vertexArray[i]<<std::endl;
//        }

        btCollisionShape* convex;// = new btConvexHullShape( vertexArray,5,4);
//         if("bullkocka.bullet" && strlen("bullkocka.bullet") > 0)
//         {
//             btBulletWorldImporter importer ;
//             importer.loadFile("../models/bullkocka.bullet");
//             convex = importer.getCollisionShapeByIndex(0);
//         }
//         else
//         {
//             convex = NULL;
//         }
//        setCollisionShape(convex);

    setDamping(.3, .7);
}

void vRigidBody::draw()
{
    btTransform t;
    getMotionState()->getWorldTransform(t);
    glm::mat4x4 mat(1);
    t.getOpenGLMatrix(glm::value_ptr(tm));
    vModel::draw();

//        glColor3f(1,1,0);
//        btVector3 extent=((btBoxShape*)this->getCollisionShape())->getHalfExtentsWithoutMargin();
//        btTransform tr;
//        this->getMotionState()->getWorldTransform(tr);
//        float mt[16];
//        tr.getOpenGLMatrix(mt);
//        glPushMatrix();
//                glMultMatrixf(mt);     //translation,rotation
//                glBegin(GL_LINE_LOOP);
//                        glVertex3f(-extent.x(),extent.y(),-extent.z());
//                        glVertex3f(-extent.x(),-extent.y(),-extent.z());
//                        glVertex3f(-extent.x(),-extent.y(),extent.z());
//                        glVertex3f(-extent.x(),extent.y(),extent.z());

//                        glVertex3f(extent.x(),extent.y(),-extent.z());
//                        glVertex3f(extent.x(),-extent.y(),-extent.z());
//                        glVertex3f(extent.x(),-extent.y(),extent.z());
//                        glVertex3f(extent.x(),extent.y(),extent.z());

//                        glVertex3f(-extent.x(),extent.y(),extent.z());
//                        glVertex3f(-extent.x(),-extent.y(),extent.z());
//                        glVertex3f(extent.x(),-extent.y(),extent.z());
//                        glVertex3f(extent.x(),extent.y(),extent.z());

//                        glVertex3f(-extent.x(),extent.y(),-extent.z());
//                        glVertex3f(-extent.x(),-extent.y(),-extent.z());
//                        glVertex3f(extent.x(),-extent.y(),-extent.z());
//                        glVertex3f(extent.x(),extent.y(),-extent.z());

//                        glVertex3f(-extent.x(),extent.y(),-extent.z());
//                        glVertex3f(-extent.x(),extent.y(),extent.z());
//                        glVertex3f(extent.x(),extent.y(),extent.z());
//                        glVertex3f(extent.x(),extent.y(),-extent.z());

//                        glVertex3f(-extent.x(),-extent.y(),-extent.z());
//                        glVertex3f(-extent.x(),-extent.y(),extent.z());
//                        glVertex3f(extent.x(),-extent.y(),extent.z());
//                        glVertex3f(extent.x(),-extent.y(),-extent.z());
//                glEnd();
//        glPopMatrix();
}

