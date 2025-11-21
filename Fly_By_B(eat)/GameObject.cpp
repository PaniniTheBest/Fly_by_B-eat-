#include "Player.h"


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