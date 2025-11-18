#include "_3D_Shapes.h"

void _3D_Shapes::Create_3D_Cube(float x, float y, float z)
{
	glBegin(GL_QUADS); //RED SIDE Z-based//
	glVertex3f(-1, 1, -1);
	glVertex3f(1, 1, -1);
	glVertex3f(1, -1, -1);
	glVertex3f(-1, -1, -1);
	/*if (z > 0)
	{
		glColor3f(1.0, 0, 0);
	}
	else
	{
		glColor3f(1.0, 1.0, 1.0);
	}*/
	glEnd();

	glBegin(GL_QUADS); //CYAN SIDE X-based//
	glVertex3f(-1, 1, 1);
	glVertex3f(1, 1, 1);
	glVertex3f(1, -1, 1);
	glVertex3f(-1, -1, 1);
	/*if (x < 0)
	{
		glColor3f(0, 1.0, 1.0);
	}
	else
	{
		glColor3f(1.0, 1.0, 1.0);
	}*/
	glEnd();

	glBegin(GL_QUADS); //YELLOW SIDE X-based//
	glVertex3f(-1, 1, 1);
	glVertex3f(-1, -1, 1);
	glVertex3f(-1, -1, -1);
	glVertex3f(-1, 1, -1);
	/*if (x > 0)
	{
		glColor3f(1.0, 1.0, 0);
	}
	else
	{
		glColor3f(1.0, 1.0, 1.0);
	}*/
	glEnd();

	glBegin(GL_QUADS); //GREEN SIDE Y-based//
	glVertex3f(1, 1, 1);
	glVertex3f(1, -1, 1);
	glVertex3f(1, -1, -1);
	glVertex3f(1, 1, -1);
	/*if (y < 0)
	{
		glColor3f(0, 1.0, 0);
	}
	else
	{
		glColor3f(1.0, 1.0, 1.0);
	}*/
	glEnd();

	glBegin(GL_QUADS); // BLUE SIDE Y-based//
	glVertex3f(-1, -1, 1);
	glVertex3f(1, -1, 1);
	glVertex3f(1, -1, -1);
	glVertex3f(-1, -1, -1);
	/*if (y > 0)
	{
		glColor3f(0, 0, 1.0);
	}
	else
	{
		glColor3f(1.0, 1.0, 1.0);
	}*/
	glEnd();

	glBegin(GL_QUADS); //PURPLE SIDE Y-based//
	glVertex3f(-1, 1, 1);
	glVertex3f(1, 1, 1);
	glVertex3f(1, 1, -1);
	glVertex3f(-1, 1, -1);
	/*if (z > 0)
	{
		glColor3f(1.0, 0, 1.0);
	}
	else
	{
		glColor3f(1.0, 1.0, 1.0);
	}*/
	glEnd();
}