#ifndef PHYSICS_H
#define PHYSICS_H
#include "vector3.h"
#include "engine.h"

#pragma once
class Physics
{
    private:
	    Vector3 velocity;
	    Vector3 addForce;
	    float mass;
        float gravity;
        bool booleanGravity = false;
	    //float drag;
    public:
        Physics();
        Physics(float m, float d, bool toggleGravity);

        void AddForce(float x, float y, float z);
        void AddForce(Vector3 newForce);
        void Update(float& positionX, float& positionY, float& positionZ);
        void Update(Vector3& position);
        void SetMass(float m);
        void SetDrag(float d);
        void SetVelocity(float x, float y, float z);
        void GetVelocity(float& x, float& y, float& z);
        void GetVelocity(Vector3& position);
        void SetUseGravity(bool enabled);
        bool ToggleGravity();
        void Reset();
};
#endif // !PHYSICS_H
