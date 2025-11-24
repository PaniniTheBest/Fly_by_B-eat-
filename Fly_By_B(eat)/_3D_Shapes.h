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
		float red = 0.5f, green = 0.5f, blue = 0.5f;//RGB colors
		float moveX = 0.0f, moveY = 0.0f, moveZ = 0.0f; //Moving object
		float scaleX = 1.0f, scaleY = 1.0f, scaleZ = 1.0f;//Size scaling
		float angle = 0.0f, rotateX = 0.0f, rotateY = 0.0f, rotateZ = 0.0f;//Rotation
	public:
		_3D_Shapes();
		_3D_Shapes(	float red, float green, float blue,
					float moveX, float moveY, float moveZ,
					float scaleX, float scaleY, float scaleZ, 
					float angle, float rotateX, float rotateY, float rotateZ)
		{
			this->red = red; this->green = green; this->blue = blue;
			this->moveX = moveX; this->moveY = moveY; this->moveZ = moveZ;
			this->scaleX = scaleX; this->scaleY = scaleY; this->scaleZ = scaleZ;
			this->rotateX = rotateX; this->rotateY = rotateY; this->rotateZ = rotateZ;
		}
		void Apply_Color(float r, float g, float b);
		void Move_Object (float x, float y, float z); //in progress
		void Rotate_Object(float angle, float x, float y, float z); // in progress
		void Transform_Object_Size(float x, float y, float z); // in progress

		void Create_3D_Cube(float x, float y, float z);
		void Create_3D_Sphere(double radius, double slices, double stacks);
		void Create_3D_Cone(float radius, float height, int slices);
		void Create_3D_Cylinder(float radius, float height, int slices);
};
#endif
