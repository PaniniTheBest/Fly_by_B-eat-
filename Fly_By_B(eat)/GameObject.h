#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "vector3.h"
#include "Render_3D_Shapes.h"
#include "Collider.h"
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
	void SetCollider(Vector3 position, Vector3 scale);
	bool CheckCollision(GameObject other);


	Vector3 GetScale();
	Vector3 GetPosition();
	Collider GetCollider();

	void Draw();
	void DrawSphere(float radius, int slices, int stacks);

private:
	Vector3 position;
	Vector3 scale;
	Vector3 rotation;
	float angle;
	Collider collider;
};

#endif

