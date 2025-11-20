#include "_3D_Shapes.h"
#include<GL/glu.h>

const double PI = 3.1415926535897; // Value of PI  

//struct Color
//{
//    public:
//        float red = 1.0f, green = 1.0f, blue = 1.0f;
//};
//Color apply_Color;
_3D_Shapes::_3D_Shapes()
{

}
void _3D_Shapes::Apply_Color(float r, float g, float b)
{
    red = r / 255;
    green = g / 255;
    blue = b / 255;
}
void _3D_Shapes::Move_Object(float x, float y, float z)
{
    glTranslatef(x, y ,z);
}
void _3D_Shapes::Create_3D_Cube(float x, float y, float z)
{
    x /= 2;
    y /= 2;
    z /= 2;
    glBegin(GL_QUADS);// Face 1 X-axis
    glColor3f(red, green, blue);

    glVertex3f(1.0f * x, 1.0f * y, 1.0f * z);
    glVertex3f(1.0f * x, -1.0f * y, 1.0f * z);
    glVertex3f(1.0f * x, -1.0f * y, -1.0f * z);
    glVertex3f(1.0f * x, 1.0f * y, -1.0f * z);
    glEnd();

    glBegin(GL_QUADS);// Face 2 X-axis
    glColor3f(red, green, blue);

    glVertex3f(-1.0f * x, 1.0f * y, 1.0f * z);
    glVertex3f(-1.0f * x, -1.0f * y, 1.0f * z);
    glVertex3f(-1.0f * x, -1.0f * y, -1.0f * z);
    glVertex3f(-1.0f * x, 1.0f * y, -1.0f * z);
    glEnd();

    glBegin(GL_QUADS);// Face 3 Y-axis 
    glColor3f(red, green, blue);

    glVertex3f(-1.0f * x, -1.0f * y, -1.0f * z);
    glVertex3f(-1.0f * x, -1.0f * y, 1.0f * z);
    glVertex3f(1.0f * x, -1.0f * y, 1.0f * z);
    glVertex3f(1.0f * x, -1.0f * y, -1.0f * z);
    glEnd();

    glBegin(GL_QUADS);// Face 4 Y-axis 
    glColor3f(red, green, blue);

    glVertex3f(-1.0f * x, 1.0f * y, -1.0f * z);
    glVertex3f(-1.0f * x, 1.0f * y, 1.0f * z);
    glVertex3f(1.0f * x, 1.0f * y, 1.0f * z);
    glVertex3f(1.0f * x, 1.0f * y, -1.0f * z);
    glEnd(); 
    
    glBegin(GL_QUADS);// Face 5 Z-axis
    glColor3f(red, green, blue);

    glVertex3f(-1.0f * x, -1.0f * y, -1.0f * z);
    glVertex3f(-1.0f * x, 1.0f * y, -1.0f * z);
    glVertex3f(1.0f * x, 1.0f * y, -1.0f * z);
    glVertex3f(1.0f * x, -1.0f * y, -1.0f * z);
    glEnd();

    glBegin(GL_QUADS);// Face 6 Z-axis
    glColor3f(red, green, blue);

    glVertex3f(-1.0f * x, -1.0f * y, 1.0f * z);
    glVertex3f(-1.0f * x, 1.0f * y, 1.0f * z);
    glVertex3f(1.0f * x, 1.0f * y, 1.0f * z);
    glVertex3f(1.0f * x, -1.0f * y, 1.0f * z);
    glEnd();
}
void _3D_Shapes::Create_3D_Sphere(double radius, double slices, double stacks)
{
    glPushMatrix();
    glColor3f(red, green, blue);
    glutSolidSphere(radius, slices, stacks);
    glPopMatrix();
}
/*
    //A bunch of code that My fible mind did not digest

    // Stores the sphere's texture
    GLuint texture[1];
    // Vertex structure to store position and texture coordinates
    typedef struct {
        float X, Y, Z;  // Vertex coordinates
        double U, V;    // Texture coordinates
    } VERTICES;

    // Constants for calculations
    const int space = 10;              // Angular step size for sphere segments
    const int VertexCount = (90 / space) * (360 / space) * 4; // Total vertices
    VERTICES VERTEX[VertexCount];      // Array to store sphere vertices

    int n = 0; // Vertex counter
    for (double b = 0; b <= 90 - space; b += space)
    {
        for (double a = 0; a <= 360 - space; a += space)
        {
            // Vertex 1
            VERTEX[n].X = R * sin((a) / 180 * PI) * sin((b) / 180 * PI) - H;
            VERTEX[n].Y = R * cos((a) / 180 * PI) * sin((b) / 180 * PI) + K;
            VERTEX[n].Z = R * cos((b) / 180 * PI) - Z;
            VERTEX[n].U = (a) / 360;
            VERTEX[n].V = (2 * b) / 360;
            n++;

            // Vertex 2
            VERTEX[n].X = R * sin((a) / 180 * PI) * sin((b + space) / 180 * PI) - H;
            VERTEX[n].Y = R * cos((a) / 180 * PI) * sin((b + space) / 180 * PI) + K;
            VERTEX[n].Z = R * cos((b + space) / 180 * PI) - Z;
            VERTEX[n].U = (a) / 360;
            VERTEX[n].V = (2 * (b + space)) / 360;
            n++;

            // Vertex 3
            VERTEX[n].X = R * sin((a + space) / 180 * PI) * sin((b) / 180 * PI) - H;
            VERTEX[n].Y = R * cos((a + space) / 180 * PI) * sin((b) / 180 * PI) + K;
            VERTEX[n].Z = R * cos((b) / 180 * PI) - Z;
            VERTEX[n].U = (a + space) / 360;
            VERTEX[n].V = (2 * b) / 360;
            n++;

            // Vertex 4
            VERTEX[n].X = R * sin((a + space) / 180 * PI) * sin((b + space) / 180 * PI) - H;
            VERTEX[n].Y = R * cos((a + space) / 180 * PI) * sin((b + space) / 180 * PI) + K;
            VERTEX[n].Z = R * cos((b + space) / 180 * PI) - Z;
            VERTEX[n].U = (a + space) / 360;
            VERTEX[n].V = (2 * (b + space)) / 360;
            n++;
        }
    }

    glBindTexture(GL_TEXTURE_2D, texture[0]); // Bind the texture
    glBegin(GL_TRIANGLE_STRIP);
    glScalef(0.0125 * R, 0.0125 * R, 0.0125 * R); // Scale the sphere
    for (int b = 0; b <= VertexCount; b++) {
        glTexCoord2f(VERTEX[b].U, VERTEX[b].V);
        glVertex3f(VERTEX[b].X, VERTEX[b].Y, -VERTEX[b].Z);
    }
    for (int b = 0; b <= VertexCount; b++) {
        glTexCoord2f(VERTEX[b].U, -VERTEX[b].V);
        glVertex3f(VERTEX[b].X, VERTEX[b].Y, VERTEX[b].Z);
    }
    glEnd();
    */