#include "color.h"

Color::Color()
{
	red = 1.0f;
	green = 1.0f;
	blue = 1.0f;
	alpha = 1.0f;
}

Color::Color(float red, float green, float blue)
{
	this->red = red;
	this->green = green;
	this->blue = blue;
	alpha = 1.0f;
}

Color::Color(float red, float green, float blue, float alpha)
{
	this->red = red;
	this->green = green;
	this->blue = blue;
	this->alpha = alpha;
}

void Color::SetColor(float red, float green, float blue)
{
	this->red = red / 255;
	this->green = green / 255;
	this->blue = blue / 255;
	alpha = 1.0f;
}

void Color::SetColor(float red, float green, float blue, float alpha)
{
	this->red = red / 255;
	this->green = green / 255;
	this->blue = blue / 255;
	this->alpha = alpha;
}

void Color::SetColor(Color newColor)
{
	this->red = newColor.red / 255;
	this->green = newColor.green / 255;
	this->blue = newColor.blue / 255;
	this->alpha = newColor.alpha;
}
