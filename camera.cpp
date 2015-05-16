#include "camera.h"
#include <Qt>

using namespace glm;

int camera::getWidth() const
{
    return width;
}

void camera::setWidth(int value)
{
    width = value;
}

int camera::getHeight() const
{
    return height;
}

void camera::setHeight(int value)
{
    height = value;
}
camera::camera()
{
    width=0;
    height=0;
    angle=glm::radians(45.f);
    near=0.1f;
    far=100.f;
}

camera::camera(float a, float n=.1f, float f=100.f)
{
    angle=glm::radians(a);
    near=n;
    far=f;
}

void camera::setAspect(int w, int h)
{
    width = w;
    height= h;
}

void camera::put()
{
    glViewport(0.f, 0.f , width, height);
    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    tm=glm::perspective(45.f,(float)width/height, 0.01f, 100.0f);
//    tm*=glm::lookAt(vec3(1.f,2.f,5.f), vec3(0.f,0.f,0.f), vec3(0.f,1.f,0.f));
    glLoadMatrixf(&(perspective(angle,(float)width/height, near, far)*transforamtion)[0][0]);
}

void camera::keyEvent(bool pressedKeys[])
{
    for(int i =0; i< 256; i++)
    {
        if(pressedKeys[i])
//            cout << "Key: "<<(char) (i)<< endl;
        switch ((char)(i))
        {
        case 'D':
            setPosition(vec3(-.05,0.f,0.f));
            break;
        case 'A':
            setPosition(vec3(.05f,0.f,0.f));
            break;
        case 'R':
            setPosition(vec3(0.f,-.05f,0.f));
            break;
        case 'F':
            setPosition(vec3(0,.05f,0));
            break;
        case 'W':
            setPosition(vec3(0.f,.0f,.05f));
            break;
        case 'S':
            setPosition(vec3(0.f,.0f,-.05f));
            break;
        case 'Y':
            setRotation(-1.f, vec3(1.f, 0.f,0.f));
            break;
        case 'H':
            setRotation(1.f, vec3(1.f, 0.f,0.f));
            break;
        case 'G':
            setRotation(-1.f, vec3(0.f, 1.f,0.f));
            break;
        case 'J':
            setRotation(1.f, vec3(0.f, 1.f,0.f));
            break;
        case 'Q':
            setRotation(-1.f, vec3(0.f, 0.f,1.f));
            break;
        case 'E':
            setRotation(1.f, vec3(0.f, 0.f,1.f));
            break;
        default:
            break;
        }
    }
}

void camera::lookAt(vec3 eye, vec3 center, vec3 up)
{
    transforamtion=glm::lookAt(eye, center, up);
}

float camera::getAngle() const
{
    return angle;
}

void camera::setAngle(float value)
{
    angle = radians(value);
//    cout<<"X: " <<
}

float camera::getNear() const
{
    return near;
}

void camera::setNear(float value)
{
    near = value;
}

float camera::getFar() const
{
    return far;
}

void camera::setFar(float value)
{
    far = value;
}
