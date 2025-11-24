#ifndef TEXT_H
#define TEXT_H

#include <iostream>
#include <glut.h>
#include <string>
using namespace std;

void RenderString(void* font, float x, float y, string message);
void drawText(string message, float red, float green, float blue);
void drawValue(float value, float red, float green, float blue);

#endif

