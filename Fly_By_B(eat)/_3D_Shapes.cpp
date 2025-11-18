#include "_3D_Shapes.h"

void Create_3D_Cube(float x, float y, float z)
{
    glBegin(GL_QUADS);// Face 1 Z-axis
    if (z < 0)
        glColor3f(0.3f, 1.0f, 0.0f); //green

    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glEnd();

    glBegin(GL_QUADS);// Face 2 Z-axis
    if (z > 0)
        glColor3f(0.5f, 0.5f, 1.0f); //blue

    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glEnd();

    glBegin(GL_QUADS);// Face 3 X-axis
    if (x > 0)
        glColor3f(1.0f, 0.3f, 0.0f); //orange

    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glEnd();

    glBegin(GL_QUADS);// Face 4 X-axis
    if (x < 0)
        glColor3f(1.0f, 0.0f, 0.0f); //red

    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glEnd();

    glBegin(GL_QUADS);// Face 5 Y-axis 
    if (y < 0)
        glColor3f(1.0f, 0.9f, 0.0f); //yellow

    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glEnd();

    glBegin(GL_QUADS);// Face 6 Y-axis 
    if (y > 0)
        glColor3f(1.0f, 0.9f, 0.8f); //pearl-white

    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glEnd();
}