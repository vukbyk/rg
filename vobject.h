#ifndef MOBJECT_H
#define MOBJECT_H

#define GLM_FORCE_RADIANS
#include "GL/gl.h"
#include "GL/glu.h"
#include "GL/glut.h"
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>


class vObject
{    
protected:
public:
    glm::mat4x4 tm;
    float roll, yaw, pitch;

public:
    vObject();
    void draw();
    virtual void translate(glm::vec3 position);
    virtual void rotate(glm::vec3 axis);
    virtual void keyEvent(bool pressedKeys[], int mp=1);
    virtual void mouseEvent(float x, float pitch);

    virtual glm::vec3 getOrientation() const;
    virtual void setOrientation(glm::vec3 rotation);

    virtual glm::vec3 getPosition() const;

    float getYaw() const;
    void setYaw(float value);

    float getPitch() const;
    void setPitch(float value);

    float getRoll() const;
    void setRoll(float value);

    glm::mat4x4 getTM() const;
    void setTM(const glm::mat4x4 &value);
};

#endif // MOBJECT_H
