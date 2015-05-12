#ifndef MOBJECT_H
#define MOBJECT_H

#include <glm/vec3.hpp>

class vObject
{
public:
    glm::vec3 p; //position
    glm::vec3 o; //orientation
public:
    vObject();
    vObject(const glm::vec3 &position, const glm::vec3 &oriention);

    glm::vec3 getPosition() const;
    void setPosition(const glm::vec3 &value);
    glm::vec3 getOrientation() const;
    void setOrientation(const glm::vec3 &value);
};

#endif // MOBJECT_H
