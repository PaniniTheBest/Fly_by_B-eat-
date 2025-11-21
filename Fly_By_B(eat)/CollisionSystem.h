#pragma once
#ifndef COLLISION_SYSTEM_H
#define COLLISION_SYSTEM_H

#include <cmath>

struct Vector3 {
    float x, y, z;
};

struct Ray {
    Vector3 origin;
    Vector3 direction; 
};

struct GameObject {
    Vector3 position;
    Vector3 size;     


    float radius;
};


bool RaycastCollision(const GameObject& obj, const Ray& ray, float maxDistance);


bool CoordinateOverlap(const GameObject& a, const GameObject& b);


bool SphereCollision(const GameObject& a, const GameObject& b);


bool PointInsideObject(const Vector3& point, const GameObject& obj);

#endif
