#include "cube.h"

cube::cube()
{
}

void cube::put()
{
//    glLoadIdentity();
    glLoadMatrixf(&transforamtion[0][0]);
    glColor3f(0.5, 0.0 ,0);
    glutSolidCube(.6);
}
