#include "Text.h"
#include <string>
#include <cstring>
#include <fstream>
#include <math.h>
#include <glut.h>

using namespace std;
Text::Text()
{
	TextRGB.SetColor(1.0f, 1.0f, 1.0f);
	Translate.SetValue(0.0f, 0.0f, 0.0f);
}
void RenderString(void* font, float x, float y, string message)
{
	glRasterPos3f(-10, y, 0.0f);
	for (int x = 0; x < message.length(); x++)
	{
		if (message[x] == ' ')
		{
			glutBitmapCharacter(font, ' ');
		}
		else
		{
			glutBitmapCharacter(font, message[x]);
		}
	}
}

void Text::RenderText(string message)
{
	glPushMatrix();
	glColor3f(TextRGB.red, TextRGB.green, TextRGB.blue);
	if (message.length() > 0)
		RenderString(GLUT_BITMAP_HELVETICA_18, 0, 0, message);
	glTranslatef(Translate.x, Translate.y, Translate.z);
	glPopMatrix();
}

void Text::ColorText(float r, float g, float b)
{
	this->TextRGB.SetColor(r, g, b);
}

void Text::ColorText(Color newRGB)
{
	this->TextRGB.SetColor(newRGB);
}

void Text::TranslateText(float x, float y, float z)
{
	this->Translate.SetValue(x, y, z);
}

void Text::TranslateText(Vector3 newTranslate)
{
	this->Translate.SetValue(newTranslate);
}

void Text::RenderVariableAsText(float variable)
{
	glPushMatrix();
	char buffer[256];
	sprintf_s(buffer, "%f", variable);
	glColor3f(TextRGB.red, TextRGB.green, TextRGB.blue);
	RenderString(GLUT_BITMAP_HELVETICA_18, -5, 5, buffer);
	glTranslatef(Translate.x, Translate.y, Translate.z);
	glPopMatrix();
}

void Text::RenderVariableAsText2(float variable, float r, float g, float b)
{
	glPushMatrix();
	char buffer[256];
	sprintf_s(buffer, "%f", variable);
	glColor3f( r,  g,  b);
	RenderString(GLUT_BITMAP_HELVETICA_18, -5, 5, buffer);
	glTranslatef(Translate.x, Translate.y, Translate.z);
	glPopMatrix();
}




