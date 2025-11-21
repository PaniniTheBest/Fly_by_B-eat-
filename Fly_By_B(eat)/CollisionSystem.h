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

struct GameObject1 {
    Vector3 position;
    Vector3 size;     


    float radius;
};


bool RaycastCollision(const GameObject1& obj, const Ray& ray, float maxDistance);


bool CoordinateOverlap(const GameObject1& a, const GameObject1& b);


bool SphereCollision(const GameObject1& a, const GameObject1& b);


bool PointInsideObject(const Vector3& point, const GameObject1& obj);

#endif
