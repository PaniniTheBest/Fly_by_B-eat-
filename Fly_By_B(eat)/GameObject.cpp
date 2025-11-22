#include "GameObject.h"


GameObject::GameObject()
{
	position.SetValue(0, 0, 0);
	scale.SetValue(1, 1, 1);
	SetRotation(0, 0, 0, 0);
}

void GameObject::SetPosition(Vector3 newPosition)
{
	position.SetValue(newPosition);
}

void GameObject::SetPosition(float x, float y, float z)
{
	position.SetValue(x, y, z);
}

void GameObject::SetScale(Vector3 newScale)
{
	scale.SetValue(newScale);
}

void GameObject::SetScale(float x, float y, float z)
{
	scale.SetValue(x, y, z);
}

void GameObject::SetRotation(float angle, Vector3 rotation)
{
	this->angle = angle;
	rotation.SetValue(rotation);
}

void GameObject::SetRotation(float angle, float x, float y, float z)
{
	this->angle = angle;
	rotation.SetValue(x, y, z);
}

Vector3 GameObject::GetScale()
{
	return scale;
}

Vector3 GameObject::GetPosition()
{
	return position;
}