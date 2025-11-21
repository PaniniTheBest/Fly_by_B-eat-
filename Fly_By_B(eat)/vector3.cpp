#include "vector3.h"

Vector3::Vector3()
{
	x = 0;
	y = 0;
	z = 0;
}

Vector3::Vector3(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

void Vector3::SetValue(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

void Vector3::SetValue(Vector3 other)
{
	this->x = other.x;
	this->y = other.y;
	this->z = other.z;
}

Vector3 Vector3::GetValue()
{
	return Vector3(x, y, z);
}

Vector3 Vector3::operator+(const Vector3& other)
{
	Vector3 sum;
	sum.x = this->x + other.x;
	sum.x = this->x + other.x;
	sum.x = this->x + other.x;
	return sum;
}

Vector3 Vector3::operator+=(const Vector3& other)
{
	Vector3 sum;
	sum.x = this->x += other.x;
	sum.x = this->x += other.x;
	sum.x = this->x += other.x;
	return sum;
}

Vector3 Vector3::operator-(const Vector3& other)
{
	Vector3 difference;
	difference.x = this->x - other.x;
	difference.x = this->x - other.x;
	difference.x = this->x - other.x;
	return difference;
}

Vector3 Vector3::operator-=(const Vector3& other)
{
	Vector3 difference;
	difference.x = this->x -= other.x;
	difference.x = this->x -= other.x;
	difference.x = this->x -= other.x;
	return difference;
}

Vector3 Vector3::operator*(const Vector3& other)
{
	Vector3 product;
	product.x = this->x * other.x;
	product.x = this->x * other.x;
	product.x = this->x * other.x;
	return product;
}

Vector3 Vector3::operator*=(const Vector3& other)
{
	Vector3 product;
	product.x = this->x *= other.x;
	product.x = this->x *= other.x;
	product.x = this->x *= other.x;
	return product;
}
