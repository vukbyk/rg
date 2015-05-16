#ifndef MOBJECT_H
#define MOBJECT_H

#define GLM_FORCE_RADIANS
#include "GL/gl.h"
#include "GL/glu.h"
#include "GL/glut.h"
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>


class vObject
{
public:
    float yaw, pitch, roll;


    glm::mat4x4 transforamtion;
public:
    vObject();
    void put();
    void setPosition(glm::vec3 position);
    void setRotation(float angle, glm::vec3 axis);
    void keyEvent(bool pressedKeys[]);
    void mouseEvent(float x, float y);
};

#endif // MOBJECT_H
