#ifndef _3D_SHAPES_H
#define _3D_SHAPES_H

//#include <iostream>
#include "glut.h"
#include <cmath>
#include "_3D_Shapes.h"

using namespace std;
class _3D_Shapes
{
	private:
		float red = 0.5f, green = 0.5f, blue = 0.5f;
	public:
		_3D_Shapes();
		_3D_Shapes(float red, float green, float blue)
		{
			this->red = red;
			this->green = green;
			this->blue = blue;
		}
		void Apply_Color(float r, float g, float b);
		void Move_Object (float x, float y, float z);
		void Create_3D_Cube(float x, float y, float z);
		void Create_3D_Sphere(double radius, double slices, double stacks);
		//void Create_3D_Cylinder();
		//void Create_3D_Pyramid();
};
#endif
