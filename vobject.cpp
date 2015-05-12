#include "vobject.h"
using namespace glm;

vObject::vObject()
{
    p=vec3(0,0,0);
    o=vec3(0,0,0);
}

vObject::vObject(const vec3 &position, const vec3 &oriention=vec3(0,0,0))
{
    p=position;
    o=oriention;
}

vec3 vObject::getPosition() const
{
    return p;
}

void vObject::setPosition(const vec3 &value)
{
    p = value;
}

vec3 vObject::getOrientation() const
{
    return o;
}

void vObject::setOrientation(const vec3 &value)
{
    o = value;
}
