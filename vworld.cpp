#include "vworld.h"

vWorld::vWorld()
{
    collisionConfig=new btDefaultCollisionConfiguration();
    dispatcher=new btCollisionDispatcher(collisionConfig);
    broadphase=new btDbvtBroadphase();
    solver=new btSequentialImpulseConstraintSolver();
    world=new btDiscreteDynamicsWorld(dispatcher,broadphase,solver,collisionConfig);
    world->setGravity(btVector3(0,-9.81,0));	//gravity on Earth
}
