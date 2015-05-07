#include "floorgrid.h"
#include <GL/glut.h>
#include <GL/glu.h>
#include <iostream>

floorGrid::floorGrid()
{
    std::cout<<"konstukror"<<std::endl;
    span=10;
    r=.9;
    g=.9;
    b=.9;
    std::cout<<"rgb: "<<r<<g<<b<<std::endl;
}

floorGrid::floorGrid(int s, float rr=.9, float gg=.9, float bb=.9)
{
    span=s;
    r=rr;
    g=gg;
    b=bb;
}

floorGrid::floorGrid(float rr, float gg, float bb)
{
    span=10;
    r=rr;
    g=gg;
    b=bb;
}

void floorGrid::put()
{
    glColor3f(r,g,b);
//    std::cout<<"rgb: "<<r<<g<<b<<std::endl;
    glBegin(GL_LINES);
        glVertex3f(-span, 0, 0);
        glVertex3f(span, 0, 0);
    glEnd();
}

