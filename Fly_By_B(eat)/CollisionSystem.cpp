#include "CollisionSystem.h"

static float Clamp(float v, float minVal, float maxVal) {
if (v < minVal) return minVal;
if (v > maxVal) return maxVal;
return v;
}

bool RaycastCollision(const GameObject1& obj, const Ray& ray, float maxDistance) {
    float tMin = 0.0f;
    float tMax = maxDistance;

    for (int i = 0; i < 3; ++i) {
        float origin = (&ray.origin.x)[i];
        float direction = (&ray.direction.x)[i];
        float minB = (&obj.position.x)[i] - (&obj.size.x)[i] * 0.5f;
        float maxB = (&obj.position.x)[i] + (&obj.size.x)[i] * 0.5f;

        if (fabs(direction) < 1e-6) {
            if (origin < minB || origin > maxB)
                return false;
        }
        else {
            float t1 = (minB - origin) / direction;
            float t2 = (maxB - origin) / direction;
            if (t1 > t2)
            {
                int i = t1;
                t2 = t1;
                t1 = i;
            };

            tMin = (t1 > tMin) ? t1 : tMin;
            tMax = (t2 < tMax) ? t2 : tMax;

            if (tMin > tMax)
                return false;
        }
    }

    return true;
}


bool CoordinateOverlap(const GameObject1& a, const GameObject1& b) {
    return (fabs(a.position.x - b.position.x) * 2 < (a.size.x + b.size.x)) &&
        (fabs(a.position.y - b.position.y) * 2 < (a.size.y + b.size.y)) &&
        (fabs(a.position.z - b.position.z) * 2 < (a.size.z + b.size.z));
}

bool SphereCollision(const GameObject1& a, const GameObject1& b) {
    float dx = a.position.x - b.position.x;
    float dy = a.position.y - b.position.y;
    float dz = a.position.z - b.position.z;
    float distanceSquared = dx * dx + dy * dy + dz * dz;
    float radiusSum = a.radius + b.radius;
    return distanceSquared <= (radiusSum * radiusSum);
}


bool PointInsideObject(const Vector3& point, const GameObject1& obj) {
    return (point.x >= obj.position.x - obj.size.x * 0.5f &&
        point.x <= obj.position.x + obj.size.x * 0.5f &&

        point.y >= obj.position.y - obj.size.y * 0.5f &&
        point.y <= obj.position.y + obj.size.y * 0.5f &&

        point.z >= obj.position.z - obj.size.z * 0.5f &&
        point.z <= obj.position.z + obj.size.z * 0.5f);
}
