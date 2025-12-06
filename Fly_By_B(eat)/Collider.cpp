#include "collider.h"
#include "RenderObjects.h"



Collider::Collider()
{
	position.SetValue(0, 0, 0);
	scale.SetValue(1, 1, 1);
}

void Collider::SetDimension(Vector3 position, Vector3 scale)
{
	this->position = position;
	this->scale = scale;
}
bool Collider::CheckCollision(Collider other)
{
	// Apply AABB Collision logic -> Axis Aligned Bounding Box

	// Size of this collider
	float xSize = scale.x / 2;
	float ySize = scale.y / 2;
	float zSize = scale.z / 2;

	// Size of the other collider
	float xSizeOther = other.scale.x / 2;
	float ySizeOther = other.scale.y / 2;
	float zSizeOther = other.scale.z / 2;

	// If there is an overlap, the objects collide

	// Check whether the x axis of the collider is completely left/right of the other collider
	bool xCollision = position.x - xSize > other.position.x + xSizeOther ||
		position.x + xSize < other.position.x - xSizeOther;

	// Check whether the y axis of the collider is completely above/below of the other collider
	bool yCollision = position.y - ySize > other.position.y + ySizeOther ||
		position.y + ySize < other.position.y - ySizeOther;

	// Check whether the z axis of the collider is completely front/behind of the other collider
	bool zCollision = position.z - zSize > other.position.z + zSizeOther ||
		position.z + zSize < other.position.z - zSizeOther;

	// If the collider is somewhere completely left/right/up/below/in front/behind of the collider,
	// then we assume no collision is happening
	if (xCollision || yCollision || zCollision)
		return false;
	// Otherwise there is an overlap/intersection happening
	else
		return true;
}



