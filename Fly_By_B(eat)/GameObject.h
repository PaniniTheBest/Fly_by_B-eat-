#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "vector3.h"
#include <glut.h>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <ctime>

#pragma once
class GameObject
{
public:
	GameObject();
	void SetPosition(Vector3 newPosition);
	void SetPosition(float x, float y, float z);
	void SetScale(Vector3 newScale);
	void SetScale(float x, float y, float z);
	void SetRotation(float angle, Vector3 rotation);
	void SetRotation(float angle, float x, float y, float z);

	Vector3 GetScale();
	Vector3 GetPosition();

	//void Draw();

private:
	Vector3 position;
	Vector3 scale;
	Vector3 rotation;
	float angle;
};

#endif

