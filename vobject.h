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
    vObject *parent;

public:
    vObject();
    virtual void init();
    virtual void draw();
    virtual void translate(glm::vec3 position);
    virtual void rotate(glm::vec3 axis);
    virtual void keyEvent(bool pressedKeys[]);
    virtual void mouseEvent(float x, float pitch);

    virtual glm::vec3 getLocalOrientation() const;
    virtual void setLocalOrientation(glm::vec3 rotation);

    virtual glm::vec3 getLocalPosition() const;

    float getLocalYaw() const;
    void setLocalYaw(float value);

    float getLocalPitch() const;
    void setLocalPitch(float value);

    float getLocalRoll() const;
    void setLocalRoll(float value);



    glm::mat4x4 getLocalTM() const;
    void setTM(const glm::mat4x4 &value);

    glm::mat4x4 getWorldTM() const;

    vObject *getParent() const;
    void setParent(vObject *value);
};

#endif // MOBJECT_H
