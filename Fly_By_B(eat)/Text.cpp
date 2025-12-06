#include "Text.h"
#include "Engine.h"
#include <string>
#include <cstring>
#include <fstream>
#include <math.h>
#include <glut.h>

//https://stackoverflow.com/questions/2183270/what-is-the-easiest-way-to-print-text-to-screen-in-opengl
//https://stackoverflow.com/questions/58713840/how-to-draw-text-to-the-screen-using-glutbitmapcharacter
using namespace std;
Text::Text()
{
	TextRGB.SetColor(1.0f, 1.0f, 1.0f);
	Translate.SetValue(0.0f, 0.0f, 0.0f);
}
void Text::RenderString(void* font, float x, float y, string message)
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
	glTranslatef(Translate.x, Translate.y, Translate.z);
	glColor3f(TextRGB.red, TextRGB.green, TextRGB.blue);
	glRasterPos3f(0, 0, 0);
	if (message.length() > 0)
		RenderString(GLUT_BITMAP_HELVETICA_18, 0, 0, message);
	
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
void Text::RenderFloatVariableAsText(float variable)
{
	glPushMatrix();
	glTranslatef(Translate.x, Translate.y, Translate.z);
	char buffer[256];
	sprintf_s(buffer, "%f", variable);
	glColor3f(TextRGB.red, TextRGB.green, TextRGB.blue);
	RenderString(GLUT_BITMAP_HELVETICA_18, -5, 5, buffer);
	glPopMatrix();
}

void Text::RenderIntVariableAsText(int variable)
{
	glPushMatrix();
	glTranslatef(Translate.x, Translate.y, Translate.z);
	char buffer[256];
	sprintf_s(buffer, "%i", variable);
	glColor3f(TextRGB.red, TextRGB.green, TextRGB.blue);
	RenderString(GLUT_BITMAP_HELVETICA_18, -5, 5, buffer);
	glPopMatrix();
}

Vector3 Text::GetCurrentPosition()
{
	return this->Translate;
}

//float LinearInterpolate(float currentPos, float farawayPos, float t) //Finding the values between coordinates, Also called LERP
//{
//	//t represents how close the value is to any given position.
//	//Near 0, it is close to currentPos. Near 1, it is close to farawayPos.
//	return currentPos + t * (farawayPos - currentPos);
//}
//
//Vector3 GetLERPPoints(Vector3 Origin, Vector3 Destination, float t)
//{
//	Vector3 lerpedPosition;
//	Vector3 originPos = Origin;
//	Vector3 destPos = Destination;
//
//	lerpedPosition.x = LinearInterpolate(originPos.x, destPos.x, t);
//	lerpedPosition.y = LinearInterpolate(originPos.y, destPos.y, t);
//	lerpedPosition.z = LinearInterpolate(originPos.z, destPos.z, t);
//
//	return lerpedPosition;
//}




