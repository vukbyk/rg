#ifndef CAMERA_H
#define CAMERA_H
#include "vobject.h"

class camera : public vObject
{
    int width, height;
    float angle, near, far;
public:
    camera();
    camera(float a, float n, float f);
    void put();
    void lookAt(glm::vec3 eye, glm::vec3 center, glm::vec3 up);
    void setAspect(int w, int h);

    void keyEvent(bool pressedKeys[]);

    float getAngle() const;
    void setAngle(float value);
    float getNear() const;
    void setNear(float value);
    float getFar() const;
    void setFar(float value);


    int getWidth() const;
    void setWidth(int value);
    int getHeight() const;
    void setHeight(int value);
};

#endif // CAMERA_H
