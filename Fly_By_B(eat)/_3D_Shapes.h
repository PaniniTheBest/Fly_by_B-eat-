#ifndef _3D_SHAPES_H
#define _3D_SHAPES_H

#include <iostream>
#include "glut.h"
#include <cmath>
using namespace std;
#pragma once
class _3D_Shapes
{
		
	public:
		float X, Y, Z;
		_3D_Shapes();
		_3D_Shapes(float x, float y, float z)
		{
			this -> X = x;
			this -> Y = y;
			this -> Z = z;
		}
		void Create_3D_Cube();
		void Create_3D_Cylinder();
		void Create_3D_Pyramid();
};

#endif
