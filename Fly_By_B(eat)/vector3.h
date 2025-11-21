#ifndef VECTOR3_H
#define VECTOR3_H

#pragma once

class Vector3
{
public:
	float x, y, z;
	Vector3();
	Vector3(float x, float y, float z);

	void SetValue(float x, float y, float z);
	void SetValue(Vector3 other);

	Vector3 GetValue();

	Vector3 operator+(const Vector3& other);
	Vector3 operator+=(const Vector3& other);

	Vector3 operator-(const Vector3& other);
	Vector3 operator-=(const Vector3& other);

	Vector3 operator*(const Vector3& other);
	Vector3 operator*=(const Vector3& other);
};

#endif

