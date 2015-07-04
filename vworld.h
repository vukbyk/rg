#ifndef VWORLD_H
#define VWORLD_H

#include <vector>
#include <bullet/btBulletDynamicsCommon.h>
#include <vrigidbody.h>

class vWorld
{
public:

    btDynamicsWorld* world;	//every physical object go to the world
    btDispatcher* dispatcher;	//what collision algorithm to use?
    btCollisionConfiguration* collisionConfig;	//what collision algorithm to use?
    btBroadphaseInterface* broadphase;	//should Bullet examine every object, or just what close to each other
    btConstraintSolver* solver;					//solve collisions, apply forces, impulses
    std::vector<vRigidBody*> bodies;

    vWorld();
    void addRigidBody(btRigidBody *body);
};

#endif // VWORLD_H
