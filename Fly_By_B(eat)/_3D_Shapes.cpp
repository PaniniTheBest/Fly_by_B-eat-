#include "_3D_Shapes.h"

const float PI = 3.14; // Value of PI  

_3D_Shapes::_3D_Shapes(){}

void _3D_Shapes::Apply_Color(float r, float g, float b)
{
    red = r / 255;
    green = g / 255;
    blue = b / 255;
}
void _3D_Shapes::Move_Object(float x, float y, float z)
{
    moveX = x; moveY = y; moveZ = z;
}
void _3D_Shapes::Rotate_Object(float shapeAngle, float x, float y, float z)
{
    angle = shapeAngle;
    rotateX = x;
    rotateY = y;
    rotateZ = z;    
}
void _3D_Shapes::Transform_Object_Size(float x, float y, float z)
{
    glScalef (x, y, z);
}

void _3D_Shapes::Create_3D_Cube(float x, float y, float z)
{   
    glPushMatrix();
    glColor3f(red, green, blue);
    glTranslatef(moveX, moveY, moveZ);
    glRotatef(angle, rotateX, rotateY, rotateZ);

    glBegin(GL_QUADS);// Face 1 X-axis
    glVertex3f(0.5f * x, 0.5f * y, 0.5f * z);
    glVertex3f(0.5f * x, -0.5f * y, 0.5f * z);
    glVertex3f(0.5f * x, -0.5f * y, -0.5f * z);
    glVertex3f(0.5f * x, 0.5f * y, -0.5f * z);
    glEnd();

    glBegin(GL_QUADS);// Face 2 X-axis
    glVertex3f(-0.5f * x, 0.5f * y, 0.5f * z);
    glVertex3f(-0.5f * x, -0.5f * y, 0.5f * z);
    glVertex3f(-0.5f * x, -0.5f * y, -0.5f * z);
    glVertex3f(-0.5f * x, 0.5f * y, -0.5f * z);
    glEnd();

    glBegin(GL_QUADS);// Face 3 Y-axis 
    glVertex3f(-0.5f * x, -0.5f * y, -0.5f * z);
    glVertex3f(-0.5f * x, -0.5f * y, 0.5f * z);
    glVertex3f(0.5f * x, -0.5f * y, 0.5f * z);
    glVertex3f(0.5f * x, -0.5f * y, -0.5f * z);
    glEnd();

    glBegin(GL_QUADS);// Face 4 Y-axis 
    glVertex3f(-0.5f * x, 0.5f * y, -0.5f * z);
    glVertex3f(-0.5f * x, 0.5f * y, 0.5f * z);
    glVertex3f(0.5f * x, 0.5f * y, 0.5f * z);
    glVertex3f(0.5f * x, 0.5f * y, -0.5f * z);
    glEnd(); 
    
    glBegin(GL_QUADS);// Face 5 Z-axis
    glVertex3f(-0.5f * x, -0.5f * y, -0.5f * z);
    glVertex3f(-0.5f * x, 0.5f * y, -0.5f * z);
    glVertex3f(0.5f * x, 0.5f * y, -0.5f * z);
    glVertex3f(0.5f * x, -0.5f * y, -0.5f * z);
    glEnd();

    glBegin(GL_QUADS);// Face 6 Z-axis
    glVertex3f(-0.5f * x, -0.5f * y, 0.5f * z);
    glVertex3f(-0.5f * x, 0.5f * y, 0.5f * z);
    glVertex3f(0.5f * x, 0.5f * y, 0.5f * z);
    glVertex3f(0.5f * x, -0.5f * y, 0.5f * z);
    glEnd();
    glPopMatrix();
}
void _3D_Shapes::Create_3D_Sphere(double radius, double slices, double stacks)
{
    glPushMatrix();
    glColor3f(red, green, blue); 
    glTranslatef(moveX, moveY, moveZ);  
    glRotatef(angle, rotateX, rotateY, rotateZ);

    glutSolidSphere(radius, slices, stacks); 
    glPopMatrix(); 
}
void _3D_Shapes::Create_3D_Cone(float radius, float height, int slices)
{   
    float angleIncrement = (2.0f * PI) / slices;// Calculate angle increment based on number of slices
    float renderAngle = 0.0f;
    glPushMatrix(); 
    glColor3f(red, green, blue);
    glTranslatef(moveX, moveY, moveZ);   
    glRotatef(this->angle, rotateX, rotateY, rotateZ);

    // Draws the sides of the cone
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0, height, 0);  // Apex at top (Y-axis up)
    for (int i = 0; i <= slices; i++) {
        renderAngle = i * angleIncrement;
        glVertex3f(cos(renderAngle) * radius, 0, sin(renderAngle) * radius);
    }
    glEnd();

    // Draws the base of the cone
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0, 0, 0);  // Center of base
    for (int i = 0; i <= slices; i++) {
        renderAngle = i * angleIncrement;
        glNormal3f(0, -1, 0);  // Normal pointing down for base
        glVertex3f(cos(renderAngle) * radius, 0, sin(renderAngle) * radius);
    }
    glEnd();
    glPopMatrix(); 
}
void _3D_Shapes::Create_3D_Cylinder(float radius, float height, int slices)
{   
    float angleIncrement = (2.0f * PI) / slices;// Calculate angle increment based on number of slices
    float renderAngle = 0.0f;
    glPushMatrix(); 
    glColor3f(red, green, blue);   
    glTranslatef(moveX, moveY, moveZ); 

    // Draws top side of Cylinder
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0, height, 0);  // Center of top cap
    for (int i = 0; i <= slices; i++) {
        renderAngle = i * angleIncrement;
        glNormal3f(0, 1, 0);  // Normal pointing up
        glVertex3f(cos(renderAngle) * radius, height, sin(renderAngle) * radius);
    }
    glEnd();
    // Draws bottom side of Cylinder
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0, 0, 0);  // Center of base
    for (int i = 0; i <= slices; i++) {
        renderAngle = i * angleIncrement;
        glNormal3f(0, -1, 0);  // Normal pointing down
        glVertex3f(cos(renderAngle) * radius, 0, sin(renderAngle) * radius);
    }
    glEnd();
    // Draws sides of Cylinder
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= slices; i++) {
        renderAngle = i * angleIncrement;
        glNormal3f(cos(renderAngle), 0, sin(renderAngle));  // Outward normal
        glVertex3f(cos(renderAngle) * radius, 0, sin(renderAngle) * radius);
        glVertex3f(cos(renderAngle) * radius, height, sin(renderAngle) * radius);
    }
    glEnd();
    glPopMatrix();
}