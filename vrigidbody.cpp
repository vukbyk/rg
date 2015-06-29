#include "vrigidbody.h"

vRigidBody::vRigidBody():
    btRigidBody(btRigidBodyConstructionInfo (1,new btDefaultMotionState(),new btSphereShape(.1)))
{
}
