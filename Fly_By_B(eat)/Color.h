#ifndef COLOR_H
#define COLOR_H
#include "Color.h"
// Create your custom color class
class Color
{
public:
	float red;
	float green;
	float blue;
	float alpha;

	Color();
	Color(float red, float green, float blue);
	//Color(Color newColor);
	Color(float red, float green, float blue, float alpha);
	//Color(Color newColor);

	void SetColor(float red, float green, float blue);
	void SetColor(float red, float green, float blue, float alpha);
	void SetColor(Color newColor);
	// For setting RGB values up to 255
	// void SetColor(int red, int green, int blue);
};
#endif