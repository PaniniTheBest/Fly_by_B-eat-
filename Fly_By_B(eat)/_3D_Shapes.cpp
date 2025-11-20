#include "_3D_Shapes.h"

void _3D_Shapes::Create_3D_Cube(float x, float y, float z)
{
    x /= 2;
    y /= 2;
    z /= 2;
    glBegin(GL_QUADS);// Face 1 X-axis
    //if (x > 0)
    glColor3f(1.0f, 0.0f, 0.0f); //red

    glVertex3f(1.0f * x, 1.0f * y, 1.0f * z);
    glVertex3f(1.0f * x, -1.0f * y, 1.0f * z);
    glVertex3f(1.0f * x, -1.0f * y, -1.0f * z);
    glVertex3f(1.0f * x, 1.0f * y, -1.0f * z);
    glEnd();

    glBegin(GL_QUADS);// Face 2 X-axis
    //if (x < 0)
    glColor3f(1.0f, 0.0f, 0.0f); //red

    glVertex3f(-1.0f * x, 1.0f * y, 1.0f * z);
    glVertex3f(-1.0f * x, -1.0f * y, 1.0f * z);
    glVertex3f(-1.0f * x, -1.0f * y, -1.0f * z);
    glVertex3f(-1.0f * x, 1.0f * y, -1.0f * z);
    glEnd();

    glBegin(GL_QUADS);// Face 3 Y-axis 
    //if (y < 0)
    glColor3f(1.0f, 0.9f, 0.0f); //yellow

    glVertex3f(-1.0f * x, -1.0f * y, -1.0f * z);
    glVertex3f(-1.0f * x, -1.0f * y, 1.0f * z);
    glVertex3f(1.0f * x, -1.0f * y, 1.0f * z);
    glVertex3f(1.0f * x, -1.0f * y, -1.0f * z);
    glEnd();

    glBegin(GL_QUADS);// Face 4 Y-axis 
    //if (y > 0)
    glColor3f(1.0f, 0.9f, 0.0f); //yellow

    glVertex3f(-1.0f * x, 1.0f * y, -1.0f * z);
    glVertex3f(-1.0f * x, 1.0f * y, 1.0f * z);
    glVertex3f(1.0f * x, 1.0f * y, 1.0f * z);
    glVertex3f(1.0f * x, 1.0f * y, -1.0f * z);
    glEnd(); 
    
    glBegin(GL_QUADS);// Face 5 Z-axis
    //if (z < 0)
    glColor3f(0.3f, 1.0f, 0.0f); //green

    glVertex3f(-1.0f * x, -1.0f * y, -1.0f * z);
    glVertex3f(-1.0f * x, 1.0f * y, -1.0f * z);
    glVertex3f(1.0f * x, 1.0f * y, -1.0f * z);
    glVertex3f(1.0f * x, -1.0f * y, -1.0f * z);
    glEnd();

    glBegin(GL_QUADS);// Face 6 Z-axis
    //if (z > 0)
    glColor3f(0.3f, 1.0f, 0.0f); //green

    glVertex3f(-1.0f * x, -1.0f * y, 1.0f * z);
    glVertex3f(-1.0f * x, 1.0f * y, 1.0f * z);
    glVertex3f(1.0f * x, 1.0f * y, 1.0f * z);
    glVertex3f(1.0f * x, -1.0f * y, 1.0f * z);
    glEnd();
}