#ifndef COLLISION_H
#define COLLISION_H

#include "vector3.h"

class Collider {
private:
	Vector3 position;
	Vector3 scale;
public:
	Collider();
	void SetDimension(Vector3 position, Vector3 scale);
	bool CheckCollision(Collider other);
};
#endif
