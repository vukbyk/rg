#include "vobject.h"
#include "iostream"

#include <QString>

using namespace glm;
using namespace std;

vObject::vObject()
{
    transforamtion=mat4x4(1);
    
}

void vObject::put()
{
    
}

void vObject::setPosition(vec3 position)
{
    transforamtion=translate(transforamtion, position);
}

void vObject::setRotation(float angle, vec3 axis)
{
    mat4x4 temp;
    temp=transforamtion;
    transforamtion=mat4x4(1);
    transforamtion=glm::rotate(transforamtion, radians(angle), axis);
    transforamtion=transforamtion*temp;
}

void vObject::keyEvent(bool pressedKeys[])
{
    for(int i =0; i< 256; i++)
    {
        if(pressedKeys[i])
//            cout << "Key: "<<(char) (i)<< endl;
        switch ((char)(i))
        {
        case 'D':
            setPosition(vec3(.05,0.f,0.f));
            break;
        case 'A':
            setPosition(vec3(-.05f,0.f,0.f));
            break;
        case 'R':
            setPosition(vec3(0.f,.05f,0.f));
            break;
        case 'F':
            setPosition(vec3(0,-.05f,0));
            break;
        case 'W':
            setPosition(vec3(0.f,.0f,-.05f));
            break;
        case 'S':
            setPosition(vec3(0.f,.0f,.05f));
        default:
            break;
        }
    }
//    QString temp("");
//    for(int i =0; i< 256; i++)
//    {
//        if( pressedKeys[i])
//        {
//            temp+= char(i);
//        }
//    }
//    if(temp.size() == 0)
//    temp = "none";
    //    cout << "currently Pressed Keys are: "<< temp.toUtf8().constData()<< endl;
}

void vObject::mouseEvent(float x, float y)
{
    setRotation(10, vec3(0,1,0));
}
