#include "camera.h"
#include <Qt>

#include <iostream>
using namespace std;
using namespace glm;

camera::camera()
{
    width=0;
    height=0;
    angle=glm::radians(45.f);
    near=0.5f;
    far=500.f;
}

camera::camera(float a, float n=.5f, float f=5000.f)

{
    angle=glm::radians(a);
    near=n;
    far=f;
}

void camera::draw()
{

    //    glViewport(0.f, 0.f , width, height);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(45, (float)width/height, near, far);

    //    glMatrixMode(GL_MODELVIEW);
    //    glLoadIdentity();
    //    glLoadIdentity();
    if(parent==NULL)
    {
        glMultMatrixf(&getLocalTM()[0][0]);
    //      glRotatef(0,0,1,0);

    //    setTransforamtion();
    //    glMultMatrixf(&transforamtion[0][0]);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
    }
    else
    {
        glMultMatrixf(&(getLocalTM()*glm::inverse(parent->getLocalTM()))[0][0]);
    //      glRotatef(0,0,1,0);

    //    setTransforamtion();
    //    glMultMatrixf(&transforamtion[0][0]);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
    }
}

void camera::lookAt(vec3 eye, vec3 center, vec3 up)
{
    tm=glm::lookAt(eye, center, up);
}

void camera::setAspect(int w, int h)
{
    width = w;
    height= h;
}


glm::mat4x4 camera::getLocalTM()
{
//    setTransforamtion();

//    cout<<"t: "<< tm[0][0]<<endl;
//    cout<<"t: "<< tm[0][1]<<endl;
//    cout<<"t: "<< tm[0][2]<<endl;
//    cout<<"t: "<< tm[1][0]<<endl;
//    cout<<"t: "<< tm[1][1]<<endl;
//    cout<<"t: "<< tm[1][2]<<endl;
//    cout<<"t: "<< tm[2][0]<<endl;
//    cout<<"t: "<< tm[2][1]<<endl;
//    cout<<"t: "<< tm[2][2]<<endl;
//    cout<<"x: "<< tm[3][0]<<endl;
//    cout<<"y: "<< tm[3][1]<<endl;
//    cout<<"z: "<< tm[3][2]<<endl<<endl;

//    return transforamtion;

    mat4x4 temp;
    temp=mat4x4(1);
    temp=glm::rotate(temp, yaw, vec3(1,0,0));
    temp=glm::rotate(temp, roll, vec3(0,0,1));
    temp=glm::rotate(temp, pitch, vec3(0,1,0));
    tm[3]+=temp[3];
    temp=glm::translate(temp, getLocalPosition());
//    temp=glm::translate(temp, vec3(tm[3][0], tm[3][1], tm[3][2]));

//    tm=temp;
//    return tm;
    return temp;
}

void camera::setTM()
{
    mat4x4 temp;
    temp=mat4x4(1);
    temp=glm::rotate(temp, yaw, vec3(1,0,0));
    temp=glm::rotate(temp, roll, vec3(0,0,1));
    temp=glm::rotate(temp, pitch, vec3(0,1,0));
    tm[3]+=temp[3];
//    temp=glm::translate(temp, getPosition());
    temp=glm::translate(temp, vec3(tm[3][0], tm[3][1], tm[3][2]));

    tm=temp;
}

void camera::rotate(vec3 rot)
{
    rot*=.1;
    yaw+=rot.x;
    pitch+=rot.y;
    roll+=rot.z;
    if(yaw > glm::radians(85.0f))
        yaw =  glm::radians(85.0f);
    if(yaw < glm::radians(-85.0f))
        yaw = glm::radians(-85.0f);

//    cout<<"yaw  : "<< glm::degrees(yaw)<<endl;
//    cout<<"roll : "<< glm::degrees(roll)<<endl;
//    cout<<"pitch: "<< glm::degrees(pitch)<<endl<<endl;

//    vec4 temp;
//    temp=transforamtion[3];
//    transforamtion=mat4x4(1);

//    transforamtion=glm::rotate(transforamtion, rot.x, vec3(1,0,0));
//    transforamtion=glm::rotate(transforamtion, rot.z, vec3(0,0,1));
//    transforamtion=glm::rotate(transforamtion, rot.y, vec3(0,1,0));
//    transforamtion=glm::translate(transforamtion, vec3(temp.x, temp.y, temp.z));
//    transforamtion=glm::rotate(transforamtion, roll, vec3(0,1,0));
}

void camera::translate(vec3 position)
{
//    transforamtion=glm::translate(transforamtion, position);
    mat4x4 temp;
    temp=mat4x4(1);
    temp=glm::rotate(temp, -yaw, vec3(1,0,0));
    temp=glm::rotate(temp, roll, vec3(0,0,1));
    temp=glm::rotate(temp, -pitch, vec3(0,1,0));
    temp=glm::translate(temp, position);
    temp[3]+=tm[3];
    tm=mat4x4(1);
    tm[3]+=temp[3];
//    transforamtion=glm::rotate(transforamtion, yaw, vec3(1,0,0));
//    transforamtion=glm::rotate(transforamtion, roll, vec3(0,1,0));
//    transforamtion=glm::rotate(transforamtion, pitch, vec3(0,0,1));

//    transforamtion[3][1]+=temp[3][1];
//    transforamtion[3][2]+=temp[3][2];
}

void camera::keyEvent(bool pressedKeys[])
{
    for(int i =0; i< 256; i++)
    {
        float mov=0.1f;
//        float ang=radians(1.f);
        if(pressedKeys[i])
//            cout << "Key: "<<(char) (i)<< endl;
        switch ((char)(i))
        {
        case '+':
            translate(vec3(0.f, .0f, -mov));
            break;
        case '-':
            translate(vec3(0.f, .0f, mov));
            break;
        default:
            break;
        }
    }
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
