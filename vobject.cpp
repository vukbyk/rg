#include "vobject.h"
#include "GL/gl.h"
#include "GL/glu.h"
#include "GL/glut.h"
#include "iostream"
using namespace glm;
using namespace std;

vObject::vObject()
{
    tm=mat4x4(1);
//    p=vec3(0,0,0);
//    o=vec3(0,0,0);
}

//vObject::vObject(const vec3 &position, const vec3 &oriention=vec3(0,0,0))
//{
//    p=position;
//    o=oriention;
//}

//vec3 vObject::getPosition() const
//{
//    return p;
//}

//void vObject::setPosition(const vec3 &value)
//{
//    p = value;
//}

//vec3 vObject::getOrientation() const
//{
//    return o;
//}

//void vObject::setOrientation(const vec3 &value)
//{
//    o = value;
//}

void vObject::put()
{
//        glRotatef(rotation, 0, 1, 0);
//        glTranslatef(o.p.x ,o.p.y,o.p.z);
//    float v[16] = { 1, 0, 0, 0,
//                    0, 1, 0, 0,
//                    0, 0, 1, 0,
//                    0, 0, 0, 1};
//    glGetFloatv(GL_MODELVIEW_MATRIX, v);
//    for (int n=0; n<4; n++)
//    {
//        cout<<endl;
//        for(int m=0; m<4; m++)
//            std::cout << v[n*4+m] << " ";
//    }
//    cout<<endl;
//    cout<<endl;
        glLoadMatrixf(&tm[0][0]);
//        glLoadIdentity();
//        glMultMatrixf(v);
        glutSolidTeapot(.6);
        glColor3f(0.5, 0.0 ,0);
        glutSolidCube(.6);
}

void vObject::setPosition(vec3 position)
{
    tm=translate(tm, position);
}
