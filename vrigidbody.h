#ifndef VRIGIDBODY_H
#define VRIGIDBODY_H

#include <bullet/btBulletDynamicsCommon.h>


#include "vrigidbody.h"


#include <vmodel.h>

class vRigidBody : public btRigidBody, public vModel
{
public:
    vRigidBody();
//    vRigidBody(btRigidBodyConstructionInfo info);
    void translate(btVector3 t) { btRigidBody::translate(t); };
    void draw();
};

#endif // VRIGIDBODY_H
