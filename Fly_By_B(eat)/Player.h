#ifndef PLAYER_H
#define PLAYER_H

#include <glut.h>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <ctime>

#pragma once
class GameObject
{
public:
	float posX, posY, posZ;
	float velX, velY, velZ;
	float accX, accY, accZ;
	float rotX, rotY, rotZ;
	float moveX = 0.0f;
	float moveY = 0.0f;

	GameObject()
	{
		posX = 0;
		posY = 0;
		posZ = 0;

		rotX = 0;
		rotY = 0;
		rotZ = 0;

		accX = 0;
		accY = 0;
		accZ = 0;

		velX = 0;
		velY = 0;
		velZ = 0;
	}

	void SetPosition(float posX, float posY, float posZ)
	{
		this->posX = posX;
		this->posY = posY;
		this->posZ = posZ;
	}

	void SetRotation(float rotX, float rotY, float rotZ, float angle)
	{
		this->rotX = rotX;
		this->rotY = rotY;
		this->rotZ = rotZ;
	}

	void SetVelocity(float velX, float velY, float velZ)
	{
		this->velX = velX;
		this->velY = velY;
		this->velZ = velZ;
	}

	void SetAcceleration(float accX, float accY, float accZ)
	{
		this->accX = accX;
		this->accY = accY;
		this->accZ = accZ;
	}
};

#endif

