#include "vobject.h"
#include "iostream"

#include <QString>

using namespace glm;
using namespace std;

vObject::vObject()
{
    tm=mat4x4(1);
    yaw=pitch=roll=0;
}

//void vObject::draw();

void vObject::translate(vec3 position)
{
    tm=glm::translate(tm, position);
}

void vObject::rotate(vec3 rot)
{
//    vec3 v;
//    v[0]=transforamtion[3][0];
//    v[1]=transforamtion[3][1];
//    v[2]=transforamtion[3][2];
//    transforamtion=mat4x4(1);

    rot*=1;
    yaw+=rot.x;
    pitch+=rot.y;
    roll+=rot.z;
//    if(yaw > glm::radians(85.0f))
//        yaw =  glm::radians(85.0f);
//    if(yaw < glm::radians(-85.0f))
//        yaw = glm::radians(-85.0f);

    cout<<"yaw  : "<< glm::degrees(yaw)<<endl;
    cout<<"roll : "<< glm::degrees(roll)<<endl;
    cout<<"pitch: "<< glm::degrees(pitch)<<endl<<endl;

    mat4x4 temp(1);

    temp=glm::rotate(temp, pitch, vec3(0,1,0));
    temp=glm::rotate(temp, yaw, vec3(1,0,0));
    temp=glm::rotate(temp, roll, vec3(0,0,1));
//    temp=glm::translate(temp, rot);

    tm[0]=temp[0];
    tm[1]=temp[1];
    tm[2]=temp[2];
//    translate(temp[3]);
//    tm*=eulerAngleX(yaw);
//    tm*=eulerAngleY(roll);
//    tm*=eulerAngleZ(pitch);

}

void vObject::keyEvent(bool pressedKeys[])
{
    for(int i =0; i< 256; i++)
    {
        float mov=0.1f;
        float ang=radians(1.f);
        if(pressedKeys[i])
//            cout << "Key: "<<(char) (i)<< endl;
        switch ((char)(i))
        {
        case 'D':
            translate(vec3(mov, 0.f, 0.f));
            break;
        case 'A':
            translate(vec3(-mov, 0.f, 0.f));
            break;
        case 'R':
            translate(vec3(0.f, mov, 0.f));
            break;
        case 'F':
            translate(vec3(0.f, -mov, 0.f));
            break;
        case 'W':
            translate(vec3(0.f, .0f, -mov));
            break;
        case 'S':
            translate(vec3(0.f, .0f, mov));
            break;
        case 'Y':
            rotate(vec3(ang, 0.f, 0.f));
            break;
        case 'H':
            rotate(vec3(-ang, 0.f, 0.f));
            break;
        case 'G':
            rotate(vec3(0.f, ang, 0.f));
            break;
        case 'J':
            rotate(vec3(0.f, -ang, 0.f));
            break;
        case 'Q':
            rotate(vec3(0.f, 0.f, ang));
            break;
        case 'E':
            rotate(vec3(0.f, 0.f,-ang));
            break;
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
    this->rotate(vec3(radians(x) ,0.f ,radians(y)));
}

glm::vec3 vObject::getOrientation() const
{
    return glm::vec3(yaw, pitch, roll);
}

glm::mat4x4 vObject::getTM() const
{
    return tm;
}

void vObject::setTM(const glm::mat4x4 &value)
{
    tm = value;
}

void vObject::setOrientation(glm::vec3 axis)
{
    yaw=axis.x;
    pitch=axis.y;
    roll=axis.z;
}

vec3 vObject::getPosition() const
{
    return vec3(tm[3][0], tm[3][1], tm[3][2]);
}

float vObject::getYaw() const
{
    return yaw;
}

void vObject::setYaw(float value)
{
    yaw = value;
}

float vObject::getPitch() const
{
    return roll;
}

void vObject::setPitch(float value)
{
    roll = value;
}

float vObject::getRoll() const
{
    return pitch;
}

void vObject::setRoll(float value)
{
    pitch = value;
}
