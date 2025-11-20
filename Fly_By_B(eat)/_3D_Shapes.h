#ifndef _3D_SHAPES_H
#define _3D_SHAPES_H

//#include <iostream>
#include "glut.h"
#include <cmath>
#include "_3D_Shapes.h"

using namespace std;
class _3D_Shapes
{	
	public:
		void Move_Object (float x, float y, float z);
		void Create_3D_Cube(float x, float y, float z);
		void Create_3D_Sphere(float x, float y, float z);
		//void Create_3D_Cylinder();
		//void Create_3D_Pyramid();
};
#endif
