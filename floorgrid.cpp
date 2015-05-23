#include "floorgrid.h"

floorGrid::floorGrid()
{
    span=10;
    r=.9;
    g=.9;
    b=.9;
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

void floorGrid::draw()
{
//    this->setPosition(glm::vec3(3,0,0));
//    glMatrixMode(GL_MODELVIEW);
    glLoadMatrixf(&tm[0][0]);
//    glDisable(GL_TEXTURE_2D);
//    glDisable(GL_BLEND);
    glColor3f(r,g,b);
//    std::cout<<"rgb: "<<r<<g<<b<<std::endl;
    glLineWidth(3);
    glBegin(GL_LINES);
        glVertex3f(-span, 0, 0);
        glVertex3f(span, 0, 0);
        glVertex3f(0, 0,-span);
        glVertex3f(0, 0,span);

        glVertex3f(-span, 0, span);
        glVertex3f(span, 0, span);
        glVertex3f(-span, 0, -span);
        glVertex3f(span, 0, -span);
        glVertex3f(-span, 0, -span);
        glVertex3f(-span, 0, span);
        glVertex3f(span, 0, -span);
        glVertex3f(span, 0, span);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
        for(int i=1; i<span; i++)
        {
            glVertex3f(-span, 0, i);
            glVertex3f(span, 0, i);
            glVertex3f(-span, 0, -i);
            glVertex3f(span, 0, -i);
            glVertex3f(i, 0, -span);
            glVertex3f(i, 0, span);
            glVertex3f(-i, 0, -span);
            glVertex3f(-i, 0, span);
        }
    glEnd();
}

