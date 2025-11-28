#include "GameObject.h"


GameObject::GameObject()
{
	position.SetValue(0, 0, 0);
	scale.SetValue(1, 1, 1);
	SetRotation(0, 0, 0, 0);
	collider.SetDimension(position, scale);
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

void GameObject::SetCollider(Vector3 position, Vector3 scale)
{
	collider.SetDimension(position, scale);
}

bool GameObject::CheckCollision(GameObject other)
{
	return collider.CheckCollision(other.collider);
}

Vector3 GameObject::GetScale()
{
	return scale;
}

Vector3 GameObject::GetPosition()
{
	return position;
}


Collider GameObject::GetCollider()
{
	return collider;
}

void GameObject::Draw()
{
	glPushMatrix();
	glTranslatef(position.x, position.y, position.z);
	glRotatef(angle, rotation.x, rotation.y, rotation.z);
	glScalef(scale.x, scale.y, scale.z);
	glutSolidCube(1.0f);
	glPopMatrix();

	collider.SetDimension(position, scale);
}

void GameObject::DrawSphere(float radius, int slices, int stacks)
{
	glPushMatrix();
	glTranslatef(position.x, position.y, position.z);
	glRotatef(angle, rotation.x, rotation.y, rotation.z);
	glScalef(scale.x, scale.y, scale.z);
	glutSolidSphere(radius, slices, stacks);
	glPopMatrix();

	collider.SetDimension(position, scale);
}


//void GameObject::LoadModel(string modelPath)
//{
//	model.LoadOBJ(modelPath);
//}
//
//void GameObject::RenderModel()
//{
//	glPushMatrix();
//	glTranslatef(position.x, position.y, position.z);
//	glRotatef(angle, rotation.x, rotation.y, rotation.z);
//	glScalef(scale.x, scale.y, scale.z);
//	model.RenderModel();
//	glPopMatrix();
//}