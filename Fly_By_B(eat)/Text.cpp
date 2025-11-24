#include "Text.h"
#include <string>
#include <cstring>
#include <fstream>
#include <math.h>

using namespace std;

void drawText(string message, float red, float green, float blue)
{
	glPushMatrix();
	glColor3f(red, green, blue);
	if (message.length() > 0)
		RenderString(GLUT_BITMAP_HELVETICA_18, 0, 0, message);
	glPopMatrix();
}

void drawValue(float value, float red, float green, float blue)
{
	glPushMatrix();
	char buffer[256];
	sprintf_s(buffer, "%f", value);
	glColor3f(red, green, blue);
	RenderString(GLUT_BITMAP_HELVETICA_18, -5, 5, buffer);
	glPopMatrix();
}

void RenderString(void* font, float x, float y, string message)
{
	char space = ' ';

	glRasterPos3f(-10, y, 0.0f);
	for (int x = 0; x < message.length(); x++)
	{
		if (message[x] == ' ')
		{
			glutBitmapCharacter(font, space);
		}
		else
		{
			glutBitmapCharacter(font, message[x]);
		}
	}
}

