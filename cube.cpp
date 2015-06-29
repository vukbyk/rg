#include "cube.h"


cube::cube()
{
}

void cube::draw()
{
//    glMatrixMode(GL_MODELVIEW);
//        glLoadIdentity();
        glPushMatrix();
        glLoadMatrixf(&getWorldTM()[0][0]);
//        glLoadMatrixf(&tm[0][0]);
//            glTranslated(getPosition().x, getPosition().y, getPosition().z);
//            glRotatef(yaw, 1,0,0);
//            glRotatef(roll, 0,0,1);
//            glRotatef(pitch, 0,1,0);
            glColor3f(0.5, 0.0 ,0);
            glutSolidCube(.5);
            glTranslated(1, 0, 0);
            glutSolidCube(.5);
            glTranslated(0, 0, 1);
            glutSolidCube(.5);
            glTranslated(-1, 0, 0);
            glutSolidCube(.5);
            glTranslated(-1, 0, 0);
            glutSolidCube(.5);
            glTranslated(0, 0, -1);
            glutSolidCube(.5);
            glTranslated(0, 0, -1);
            glutSolidCube(.5);
            glTranslated(1, 0, 0);
            glutSolidCube(.5);
            glTranslated(1, 0, 0);
            glutSolidCube(.5);
            glTranslated(-1, 0, -1);
            glutSolidCube(.5);
        glPopMatrix();
}
